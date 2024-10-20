#ifndef Nethelperlib_h
#define Nethelperlib_h
#include "Arduino.h"

class NetHelperLib{
public:
  enum Level {
    BASICI,
    NORMALE,
    DISCRETI,
    AVANZATI
  };

  static char * generaPiano(char piano, char diff, char* branchId);
  static char** generaPiani(char numPiani,  char diff, char numeroDiramazioni);
private: 
  static uint8_t rollD6();
  static uint8_t roll3D6();
  static uint8_t rollD10();

};
#endif