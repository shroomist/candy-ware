#ifndef __MUX_READ_TIMER_H_
#define __MUX_READ_TIMER_H_

#include "Arduino.h"
#include "../sch/header.hpp"

using set_param = std::function<void (int, int)>;
using set_btn = std::function<void (int, bool)>;

struct read_target {
  bool isPot;
  byte target;
};

class MuxReadTimer {
  public:
    int cumSum = 0; // cumulative sum
    // int readTarget = 0;
    MuxReadTimer(int b, set_param setParam, set_btn setBtn) ;
    Task tSetReadReady;
    Task tSetMuxReadTarget;
    void nextReadTarget ();
    void enable ();
    read_target readTarget;
};


#endif // __MUX_READ_TIMER_H_
