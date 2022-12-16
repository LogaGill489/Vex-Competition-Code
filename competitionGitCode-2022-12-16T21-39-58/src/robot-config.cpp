#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Motor1 = motor(PORT1, ratio6_1, true);
motor Motor2 = motor(PORT2, ratio6_1, false);
motor Motor3 = motor(PORT3, ratio6_1, true);
motor Motor5 = motor(PORT5, ratio6_1, false);
motor Motor6 = motor(PORT6, ratio6_1, true);
motor Motor7 = motor(PORT7, ratio6_1, false);
motor Motor8 = motor(PORT8, ratio36_1, true);
motor Motor9 = motor(PORT9, ratio6_1, true);
limit LimitSwitchA = limit(Brain.ThreeWirePort.A);
digital_out DigitalOutH = digital_out(Brain.ThreeWirePort.H);
digital_out DigitalOutC = digital_out(Brain.ThreeWirePort.C);
digital_out DigitalOutB = digital_out(Brain.ThreeWirePort.B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}