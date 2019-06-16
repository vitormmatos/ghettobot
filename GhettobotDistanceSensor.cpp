#include "GhettobotDistanceSensor.h"
#include <Arduino.h>

#define CM_DIVISOR  28
#define INC_DIVISOR 71

GhettobotDistanceSensor::GhettobotDistanceSensor(int pinEcho, int pinTrig, unsigned long timeout) {
  _pinEcho = pinEcho;
  _pinTrig = pinTrig;
  pinMode(_pinEcho, INPUT);
  pinMode(_pinTrig, OUTPUT);
  _timeout = timeout;
}

unsigned long GhettobotDistanceSensor::timing() {
  digitalWrite(_pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(_pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pinTrig, LOW);
  return pulseIn(_pinEcho, HIGH, _timeout); // duration
}

unsigned int GhettobotDistanceSensor::read(int unit) {
  // return the distance in the unit
  return timing() / unit / 2;
}

unsigned int GhettobotDistanceSensor::read() {
  /*
   * If the unit of measure is not passed as a parameter,
   * by default, it will return the distance in centimeters.
   * To change the default, replace CM by INCH.
   */
  return read(CM_DIVISOR);
}
