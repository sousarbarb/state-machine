#ifndef SRC_STATE_H
#define SRC_STATE_H

#include <ros/ros.h>

#include "robot_calibration/state_machine.h"

namespace robot_calibration {

class State {
 public:
  virtual void Execute(StateMachine* _state_machine) = 0;
};

class StateStandBy : public State {
 public:
  void Execute(StateMachine* _state_machine) override;
};

class StateAcquireDate : public State {
 public:
  void Execute(StateMachine* _state_machine) override;
};

class StateCalibrationOptimization : public State {
 public:
  void Execute(StateMachine* _state_machine) override;
};

}  // namespace robot_calibration

#endif //SRC_STATE_H
