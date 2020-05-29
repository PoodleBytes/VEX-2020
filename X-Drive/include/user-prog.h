#include "vex.h"

using namespace vex;

//DECLARE USER VARIABLES / FUNCTIONS

//VARIABLES
extern double slowSpeed;    //controller drive sensitivity - sensitive mode
extern double adjSpeed;    //controller drive sensitivity
extern int driveThreshold; //controller threshold for slowSpeed 7 highSpeed changes

//FUNCTIONS
extern void xDrive(double degRotate, double motorSpeed, char Fwd_Rev_Left_Right, bool b);
extern void xTurn(double degrees, double motorSpeed, bool wait);
extern void setUpMotor(motor(MotorName), char Coast_Brake_Hold);

//TASKS
extern int tUserCtl();  //user control 
extern int tAuton();    //needed for autonomous 
