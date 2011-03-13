/* This file is part of a derivative work of the GNU plotutils
   package.  Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2005,
   2008, 2009, Free Software Foundation, Inc.

   The GNU plotutils package is free software.  You may redistribute it
   and/or modify it under the terms of the GNU General Public License as
   published by the Free Software foundation; either version 2, or (at your
   option) any later version.

   The GNU plotutils package is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with the GNU plotutils package; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin St., Fifth Floor,
   Boston, MA 02110-1301, USA. */


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>

#include "error.h"
#include "common.h"
#include "stringclass.h"
#include "lib.h"
#include "pic.h"
#include "top_input.h"
#include "file_handling.h"

extern output *out; // defined in main.cc
extern int lf_flag;
extern int compatible_flag;

extern int flyback_flag;

void do_picture(FILE *fp);

/**
 * Preconditions: Global variable out must be set to a valid output
 * object 
 */
void 
do_file (const char *filename)
{
  FILE *fp;
  if (strcmp(filename, "-") == 0)
    fp = stdin;
  else 
    {
      errno = 0;
      fp = fopen(filename, "r");
      if (fp == 0)
	fatal ("can't open `%1': %2", filename, strerror(errno));
    }
  out->set_location (filename, 1);
  current_filename = filename;
  current_lineno = 1;
  enum { START, MIDDLE, HAD_DOT, HAD_P, HAD_PS, HAD_l, HAD_lf } state = START;
  for (;;) 
    {
      int c = getc(fp);
      if (c == EOF)		// break out of for loop on EOF, only
	break;
      switch (state) 
	{
	case START:
	  if (c == '.')
	    state = HAD_DOT;
	  else 
	    {
	      if (c == '\n') 
		{
		  current_lineno++;
		  state = START;
		}
	      else		// dnl
		state = MIDDLE;
	    }
	  break;
	case MIDDLE:
	  // discard chars until newline seen; switch back to START
	  if (c == '\n') 
	    {
	      current_lineno++;
	      state = START;
	    }
	  break;
	case HAD_DOT:
	  if (c == 'P')
	    state = HAD_P;
	  else if (lf_flag && c == 'l')
	    state = HAD_l;
	  else 
	    {
	      if (c == '\n') 
		{
		  current_lineno++;
		  state = START;
		}
	      else		// dnl
		state = MIDDLE;
	    }
	  break;
	case HAD_P:
	  if (c == 'S')
	    state = HAD_PS;
	  else  
	    {
	      if (c == '\n') 
		{
		  current_lineno++;
		  state = START;
		}
	      else		// dnl
		state = MIDDLE;
	    }
	  break;
	case HAD_PS:
	  if (c == ' ' || c == '\n' || compatible_flag) 
	    {
	      ungetc(c, fp);
	      do_picture(fp);	// do the picture, incl. args of .PS if any
	      state = START;
	    }
	  else			// dnl
	    state = MIDDLE;
	  break;
	case HAD_l:
	  if (c == 'f')
	    state = HAD_lf;
	  else 
	    {
	      if (c == '\n') 
		{
		  current_lineno++;
		  state = START;
		}
	      else		// dnl
		state = MIDDLE;
	    }
	  break;
	case HAD_lf:
	  if (c == ' ' || c == '\n' || compatible_flag) 
	    {
	      string line;

	      while (c != EOF) 
		{
		  line += c;
		  if (c == '\n') 
		    {
		      current_lineno++;
		      break;
		    }
		  c = getc(fp);
		}
	      line += '\0';
	      interpret_lf_args(line.contents());
	      state = START;
	    }
	  else			// dnl
	    state = MIDDLE;
	  break;
	default:
	  assert(0);
	}
    }

  // exit gracefully when EOF seen
  if (fp != stdin)
    fclose(fp);
}

void 
do_picture(FILE *fp)
{
  flyback_flag = 0;
  int c;
  while ((c = getc(fp)) == ' ')
    ;
  if (c == '<') 
    /* first nonblank character after .PS is '<' */
    {
      string filename;
      while ((c = getc(fp)) == ' ')
	;
      while (c != EOF && c != ' ' && c != '\n') 
	{
	  filename += char(c);
	  c = getc(fp);
	}
      if (c == ' ') 
	{
	  do 
	    {
	      c = getc(fp);
	    } while (c != EOF && c != '\n');
	}
      if (c == '\n') 
	current_lineno++;
      if (filename.length() == 0)
	error("missing filename after `<'");
      else 
	{
	  filename += '\0';
	  const char *old_filename = current_filename;
	  int old_lineno = current_lineno;
	  // filenames must be permanent
	  do_file (strsave(filename.contents())); // recursive call
	  current_filename = old_filename;
	  current_lineno = old_lineno;
	}
      out->set_location (current_filename, current_lineno);
    }
  else 
    /* first nonblank character after .PS is not '<' */
    {
      out->set_location (current_filename, current_lineno);

      /* get the starting line */
      string start_line;
      while (c != EOF) 
	{
	  if (c == '\n') 
	    {
	      current_lineno++;
	      break;
	    }
	  start_line += c;
	  c = getc(fp);
	}
      if (c == EOF)
	return;
      start_line += '\0';

      /* parse starting line for height and width */
      double wid, ht;
      switch (sscanf(&start_line[0], "%lf %lf", &wid, &ht)) 
	{
	case 1:
	  ht = 0.0;
	  break;
	case 2:
	  break;
	default:
	  ht = wid = 0.0;
	  break;
	}
      out->set_desired_width_height (wid, ht);
      out->set_args (start_line.contents());

      // do the parse
      lex_init (new top_input(fp));
      if (yyparse()) 
	{
	  had_parse_error = 1;
	  lex_error ("giving up on this picture");
	}
      parse_cleanup();
      lex_cleanup();

      // skip the rest of the .PF/.PE line
      while ((c = getc(fp)) != EOF && c != '\n')
	;
      if (c == '\n')
	current_lineno++;
      out->set_location (current_filename, current_lineno);
    }
}
