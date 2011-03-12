// -*- C++ -*-
// The text-piece class, used by pic2plot.

#ifndef _TEXT_H_
#define _TEXT_H_

enum hadjustment 
{
  CENTER_ADJUST,
  LEFT_ADJUST,
  RIGHT_ADJUST
};

enum vadjustment 
{
  NONE_ADJUST,
  ABOVE_ADJUST,
  BELOW_ADJUST
};

struct adjustment 
{
  hadjustment h;
  vadjustment v;
};

class text_piece 
{
public:
  // ctor, dtor
  text_piece();
  ~text_piece();
  // public data
  char *text;
  adjustment adj;
  const char *filename;
  int lineno;
};

#endif /* _TEXT_H_ */
