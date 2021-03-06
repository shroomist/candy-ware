#ifndef __MUX_READ_TIMER_H_
#define __MUX_READ_TIMER_H_

#include "Arduino.h"
#include "../sch/header.hpp"
#include "set-pot-btn.hpp"

struct read_target {
  bool isPot;
  byte target;
};

class MuxReadTimer {
  public:
    MuxReadTimer(set_param setParam, set_btn setBtn) ;
    Task tSetReadReady;
    Task tSetMuxReadTarget;
    void nextReadTarget ();
    void enable ();
    read_target readTarget;
};


#endif // __MUX_READ_TIMER_H_
