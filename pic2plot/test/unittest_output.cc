#include "unittest_output.h"

#include "position.h"

using std::endl;

unittest_output::unittest_output(std::ostream & stream_) : stream(stream_)
{
}

void unittest_output::start_picture(double sc, const position &ll, const position &ur)
{
	stream << "start_picture()" << endl;
}

void unittest_output::finish_picture()
{
	stream << "finish_picture()" << endl;
}

void unittest_output::arc(const position &start, const position &cent,
						  const position &end, const line_type &lt)
{
	stream << "arc()" << endl;
}

void unittest_output::circle(const position &cent, double rad,
							 const line_type &lt, double fill)
{
	stream << "circle()" << endl;
}

void unittest_output::ellipse(const position &cent, const distance &dim,
							  const line_type &lt, double fill)
{
	stream << "ellipse()" << endl;
}

void unittest_output::line(const position &start, const position *v, int n,
						   const line_type &lt)
{
	stream << "line()" << endl;
}

void unittest_output::polygon(const position *v, int n,
							  const line_type &lt, double fill)
{
	stream << "polygon()" << endl;
}

void unittest_output::spline(const position &start, const position *v,
							 int n, const line_type &lt)
{
	stream << "spline()" << endl;
}

void unittest_output::text(const position &center, text_piece *v, int n,
						   double angle)
{
	stream << "text()" << endl;
}

void unittest_output::rounded_box(const position &cent, const distance &dim,
								  double rad, const line_type &lt,
								  double fill)
{
	stream << "rounded_box()" << endl;
}
