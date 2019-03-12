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
  return pulseIn(_pinEcho, HIGH, _timeout); // duração
}

unsigned int GhettobotDistanceSensor::read(int unit) {
  // Retorna a distância da unidade
  return timing() / unit / 2;
}

unsigned int GhettobotDistanceSensor::read() {
  /*
   * Caso a unidade de medida não seja passada como parâmetro,
   * por padrão, será retornada a distância em centimetros.
   * Para substituir o padrão substitua CM por INCH(polegadas).
   */
  return read(CM);
}
