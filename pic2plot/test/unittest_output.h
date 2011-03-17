#ifndef _UNITTEST_OUTPUT_H_
#define _UNITTEST_OUTPUT_H_ 1

#include <iostream>

#include "output.h"

class unittest_output : public output
{
 public:
	unittest_output(std::ostream & stream);

	virtual void start_picture (double sc, const position &ll, const position &ur);
	virtual void finish_picture ();
	virtual void arc (const position &start, const position &cent, 
					  const position &end, const line_type &lt);
	virtual void circle (const position &cent, double rad,
						 const line_type &lt, double fill);
	virtual void ellipse (const position &cent, const distance &dim,
						  const line_type &lt, double fill);
	virtual void line (const position &start, const position *v, int n,
					   const line_type &lt);
	virtual void polygon (const position *v, int n,
						  const line_type &lt, double fill);
	virtual void spline (const position &start, const position *v, int n,
						 const line_type &lt);
	virtual void text (const position &center, text_piece *v, int n,
					   double angle);
	virtual void rounded_box (const position &cent, const distance &dim,
							  double rad, const line_type &lt, double fill);

 private:
	std::ostream & stream;
};

#endif /* not _UNITTEST_OUTPUT_H_ */
