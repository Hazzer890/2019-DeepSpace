#include "Robot5663.h"
#include <math.h>

using hand = frc::XboxController::JoystickHand; // Type alias for hand

void Robot::RobotInit() {
  // Sparks
  left_motor = new frc::Spark(0);
  right_motor = new frc::Spark(1);
  Cargo = new frc::Spark(2);

  // pistons
  Hatch_deploy = new frc::DoubleSolenoid(0, 1);

  xbox1 = new frc::XboxController(0);
  xbox2 = new frc::XboxController(1);
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  // Tank drive and intake
  double left_speed = -xbox1->GetY(hand::kLeftHand);
  double right_speed = xbox1->GetY(hand::kRightHand);
  //double intake_speed = xbox->GetTriggerAxis(hand::kLeftHand);

  left_speed *= std::abs(left_speed);
  right_speed *= std::abs(right_speed);
  //intake_speed *= std::abs(intake_speed);

  left_motor->Set(left_speed);
  right_motor->Set(right_speed);

  //Cargo
  if(xbox2->GetTriggerAxis(hand::kLeftHand) != 0.0) {
    Cargo->Set(-xbox2->GetTriggerAxis(hand::kLeftHand));
  } else {
    Cargo->Set(xbox2->GetTriggerAxis(hand::kRightHand));
  }
  
  //Hatch
  if(xbox2->GetAButton() == 1){
    Hatch_deploy->frc::DoubleSolenoid::Set  (frc::DoubleSolenoid::kForward);
  } else  { 
    Hatch_deploy->frc::DoubleSolenoid::Set  (frc::DoubleSolenoid::kReverse);
  }


  }

void Robot::TestInit() {}
void Robot::TestPeriodic() {}
