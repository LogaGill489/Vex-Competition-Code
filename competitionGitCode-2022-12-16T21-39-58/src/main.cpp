/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor1               motor         1               
// Motor2               motor         2               
// Motor3               motor         3               
// Motor5               motor         5               
// Motor6               motor         6               
// Motor7               motor         7               
// Motor8               motor         8               
// Motor9               motor         9               
// LimitSwitchA         limit         A               
// DigitalOutH          digital_out   H               
// DigitalOutC          digital_out   C               
// DigitalOutB          digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

  Motor9.spin(forward);
  Motor9.setVelocity(100, percent);

  wait(500, msec);
  Motor9.stop();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  int deadband = 5;

  motor_group driveL(Motor1, Motor2, Motor3);
  motor_group driveR(Motor7, Motor5, Motor6);

  driveL.spin(forward);
  driveR.spin(forward);
  Motor8.spin(forward);

  while (1) {
        // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    int rightspeed = Controller1.Axis3.position() + Controller1.Axis1.position();
    int leftspeed = Controller1.Axis3.position() - Controller1.Axis1.position();

    //right side code
    //if stick input is not given, no motor spin will occur
    //velocity changes based on stick input
    if (abs(rightspeed) < deadband)
    {
      driveR.setVelocity(0, percent);
    }
    else
    {
      driveR.setVelocity(rightspeed, percent);
    }

    //left side code
    if (abs(leftspeed) < deadband)
    {
      driveL.setVelocity(0, percent);
    }
    else
    {
      driveL.setVelocity(leftspeed, percent);
    }

    //catapult code
    Motor8.setVelocity(100, percent);

    if (LimitSwitchA.pressing())
    {
      Motor8.stop();
    }
    if (Controller1.ButtonA.pressing())
    {
      Motor8.spin(forward);
    }

    Motor9.setVelocity(100, percent);

    //intake / roller code 
    if (Controller1.ButtonR2.pressing())
    {
      Motor9.spin(forward);
    }
    else if (Controller1.ButtonR1.pressing())
    {
      Motor9.spin(reverse);
    }
    else
    {
        
       Motor9.stop();
    }
    
    //pnuematics for allignment of discs in catapult
    if (Controller1.ButtonX.pressing())
    { 
      DigitalOutH.set(true);
    }
    else 
    {
      DigitalOutH.set(false);
    }

    //pnuematics for endgame
    if (Controller1.ButtonL2.pressing() && Controller1.ButtonL1.pressing() && 
    Controller1.ButtonY.pressing())
    {
      DigitalOutB.set(true);
      DigitalOutC.set(true);
    }
    else
    {
      DigitalOutB.set(false);
      DigitalOutC.set(false);
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
