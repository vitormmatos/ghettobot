#include "GhettobotMotors.h"
#include <Arduino.h>

// Pins definitions
// Motors
#define PIN_ML_PWM   5
#define PIN_ML_DIR   7
#define PIN_MR_PWM   6
#define PIN_MR_DIR   8

// Constructor.
GhettobotMotors::GhettobotMotors(int pinMLPWM, int pinMLDIR, int pinMRPWM, int pinMRDIR) {
  // DIR defines the direction (forward, reverse); PWM defines the speed.
  _pinMLPWM = pinMLPWM;
  _pinMLDIR = pinMLDIR;
  _pinMRPWM = pinMRPWM;
  _pinMRDIR = pinMRDIR;

  pinMode(_pinMLPWM, OUTPUT);
  pinMode(_pinMLDIR, OUTPUT);
  pinMode(_pinMRPWM, OUTPUT);
  pinMode(_pinMRDIR, OUTPUT);
}

// Constructor. Mostly for pin setup;
GhettobotMotors::GhettobotMotors() {
    // DIR defines the direction (forward, reverse); PWM defines the speed.
  _pinMLPWM = PIN_ML_PWM;
  _pinMLDIR = PIN_ML_DIR;
  _pinMRPWM = PIN_MR_PWM;
  _pinMRDIR = PIN_MR_DIR;

  pinMode(_pinMLPWM, OUTPUT);
  pinMode(_pinMLDIR, OUTPUT);
  pinMode(_pinMRPWM, OUTPUT);
  pinMode(_pinMRDIR, OUTPUT);
}

// Basically the same as drive(), but omitting the right motor.
void GhettobotMotors::rightDrive(int speed, boolean direction) {
  speed = speed > 100 ? 100 : speed < 0 ? 0 : speed;
  speed = map(speed, 0, 100, 0, 255);
  digitalWrite(_pinMRDIR, direction);
  analogWrite(_pinMRPWM, speed);
}

// Basically the same as drive, but omitting the left motor.
void GhettobotMotors::leftDrive(int speed, boolean direction) {
  speed = speed > 100 ? 100 : speed < 0 ? 0 : speed;
  speed = map(speed, 0, 100, 0, 255);
  digitalWrite(_pinMLDIR, direction);
  analogWrite(_pinMLPWM, speed);
}

// Stop funcions for the each motor
void GhettobotMotors::leftStop() {
  analogWrite(_pinMLPWM, 0);
}

void GhettobotMotors::rightStop() {
  analogWrite(_pinMRPWM, 0);
}

// Stop funcion for the both motors
void GhettobotMotors::stop() {
  leftStop();
  rightStop();
}

// drive() starts both motors. It figures out whether the motors should go
//  forward or revers, then calls the appropriate individual functions.
void GhettobotMotors::drive(int speed, boolean direction) {
  leftDrive(speed, direction);
  rightDrive(speed, direction);
}

// this variant of drive() integrates a delay duration to allow for single
// commmand instruction.
void GhettobotMotors::drive(int speed, boolean direction, int duration) {
  drive(speed, direction);
  delay(duration);
  stop();
}
