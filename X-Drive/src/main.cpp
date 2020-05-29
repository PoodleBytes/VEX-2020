#include "vex.h"
#include "user-prog.h"   //motor set-up, user variables/functions

using namespace vex;

competition Competition;

void autonomous(void) {
  xDrive(360,50,'F',1);
  xTurn(-90,40,1);

}//end auton

void usercontrol(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //start user-control tasks
  vex::task t(tUserCtl); // start contorl of aux systems
  t.setPriority(6);

  while(1){

    //set drive sensitivity - fancy if-else: (test condition) ? (if true) : (if false)
    (abs(Controller1.Axis1.position() + Controller1.Axis2.position() + Controller1.Axis4.position()) < driveThreshold && abs(Controller1.Axis1.position() - Controller1.Axis2.position() + Controller1.Axis4.position()) < driveThreshold) ? adjSpeed = slowSpeed  :  adjSpeed = 1.0;
    
    //X-Drive Control
    LFM.spin(directionType::fwd,(Controller1.Axis2.position() + Controller1.Axis1.position() + Controller1.Axis4.position()) * adjSpeed, velocityUnits::pct);
    LBM.spin(directionType::fwd,(Controller1.Axis2.position() - Controller1.Axis1.position() + Controller1.Axis4.position()) * adjSpeed, velocityUnits::pct);
    RFM.spin(directionType::fwd,( -(Controller1.Axis2.position()) + Controller1.Axis1.position() + Controller1.Axis4.position()) * adjSpeed, velocityUnits::pct);
    RBM.spin(directionType::fwd,( -(Controller1.Axis2.position()) - Controller1.Axis1.position() + Controller1.Axis4.position()) * adjSpeed, velocityUnits::pct);



    vex::this_thread::sleep_for(100);
  }//end user control
  
}

//set-up robot 
void pre_auton(void) {

  //set-up motors (B = Brake  H = Hold, C = Coast)
  setUpMotor(LFM,'B');
  setUpMotor(LBM,'B');
  setUpMotor(RFM,'B');
  setUpMotor(RBM,'B');

  //start misc tasks 
  vex::task t(tAuton); // start task which updates controller screen
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
