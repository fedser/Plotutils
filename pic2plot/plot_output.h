/* This file is part of a derivative work of the GNU plotutils
   package. This file Copyright (C) 2011 Tim Martin
   tim@asymptotic.co.uk

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


#ifndef _PLOT_OUTPUT_H_
#define _PLOT_OUTPUT_H_

#include "common.h"
#include "plot.h"

// our libplot driver

class plot_output : public common_output
{
public:
  // ctor, dtor
  plot_output();
  ~plot_output();
  // basic interface
  void start_picture (double sc, const position &ll, const position &ur);
  void finish_picture (void);
  // draw objects
  void arc (const position &start, const position &cent, const position &end,
	    const line_type &lt);
  void circle (const position &cent, double rad, const line_type &lt, 
	       double fill);
  void ellipse (const position &cent, const distance &dim,
		const line_type &lt, double fill);
  void line (const position &start, const position *v, int n,
	     const line_type &lt);
  void polygon (const position *v, int n,
		const line_type &lt, double fill);
  void spline (const position &start, const position *v, int n,
	       const line_type &lt);
  void text (const position &center, text_piece *v, int n, double angle);
  void rounded_box (const position &cent, const distance &dim,
		    double rad, const line_type &lt, double fill);
  // attribute-querying function
  int supports_filled_polygons (void);
private:
  // parameters
  plPlotter *plotter;		// pointer to opaque libplot Plotter object
  double default_plotter_line_thickness; // line thickness in virtual points
  int pen_red, pen_green, pen_blue;	 // 48-bit pen color
  // dynamic variables, keep track of Plotter drawing state
  int plotter_line_type; // one of line_type::solid etc.
  int plotter_fill_fraction; // libplot fill fraction
  double plotter_line_thickness; // in virtual points
  bool plotter_visible_pen;	// default is `yes'
  bool plotter_path_in_progress; // need to break?
  // internal functions, modify Plotter drawing state
  void set_line_type_and_thickness (const line_type &lt);
  void set_fill (double fill);
  void set_pen_visibility (bool visible);
  // invoked by common_output dotting methods
  void dot (const position &pos, const line_type &lt);
};


#endif /* not _PLOT_OUTPUT_H_ */
