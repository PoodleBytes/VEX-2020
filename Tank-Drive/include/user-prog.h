#include "vex.h"

using namespace vex;

/*====  START USER VARIABLES / FUNCTIONS / TASKS ======*/
//  USER VARIABLES
//drive() sensitivity
extern double adjSpeed;    //controller drive sensitivity
extern double slowSpeed;    //controller drive sensitivity - sensitive mode
extern int driveThreshold;  //joystick sensitivity rip point - slowSpeed to highSpeed 

//  USER FUNCTIONS
//motor set-up 
extern void setUpMotor(motor(M), char B);

//  USER TASKS
extern int tAuton(void);
extern int tUserCtl(void);


/*====  END  USER VARIABLES / FUNCTIONS  ======*/