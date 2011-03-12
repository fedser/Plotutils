// -*- C++ -*-
// Declaration of the position class, defined in pic2plot source.

#ifndef _POSITION_H_
#define _POSITION_H_ 1

struct place;

class position {
public:
  double x;
  double y;
  position(double, double );
  position();
  position(const place &);
  position &operator+=(const position &);
  position &operator-=(const position &);
  position &operator*=(double);
  position &operator/=(double);
};

position operator-(const position &);
position operator+(const position &, const position &);
position operator-(const position &, const position &);
position operator/(const position &, double);
position operator*(const position &, double);
// dot product
double operator*(const position &, const position &);
int operator==(const position &, const position &);
int operator!=(const position &, const position &);

double hypot(const position &a);

typedef position distance;

#endif /* not _POSITION_H_ */
