#include "GhettobotMotors.h"
#include <Arduino.h>

// Constructor.
GhettobotMotors::GhettobotMotors(int pinMLPWM, int pinMLDIR, int pinMRPWM, int pinMRDIR) {
  // DIR define a direção (forward, reverse); PWM define a velocidade.
  _pinMLPWM = pinMLPWM;
  _pinMLDIR = pinMLDIR;
  _pinMRPWM = pinMRPWM;
  _pinMRDIR = pinMRDIR;

  pinMode(_pinMLPWM, OUTPUT);
  pinMode(_pinMLDIR, OUTPUT);
  pinMode(_pinMRPWM, OUTPUT);
  pinMode(_pinMRDIR, OUTPUT);
}

// Constructor. Basicamente setup de pinos
GhettobotMotors::GhettobotMotors() {
    // DIR define a direção (forward, reverse); PWM define a velocidade.
  _pinMLPWM = PIN_ML_PWM;
  _pinMLDIR = PIN_ML_DIR;
  _pinMRPWM = PIN_MR_PWM;
  _pinMRDIR = PIN_MR_DIR;

  pinMode(_pinMLPWM, OUTPUT);
  pinMode(_pinMLDIR, OUTPUT);
  pinMode(_pinMRPWM, OUTPUT);
  pinMode(_pinMRDIR, OUTPUT);
}

// Basicamente o mesmo que drive(), mas omitindo o motor direito.
void GhettobotMotors::rightDrive(int speed, boolean direction) {
  speed = speed > 100 ? 100 : speed < 0 ? 0 : speed;
  speed = map(speed, 0, 100, 0, 255);
  digitalWrite(_pinMRDIR, direction);
  analogWrite(_pinMRPWM, speed);
}

// Basicamente o mesmo que drive(), mas omitindo o motor esquerdo.
void GhettobotMotors::leftDrive(int speed, boolean direction) {
  speed = speed > 100 ? 100 : speed < 0 ? 0 : speed;
  speed = map(speed, 0, 100, 0, 255);
  digitalWrite(_pinMLDIR, direction);
  analogWrite(_pinMLPWM, speed);
}

// Para o motor esquerdo
void GhettobotMotors::leftStop() {
  analogWrite(_pinMLPWM, 0);
}
// Para o motor direito
void GhettobotMotors::rightStop() {
  analogWrite(_pinMRPWM, 0);
}

// Para ambos os motores
void GhettobotMotors::stop() {
  leftStop();
  rightStop();
}

// drive() inicia ambos motores.
// A função primeiramente determina qual direção os motores
// devem seguir, para frente ou para trás em seguida chama
// as seguintes funções individuais adequadas
void GhettobotMotors::drive(int speed, boolean direction) {
  leftDrive(speed, direction);
  rightDrive(speed, direction);
}

// Essa variação de this drive() integra a duração de delay
void GhettobotMotors::drive(int speed, boolean direction, int duration) {
  drive(speed, direction);
  delay(duration);
  stop();
}
