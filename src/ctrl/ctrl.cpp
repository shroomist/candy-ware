#include "ctrl.hpp"
#include "debug.h"

CtrlLog::CtrlLog () {
  set_param potH = [] (int target, int value) {
    _PP("CTRLPOT value for: ");
    _PP(target);
    _PP(" = ");
    _PL(value);
  };
  set_btn btnH = [] (int target, bool value) {
    _PP("CTRLBTN value for: ");
    _PP(target);
    _PP(" = ");
    _PL(value);
  };

  hs = {potH, btnH};

};

param_btn_handles CtrlLog::getHandles () {
  return hs;
};

CtrlSwitch::CtrlSwitch(all_ctrls allCtls): allCtrls{allCtls} {};
