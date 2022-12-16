using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Motor1;
extern motor Motor2;
extern motor Motor3;
extern motor Motor5;
extern motor Motor6;
extern motor Motor7;
extern motor Motor8;
extern motor Motor9;
extern limit LimitSwitchA;
extern digital_out DigitalOutH;
extern digital_out DigitalOutC;
extern digital_out DigitalOutB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );