#include "vex.h"

using namespace vex;

/*====  START USER VARIABLES / FUNCTIONS / TASKS ======*/
//  USER VARIABLES
//drive() sensitivity
double adjSpeed = 1.0;    //controller drive sensitivity
double slowSpeed = 0.3;    //controller drive sensitivity - sensitive mode
int driveThreshold = 50;  //joystick sensitivity rip point - slowSpeed to highSpeed 

//  USER FUNCTIONS
//motor set-up 
void setUpMotor(motor(M), char B) {
  M.setMaxTorque(95, percentUnits::pct); // set torque
  M.setTimeout(3, timeUnits::sec);       // set motor timeout
  M.resetRotation();                     // reset encoders
  if (B == 'C') {
    M.setStopping(brakeType::coast); // coast
  } else if (B == 'H') {
    M.setStopping(brakeType::hold); // braking
  } else if (B == 'B') {
    M.setStopping(brakeType::brake); // braking
  } else {
    M.setStopping(brakeType::coast); // braking
  }
}//end motor setup



int tUserCtl(void){
  while(1){
    //high priority - sensors

    //low priority - display, temp log
    vex::this_thread::sleep_for(100);
  }
  return(0);
}

//misc - sensors, display
int tAuton(void){
  while(1){
    //high priority - sensors

    //low priority - display, temp log
   
    
  vex::this_thread::sleep_for(100);
  }
  return(0);
}




/*====  END  USER VARIABLES / FUNCTIONS  ======*/