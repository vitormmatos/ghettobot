#ifndef GhettobotLineSensor_h
#define GhettobotLineSensor_h

#include <Arduino.h>

// Infrared Line Sensor
#define PIN_LS_1  A2
#define PIN_LS_2  A3

// This is the reflectance sensor used for eg line following and table edge
//  detection. It's pretty crude, but since they're analog sensors, they're
//  kind of hard to work with.
class GhettobotLineSensor {
  public:
    GhettobotLineSensor(int pin);  // Configure a pin as a sensor.
    int read();             // Return the current value of the pin.
    boolean check();        // In theory, this will be true if a deviation from
                            //  detectLevel is found; false otherwise.
    int setBGLevel();       // You can calibrate the sensor to detect a deviation
    int setDetectLevel();   //  from detectLevel; these functions allow for that.
    boolean calStatus();    // Have both calibrated levels been set yet?
  private:
    int _pin;
    int _BGLevel;
    int _lineLevel;
};

#endif
