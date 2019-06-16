#include "GhettobotButton.h"
#include <Arduino.h>

GhettobotButton::GhettobotButton(int pin) {
  // Sets the "default" state of the button to be HIGH.
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

boolean GhettobotButton::read() {
  return(!digitalRead(_pin));
}
