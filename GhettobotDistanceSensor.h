#ifndef GhettobotDistanceSensor_h
#define GhettobotDistanceSensor_h

#include <Arduino.h>

// Definição de pinos do Sensor de Distância Ultrassonico
#define PIN_ECHO  2
#define PIN_TRIG  3

// Valores para operações matemáticas do sensor de distância
#define CM 28
#define INCH 71

// Essa classe é responsável pelo Sensor de Distância Ultrassonico.
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
