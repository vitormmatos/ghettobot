#ifndef GhettobotMotors_h
#define GhettobotMotors_h

#include <Arduino.h>

// Pins definitions
// Motors
#define PIN_ML_PWM   5
#define PIN_ML_DIR   7
#define PIN_MR_PWM   6
#define PIN_MR_DIR   8

// Constantes de direção para as funções dos motores
#define BACKWARD  1
#define FORWARD 0
#define RIGHT 0
#define LEFT 1

// Motors functions directions constants
#define BACKWARD  0
#define FORWARD 1
#define RIGHT 0
#define LEFT 1

// Distance Sensor divisors values
#define CM 28
#define INCH 71

// This class handles motor functionality. I expect one instance of this at the
// start of a piece of FalconRobot code.
class GhettobotMotors {
  public:
    GhettobotMotors();  // Constructor. Mainly sets up pins.
    GhettobotMotors(int pinMLPWM, int pinMLDIR, int pinMRPWM, int pinMRDIR); // Constructor

    void leftStop();  // Stop left motor, as with stop().
    void rightStop(); // Stop right motor, as with stop().

    void stop();  // Stop motors

    void drive(int speed, boolean direction); // Drive in direction given
    void drive(int speed, boolean direction, int duration); // drive(), but with a delay(duration)

    void rightDrive(int speed, boolean direction);  // Drive just the right motor
    void leftDrive(int speed, boolean direction);  // Drive just the left motor

  private:
    int _pinMLPWM;
    int _pinMLDIR;
    int _pinMRPWM;
    int _pinMRDIR;
};

#endif
