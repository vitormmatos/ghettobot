#include "GhettobotButton.h"
#include <Arduino.h>

GhettobotButton::GhettobotButton(int pin) {
  // Atribui o estado padrão do botão para HIGH.
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

boolean GhettobotButton::read() {
  return(!digitalRead(_pin));
}
