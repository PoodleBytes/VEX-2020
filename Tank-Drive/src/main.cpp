#include "vex.h"
#include "user-prog.h"   //motor set-up, user variables/functions

using namespace vex;

competition Competition;


void autonomous(void) {
  wait(200,msec);
  Drive.turnFor(right, 90, rotationUnits::deg);
  wait(200,msec);
  Drive.driveFor(fwd, 20,distanceUnits::in,1);

}//end auton

void usercontrol(void) {
  
  //start user-control tasks
  vex::task t(tUserCtl); // start task of arm, lift, claw etc...
  t.setPriority(6);

  while(1){

    //Drive
    //set drive sensitivity - fancy if-else: (test condition) ? (if true) : (if false)
    (abs(Controller1.Axis2.position()) < driveThreshold && abs(Controller1.Axis4.position()) < driveThreshold) ? adjSpeed = slowSpeed  :  adjSpeed = 1.0;
    
    //X-Drive Control
    LFM.spin(directionType::fwd,Controller1.Axis2.position() * adjSpeed, velocityUnits::pct);
    RFM.spin(directionType::fwd,Controller1.Axis4.position() * adjSpeed, velocityUnits::pct);

  }//end user control
  
}

//set-up robot 
void pre_auton(void) {

  //set-up motors
  setUpMotor(LFM,'B');
  setUpMotor(RFM,'B');

  //start misc tasks 
  vex::task t(tAuton); // start task needed for autonomous
  t.setPriority(6);

  //calibrate gyro
  wait(200, msec);
  Gyro.calibrate();
  while (Gyro.isCalibrating()) {
    wait(25, msec);
  } 

  vexcodeInit(); 
}//end robot set-up pre_auton()


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
    
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(500, msec);
  }
}
