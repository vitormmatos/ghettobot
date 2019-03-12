#include "GhettobotMotors.h"
#include <Thread.h>
#include <ThreadController.h>

GhettobotMotors motors(5, 7, 6, 8);

// Create a couple of constants for our pins.
const int ledPin = 13;
const int buttonPin = A0;
const int buttonPin1 = A1;
int forwardButton = 0;
int leftRightButton = 0;

ThreadController control = ThreadController();
Thread forward = Thread();
Thread leftRight = Thread();

void moveForward(){
  if( digitalRead(buttonPin) == LOW){
    switch (forwardButton){
      case 0:
        digitalWrite(ledPin, HIGH);
        motors.drive(100, 1);
        forwardButton = 1;
        delay(1000);
      break;
      case 1:
        digitalWrite(ledPin, LOW);
        motors.drive(0, 1);
        forwardButton = 0;
        delay(1000);
      break;
    }
  }
}

void moveRightLeft(){

  if( digitalRead(buttonPin1) == LOW){
    switch (leftRightButton){
      case 0:
        digitalWrite(ledPin, HIGH);
        motors.rightDrive(100, 1);
        leftRightButton = 1;
        delay(1000);
      break;
      case 1:
        motors.rightDrive(0, 1);
        leftRightButton = 2;
        delay(1000);
        motors.leftDrive(100, 1);
        delay(1000);
      break;
      case 2:
        digitalWrite(ledPin, LOW);
        motors.leftDrive(0, 1);
        delay(1000);
      break;
    }
  }
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  forward.onRun(moveForward);
  control.add(&forward);
  leftRight.onRun(moveRightLeft);
  control.add(&leftRight);
}


void loop() {
  control.run();
}
