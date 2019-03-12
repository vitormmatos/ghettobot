#ifndef GhettobotLineSensor_h
#define GhettobotLineSensor_h

#include <Arduino.h>

// Definição de pinos do Sensor de Linha Infravermelho
#define PIN_LS_1  A2
#define PIN_LS_2  A3

// Esse é um senso de refletância usado para por exemplo seguir uma linha
// ou verificar a borda de uma mesa.
class GhettobotLineSensor {
  public:
    GhettobotLineSensor(int pin);  // Configura um pino como sensor.
    int read();             // Retorna o atual valor do pino

    boolean check();        // Em teoria, essa função retornará verdadeiro
                            //  caso encontrado um desvio no detectLevel
                            // caso contrário falso.

    int setBGLevel();       // Você pode calibrar o sensor para detectar um desvio
    int setDetectLevel();   // do detectLevel. Essas funções permitem isso.

    boolean calStatus();    // Ambos os níveis de calibração foram definidos?
  private:
    int _pin;
    int _BGLevel;
    int _lineLevel;
};

#endif
