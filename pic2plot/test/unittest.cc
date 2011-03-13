#include <UnitTest++.h>

#include "plot_output.h"
#include "file_handling.h"

// Global variables that are present in main.cc, which have to be
// duplicated here for linkage. Probably these should be removed
// entirely if at all possible.
plPlotterParams *plotter_params;
int precision_dashing = 0;

const char *progname = "unittest"; // name of this program
const char *written = "Written by Tim Martin, incorporating code from GNU PlotUtils";
const char *copyright = "Copyright (C) 2011 Tim Martin";

const char *usage_appendage = " FILE...\n";

output *out;			// declared in output.h

char *output_format = (char *)"meta"; // libplot output format
char *font_name = NULL;	// initial font name (if set)
char *pen_color_name = NULL; // initial pen color (if set)
double font_size = 10.0/(8.0*72.); // font size as width of graphics display
double line_width = -0.5/(8.0*72.); // line width as width of graphics display,
				// negative means use libplot default

// flags (used by lexer)
int command_char = '.';		// char that introduces pass-thru lines
int compatible_flag = 0;	// recog. PS/PE even if not foll. by ' ', '\n'?

// flags (used by parser)
int safer_flag = 0; 		// forbid shell escapes?

// flag (could be used by driver)
int no_centering_flag = 0;	// turn off auto-centering?

// static variables
int lf_flag = 1;		// non-zero -> try to parse `.lf' lines

int had_parse_error = 0;


TEST(plot_output)
{
	plotter_params = pl_newplparams();
	plot_output output;

	CHECK_EQUAL(true, output.supports_filled_polygons());
}

TEST(do_file)
{
	out = make_plot_output();
	do_file("test/basic.pic");
}

int main(int argc, char ** argv)
{
	return UnitTest::RunAllTests();
}
