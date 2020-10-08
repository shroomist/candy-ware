#ifndef __CTRL_H_
#define __CTRL_H_

#include <Arduino.h>
#include "../potnbtn/set-pot-btn.hpp"

struct param_btn_handles {
  set_param param;
  set_btn btn;
};

class Ctrl {
  public:
    // virtual ~Ctrl ();
    virtual param_btn_handles getHandles();
};

enum ctrl_id {
Log = 0,
Synth = 1,
};

struct ctrl {
  ctrl_id id;
  Ctrl* c;
};

struct all_ctrls {
  ctrl log;
  // ctrl synth;
};

class CtrlSwitch {
  public:
    CtrlSwitch(all_ctrls allCtrls);
    // ~CtrlSwitch ();
  private:
    all_ctrls allCtrls;

};

class CtrlLog : public Ctrl {
  public:
    CtrlLog();
    param_btn_handles getHandles();
  private:
    param_btn_handles hs;
};
#endif // __CTRL_H_
