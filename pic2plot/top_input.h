/* This file is a derivative work of the GNU plotutils package.
   Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2005, 2008, 2009,
   Free Software Foundation, Inc.

   This file incorporates modifications by Tim Martin
   (tim@asymptotic.co.uk) 2011
   
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


#ifndef _TOP_INPUT_H_
#define _TOP_INPUT_H_

#include "pic.h"

//////////////////////////////////////////////////////////////////////
// TOP_INPUT class.
//////////////////////////////////////////////////////////////////////

class top_input : public input 
{
public:
  // ctor
  top_input (FILE *);
  // public functions
  int get (void);
  int peek (void);
  int get_location (const char **filenamep, int *linenop);
private:
  FILE *fp;
  int bol;
  int eof;
  int push_back[3];
  int start_lineno;
};

#endif /* not _TOP_INPUT_H_ */
