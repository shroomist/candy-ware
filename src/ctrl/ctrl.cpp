#include "ctrl.hpp"
#include "debug.h"

CtrlLog::CtrlLog (byte id) {
  set_param potH = [id] (int target, int value) {
    _PP(id);
    _PP(" CTRLPOT value for: ");
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

CtrlSwitch::CtrlSwitch(all_ctrls allCtls): allCtrls{allCtls} {
  activeCtrl = &allCtls.log;
};

param_btn_handles CtrlSwitch::getHandles () {
  return activeCtrl->c->getHandles();
}

void CtrlSwitch::switchHandle (ctrl_id switchToId) {
  switch (switchToId) {
    case Log :
      activeCtrl = &allCtrls.log;
      break;
    case Synth :
      activeCtrl = &allCtrls.synth;
  }
}
