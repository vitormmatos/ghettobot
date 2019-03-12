#ifndef GhettobotMotors_h
#define GhettobotMotors_h

#include <Arduino.h>

// Definição de pinos dos motores
#define PIN_ML_PWM   5
#define PIN_ML_DIR   7
#define PIN_MR_PWM   6
#define PIN_MR_DIR   8

// Constantes de direção para as funções dos motores
#define BACKWARD  1
#define FORWARD 0
#define RIGHT 0
#define LEFT 1

// Essa classe controla a funcionalidade do motor.
// É esperado uma instância dessa classe
// no inicio do código do Ghettobot.
class GhettobotMotors {
  public:
    GhettobotMotors();  // Constructor. Estabelece os pinos
    GhettobotMotors(int pinMLPWM, int pinMLDIR, int pinMRPWM, int pinMRDIR); // Constructor

    void leftStop();  // Para o motor esquerdo.
    void rightStop(); // ara o motor direito.

    void stop();  // Para os motores

    void drive(int speed, boolean direction); // Dirige na direção dada
    void drive(int speed, boolean direction, int duration); // drive(), mas com um delay

    void rightDrive(int speed, boolean direction);  // Dirige apenas com o motor direito
    void leftDrive(int speed, boolean direction);  // Dirige apenas com o motor esquerdo

  private:
    int _pinMLPWM;
    int _pinMLDIR;
    int _pinMRPWM;
    int _pinMRDIR;
};

#endif
