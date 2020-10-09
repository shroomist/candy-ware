#include "ctrl.hpp"
#include "debug.h"

CtrlLog::CtrlLog (String id) {
  set_param potH = [id] (int target, int value) {
    _PP(id);
    _PP(" value for: ");
    _PP(target);
    _PP(" = ");
    _PL(value);
  };
  set_btn btnH = [id] (int target, bool value) {
    _PP(id);
    _PP(" value for: ");
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

  set_param potH = [this] (int target, int value) {
    _PP(" CTRLPOT value for: ");
    _PP(target);
    _PP(" = ");
    _PL(value);
    allCtrls.displ.c->getHandles().param(target, value);
    if (activeId == Synth) {
      allCtrls.synth.c->getHandles().param(target, value);
    } else {
      allCtrls.log.c->getHandles().param(target, value);
    }
  };
  set_btn btnH = [this] (int target, bool value) {
    _PP("CTRLBTN value for: ");
    _PP(target);
    _PP(" = ");

    _PL(value);
    allCtrls.displ.c->getHandles().btn(target, value);
    if (value == 1) {
      switchHandle(Synth);
    } else {
      switchHandle(Log);
    }
  };

  return (param_btn_handles{potH, btnH});
}


void CtrlSwitch::switchHandle (ctrl_id switchToId) {
  activeId = switchToId;
  switch (switchToId) {
    case Log :
      activeCtrl = &allCtrls.log;
      break;
    case Synth :
      activeCtrl = &allCtrls.synth;
  }
}
