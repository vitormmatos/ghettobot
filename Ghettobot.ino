#include "GhettobotMotors.h"
#include "GhettobotDistanceSensor.h"
#include <Thread.h>
#include <ThreadController.h>

ThreadController thController = ThreadController();
Thread seekThread = Thread();
Thread attackThread = Thread();
Thread turnLeftThread = Thread();
Thread turnRightThread = Thread();
Thread moveBackwardsThread = Thread();

GhettobotMotors motors(5, 7, 6, 8);
GhettobotDistanceSensor distances(1, 0, 20000UL);
bool lineFrontLeftValue;
bool lineFrontRightValue;

int checkLine(){
  if(analogRead(A0) > 700 && analogRead(A1) > 700){
    return 0;
  }else if (analogRead(A0) < 700 && analogRead(A1) < 700){
    return 1;
  }else if (analogRead(A0) > 700 && analogRead(A1) < 700){
    return 2;  
  }else if (analogRead(A0) < 700 && analogRead(A1) > 700){
    return 3;
  }else
    return -1;
} 

void attack()
{
  if (distances.read() <= 30){
    motors.leftDrive(100, 0);
    motors.rightDrive(100, 1);
    delay(100);
  }
}

void seek(){
  if (distances.read() > 30 && checkLine()==0){
    motors.leftDrive(100, 1);
    motors.rightDrive(100, 1);
    delay(30);
    motors.leftStop();
    motors.rightStop();
    delay(120);
  }
}

void moveBackwards(){
  if(checkLine()==1){
    motors.leftDrive(100, 1);
    motors.rightDrive(100, 0);
    delay(50);
  }
}

void turnRight(){
  if(checkLine()==2){
    motors.rightDrive(60, 1);
    delay(300);
    motors.rightStop();
  }
}

void turnLeft(){
  if(checkLine()==3){
    motors.leftDrive(60, 0);
    delay(300);
    motors.leftStop();
  }
}

void setup() {
  
  delay(3000);

  seekThread.onRun(seek);
  seekThread.setInterval(110);
  thController.add(&seekThread);

  attackThread.onRun(attack);
  attackThread.setInterval(120);
  thController.add(&attackThread);

  turnLeftThread.onRun(turnLeft);
  turnLeftThread.setInterval(130);
  thController.add(&turnLeftThread);

  turnRightThread.onRun(turnRight);
  turnLeftThread.setInterval(130);
  thController.add(&turnRightThread);

  moveBackwardsThread.onRun(moveBackwards);
  moveBackwardsThread.setInterval(130);
  thController.add(&moveBackwardsThread);
}


void loop() {
  thController.run();
}
