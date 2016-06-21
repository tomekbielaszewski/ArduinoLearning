#include <Arduino.h>

class Diode {
public:
  Diode(int pin) {
    pinMode(pin, OUTPUT);
    _pin = pin;
  }

  void on() {
    digitalWrite(_pin, HIGH);
  }

  void off() {
    digitalWrite(_pin, LOW);
  }

  void set(int state) {
    digitalWrite(_pin, state);
  }

protected:
  int _pin;
};
