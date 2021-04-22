#ifndef SRC_STATE_MACHINE_H
#define SRC_STATE_MACHINE_H

#include <iostream>

#include "robot_calibration/state.h"

namespace robot_calibration {

class StateMachine{
 private:
  State* state_;
  trigger_acquisition_ = false;
  trigger_calibration_ = false;

 public:
  StateMachine();
  ~StateMachine();
  void SetState(State* _new_state);
  void Execute(StateMachine* _state_machine);
  void TriggerDataAcquisition(bool _trigger_acquisition);
  void TriggerCalibrationOptimization(bool _trigger_calibration);
  bool GetTriggerDataAcquisition();
  bool GetTriggerCalibrationOptimization();
};

}  // namespace robot_calibration

#endif //SRC_STATE_MACHINE_H
