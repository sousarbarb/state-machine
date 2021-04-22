#include "robot_calibration/state_machine.h"

namespace robot_calibration {

StateMachine::StateMachine() {
  state_ = static_cast<State*>(new StateStandBy());
}

StateMachine::~StateMachine() = default;

void StateMachine::SetState(State *_new_state) {
  State* aux = _new_state;
  state_ = _new_state;
  delete aux;
}

void StateMachine::Execute(StateMachine* _state_machine) {
  state_->Execute(_state_machine);
}

void StateMachine::TriggerDataAcquisition(bool _trigger_acquisition) {
  trigger_acquisition_ = _trigger_acquisition;
}

void StateMachine::TriggerCalibrationOptimization(bool _trigger_calibration) {
  trigger_calibration_ = _trigger_calibration;
}

bool StateMachine::GetTriggerDataAcquisition() {
  return trigger_acquisition_;
}

bool StateMachine::GetTriggerCalibrationOptimization() {
  return trigger_calibration_;
}

}  // namespace robot_calibration
