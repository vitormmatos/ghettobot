#ifndef GhettobotDistanceSensor_h
#define GhettobotDistanceSensor_h

#include <Arduino.h>

// Pins definitions
// Ultrasonic Distance Sensor
#define PIN_ECHO  2
#define PIN_TRIG  3

// Distance Sensor divisors values
#define CM 28
#define INCH 71

// This handles the ultrasonic distance sensor.
class GhettobotDistanceSensor {
  public:
    GhettobotDistanceSensor(int pinEcho, int pinTrig, unsigned long timeout = 20000UL); // Simple constructor
    unsigned int read();
    unsigned int read(int unit);
    void setTimeout(unsigned long timeout) {_timeout = timeout;}

  private:
    int _pinEcho;
    int _pinTrig;
    unsigned long _timeout;
    unsigned long timing();
};

#endif
