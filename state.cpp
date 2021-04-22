#include "robot_calibration/state.h"

namespace robot_calibration {

void StateStandBy::Execute(StateMachine *_state_machine) {

  // Transition: STAND_BY >>> ACQUIRE_DATA
  if (_state_machine->GetTriggerDataAcquisition()) {
    _state_machine->SetState(new StateAcquireDate());
    ROS_DEBUG("State Machine: STAND_BY >>> ACQUIRE_DATA");
  }
}

void StateAcquireDate::Execute(StateMachine *_state_machine) {

  // Transition: ACQUIRE_DATA >>> CALIBRATION_OPTIMIZATION
  if (_state_machine->GetTriggerCalibrationOptimization()) {
    _state_machine->SetState(new StateCalibrationOptimization());
    ROS_DEBUG("State Machine: ACQUIRE_DATA >>> CALIBRATION_OPTIMIZATION");
  }
}

void StateCalibrationOptimization::Execute(StateMachine *_state_machine) {

  // Transition: CALIBRATION_OPTIMIZATION >>> STAND_BY
  _state_machine->SetState(new StateStandBy());
  ROS_DEBUG("State Machine: CALIBRATION_OPTIMIZATION >>> STAND_BY");
}

}  // namespace robot_calibration
