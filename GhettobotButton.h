#ifndef GhettobotButton_h
#define GhettobotButton_h

#include <Arduino.h>

// Pins definitions
// Buttons
#define PIN_BTN0  A0
#define PIN_BTN1  A1

// This is a simple class to handle the button object on the robot. It has only one
// method, read(). This returns a boolean value for whether the button is pressed.
class GhettobotButton {
  public:
    GhettobotButton(int pin);  // Constructor
    boolean read();  // Return the button state(Pressed = HIGH / Released = LOW)
  private:
    int _pin;
};

#endif
