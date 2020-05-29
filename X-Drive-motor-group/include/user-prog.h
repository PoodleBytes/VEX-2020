#include "vex.h"

using namespace vex;

//DECLARE USER VARIABLES / FUNCTIONS

//VARIABLES
extern double slowSpeed;    //controller drive sensitivity - sensitive mode
extern double adjSpeed;    //controller drive sensitivity
extern int driveThreshold; //controller threshold for slowSpeed <> highSpeed changes

//FUNCTIONS
extern void xDrive(double degRotate, double motorSpeed, char Fwd_Rev_Left_Right, bool b);
extern void xTurn(double degrees, double motorSpeed, bool wait);
extern void setUpMotor(motor&, char);

//TASKS
extern int tUserCtl();  //tasks needed for user control 
extern int tAuton();    //tasks needed for autonomous 
