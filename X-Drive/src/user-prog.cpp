#include "vex.h"

using namespace vex;

/*====  START USER VARIABLES / FUNCTIONS / TASKS ======*/
//  USER VARIABLES
//drive()
double slowSpeed = 0.3;    //controller drive sensitivity - sensitive mode
double adjSpeed = 1.0;    //controller drive sensitivity
int driveThreshold = 50; //controller threshold for slowSpeed 7 highSpeed changes

//  USER FUNCTIONS

void xDrive(double degRotate, double motorSpeed, char dir, bool b){

  /* SIMPLE 
  thoughts on making this work
    inpit distance, speed, direction - run motors accordingly

  assumes motor polarity set so all motors turning forward rotates right
                LFM   LRM   RFM   RBM
    forward     +      +     -     -
    reverse     -      -     +     +
    left        -      +     -     +
    right       +      -     +     -
  */
    int motorDir[4][4] = {
      {1, 1, -1, -1},	//forward 
      {-1, -1, 1, 1},	//reverse  
      {-1, 1, -1, 1},	//strafe left 
      {1, -1, 1, -1},	//strafe right
    };
    
    int rowIndex;
    
    //determine direction
    switch(dir) {
      case 'F' :    //forward
         rowIndex = 0;  
         break;
      case 'B' :    //backward
         rowIndex = 1;
         break;
      case 'L' :    //left
         rowIndex = 2;
         break;
      case 'R' :    //right
         rowIndex = 3;
         break;
      default :   //do nothing!!
         rowIndex = -1;
         break;
     }

    LFM.rotateFor(degRotate * motorDir[rowIndex][0], vex::rotationUnits::deg, motorSpeed, vex::velocityUnits::pct, 0);
    LBM.rotateFor(degRotate * motorDir[rowIndex][1], vex::rotationUnits::deg, motorSpeed, vex::velocityUnits::pct, 0);
    RFM.rotateFor(degRotate * motorDir[rowIndex][2], vex::rotationUnits::deg, motorSpeed, vex::velocityUnits::pct, 0);
    RBM.rotateFor(degRotate * motorDir[rowIndex][3], vex::rotationUnits::deg, motorSpeed, vex::velocityUnits::pct, b);

    if (b) { // b = tue means wait for motors stop spinning or timeout
      while (LFM.isSpinning()) {}    //TODO - look into using Gryo to detect movemet
    }
    wait(0.2, seconds);   //let robot settle
  
}//xDrive

//tractin cobtrol - compare gyro speed to calc on wheel - slow or stutter wheel if true stuck b

void xTurn(double deg, double motorSpeed, bool b){

  Gyro.resetRotation(); //zero gyro angle
  
  //what direction to spin motors
  directionType dir;  
  (deg > 0 ? dir = fwd : dir = reverse);

  do{
    LFM.spin(dir, motorSpeed , vex::velocityUnits::pct);
    LBM.spin(dir, motorSpeed, vex::velocityUnits::pct);
    RFM.spin(dir, motorSpeed , vex::velocityUnits::pct);
    RBM.spin(dir, motorSpeed, vex::velocityUnits::pct);
  }while(Gyro.rotation() < deg);
  
  if (b) { // b = tue means wait for motors stop spinning or timeout
      while (LFM.isSpinning()){}     //TODO - look into using Gryo to detect movemet
    }
  wait(0.2, seconds);   //let robot settle
  
}//xTurn

//EXPERIMENTAL MOTOR ACCELLERATE/DECELLERATE
void rampMotor(double speed, double degrees){
  double rampRange = degrees * 0.10; //amt of rotation to slowly start and end
  double rampSpeed = 20;

  



}//rampMotor

//motor set-up 

void setUpMotor(vex::motor &m, char B) {
  m.setMaxTorque(95, percentUnits::pct); // set torque
  m.setTimeout(3, timeUnits::sec);       // set motor timeout
  m.resetRotation();                     // reset encoders
  if (B == 'C') {
    m.setStopping(brakeType::coast); // coast
  } else if (B == 'H') {
    m.setStopping(brakeType::hold); // braking
  } else if (B == 'B') {
    m.setStopping(brakeType::brake); // braking
  } else {
    m.setStopping(brakeType::coast); // braking
  }
}//end motor setup


//  USER TASKS
//contol auxilary systems  - lift - claw - intake control etc..
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