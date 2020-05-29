#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFM = motor(PORT2, ratio18_1, false); //left front motor
motor RFM = motor(PORT9, ratio18_1, true); //right front motor

inertial Gyro = inertial(PORT1);
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