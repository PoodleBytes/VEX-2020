using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFM;
extern motor LBM;
extern motor RBM;
extern motor RFM;
extern smartdrive Drive;
extern inertial Gyro;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );