#include "top_input.h"

// flag (could be used by driver)
int flyback_flag;

top_input::top_input(FILE *p) : fp(p), bol(1), eof(0)
{
  push_back[0] = push_back[1] = push_back[2] = EOF;
  start_lineno = current_lineno;
}

int 
top_input::get(void)
{
  if (eof)
    return EOF;
  if (push_back[2] != EOF) 
    {
      int c = push_back[2];
      push_back[2] = EOF;
      return c;
    }
  else if (push_back[1] != EOF) 
    {
      int c = push_back[1];
      push_back[1] = EOF;
      return c;
    }
  else if (push_back[0] != EOF) 
    {
      int c = push_back[0];
      push_back[0] = EOF;
      return c;
    }
  int c = getc(fp);
  while (illegal_input_char(c)) 
    {
      error("illegal input character code %1", int(c));
      c = getc(fp);
      bol = 0;
    }
  if (bol && c == '.') 
    {
      c = getc(fp);
      if (c == 'P') 
	{
	  c = getc(fp);
	  if (c == 'F' || c == 'E') 
	    {
	      int d = getc(fp);
	      if (d != EOF)
		ungetc(d, fp);
	      if (d == EOF || d == ' ' || d == '\n' || compatible_flag) 
		{
		  eof = 1;
		  flyback_flag = (c == 'F');
		  return EOF;
		}
	      push_back[0] = c;
	      push_back[1] = 'P';
	      return '.';
	    }
	  if (c == 'S') 
	    {
	      c = getc(fp);
	      if (c != EOF)
		ungetc(c, fp);
	      if (c == EOF || c == ' ' || c == '\n' || compatible_flag) 
		{
		  error("nested .PS");
		  eof = 1;
		  return EOF;
		}
	      push_back[0] = 'S';
	      push_back[1] = 'P';
	      return '.';
	    }
	  if (c != EOF)
	    ungetc(c, fp);
	  push_back[0] = 'P';
	  return '.';
	}
      else 
	{
	  if (c != EOF)
	    ungetc(c, fp);
	  return '.';
	}
    }
  if (c == '\n') 
    {
      bol = 1;
      current_lineno++;
      return '\n';
    }
  bol = 0;
  if (c == EOF) 
    {
      eof = 1;
      error("end of file before .PE or .PF");
      error_with_file_and_line(current_filename, start_lineno - 1,
			       ".PS was here");
    }
  return c;
}

int 
top_input::peek(void)
{
  if (eof)
    return EOF;
  if (push_back[2] != EOF)
    return push_back[2];
  if (push_back[1] != EOF)
    return push_back[1];
  if (push_back[0] != EOF)
    return push_back[0];
  int c = getc(fp);
  while (illegal_input_char(c)) 
    {
      error("illegal input character code %1", int(c));
      c = getc(fp);
      bol = 0;
    }
  if (bol && c == '.') 
    {
      c = getc(fp);
      if (c == 'P') 
	{
	  c = getc(fp);
	  if (c == 'F' || c == 'E') 
	    {
	      int d = getc(fp);
	      if (d != EOF)
		ungetc(d, fp);
	      if (d == EOF || d == ' ' || d == '\n' || compatible_flag) 
		{
		  eof = 1;
		  flyback_flag = (c == 'F');
		  return EOF;
		}
	      push_back[0] = c;
	      push_back[1] = 'P';
	      push_back[2] = '.';
	      return '.';
	    }
	  if (c == 'S') 
	    {
	      c = getc(fp);
	      if (c != EOF)
		ungetc(c, fp);
	      if (c == EOF || c == ' ' || c == '\n' || compatible_flag) 
		{
		  error("nested .PS");
		  eof = 1;
		  return EOF;
		}
	      push_back[0] = 'S';
	      push_back[1] = 'P';
	      push_back[2] = '.';
	      return '.';
	    }
	  if (c != EOF)
	    ungetc(c, fp);
	  push_back[0] = 'P';
	  push_back[1] = '.';
	  return '.';
	}
      else 
	{
	  if (c != EOF)
	    ungetc(c, fp);
	  push_back[0] = '.';
	  return '.';
	}
    }
  if (c != EOF)
    ungetc(c, fp);
  if (c == '\n')
    return '\n';
  return c;
}

int 
top_input::get_location(const char **filenamep, int *linenop)
{
  *filenamep = current_filename;
  *linenop = current_lineno;
  return 1;
}


