#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFM = motor(PORT1, ratio18_1, false);   //left front motor -  !rotation fwd turns robot right
motor LBM = motor(PORT11, ratio18_1, false);   //right back motor -  !rotation fwd turns robot right
motor RFM = motor(PORT10, ratio18_1, false);   //right front motor -  !rotation fwd turns robot right
motor RBM = motor(PORT20, ratio18_1, false);   //left back motor -  !rotation fwd turns robot right

motor_group leftSide(LFM, LBM);

inertial Gyro = inertial(PORT15);
smartdrive Drive = smartdrive(LFM, RFM, Gyro, 300, 400, 279.4, mm, 1);  //motor1 motor2, robot track(width), robot wheel base, wheel dia, in mm, true

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true; 

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}