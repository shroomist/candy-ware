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
SynthC = 1,
DisplayC = 2,
};

struct ctrl {
  ctrl_id id;
  Ctrl* c;
};

struct all_ctrls {
  ctrl log;
  ctrl synth;
  ctrl displ;
};

class CtrlSwitch {
  public:
    CtrlSwitch(all_ctrls allCtrls);
    // ~CtrlSwitch ();
    param_btn_handles getHandles();
    void switchHandle (ctrl_id switchToId);
  private:
    ctrl* activeCtrl;
    all_ctrls allCtrls;
    ctrl_id activeId;

};

class CtrlLog : public Ctrl {
  public:
    CtrlLog(String id);
    param_btn_handles getHandles();
  private:
    param_btn_handles hs;
};
#endif // __CTRL_H_
