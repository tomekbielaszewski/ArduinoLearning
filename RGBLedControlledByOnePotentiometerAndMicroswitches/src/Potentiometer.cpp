#include <Arduino.h>

class Potentiometer {
public:
  Potentiometer(byte pin) {
    pinMode(pin, OUTPUT);
    _pin = pin;
  }

  bool isMin() {
    return analogRead(_pin) == 0;
  }

  bool isMax() {
    return analogRead(_pin) == MAX;
  }

  int get(int scaleTo=1023) {
    return analogRead(_pin)/(MAX/scaleTo);
  }

protected:
  const int MAX = 1023;
  byte _pin;
};
