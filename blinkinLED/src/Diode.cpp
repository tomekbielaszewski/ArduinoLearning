#include <Arduino.h>

class Diode {
public:
  Diode(int pin) {
    pinMode(pin, OUTPUT);
    _pin = pin;
  }
  void blink() {
    if(_timer < 0) {
      digitalWrite(_pin, _isHigh ? HIGH : LOW);
      _timer = rand() % 1000;
      _isHigh = !_isHigh;
    } else {
      _timer -= 1;
    }
  }

protected:
  int _pin;
  int _timer=0;
  bool _isHigh=false;
};
