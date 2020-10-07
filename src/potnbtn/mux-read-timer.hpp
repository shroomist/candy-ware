#ifndef __MUX_READ_TIMER_H_
#define __MUX_READ_TIMER_H_

#include "../sch/header.hpp"

class MuxReadTimer {
  public:
    int cumSum = 0; // cumulative sum
    int readTarget = 0;
    MuxReadTimer(int b) ;
    Task tSetReadReady;
    Task tSetMuxReadTarget;
    int nextReadTarget (int curr);
    void enable ();
};


#endif // __MUX_READ_TIMER_H_
