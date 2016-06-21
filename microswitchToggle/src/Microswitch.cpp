#include <Arduino.h>

class Microswitch {
public:
  Microswitch(int pin, int bounceTime=50) {
    pinMode(pin, INPUT);
    _pin = pin;
    _bounceTime = bounceTime;
  }

  bool isPressed() {
    return digitalRead(_pin) == HIGH;
  }

  bool isClicked() {
    int reading = digitalRead(_pin);
    updateLastBounceTime(reading);

    if(stoppedBouncing() && stateChanged(reading)) {
      _state = reading;
      _lastState = reading;

      return _state == LOW;
    }

    _lastState = reading;
    return false;
  }

protected:
  int _pin;
  int _lastState;
  int _state;
  int _bounceTime;
  int _lastBounceTime;

  void updateLastBounceTime(int reading) {
    if(reading != _lastState) {
      _lastBounceTime = millis();
    }
  }

  bool stoppedBouncing() {
    return (millis() - _lastBounceTime) > _bounceTime;
  }

  bool stateChanged(int reading) {
    return reading != _state;
  }

  bool stateChangedToLOW(int reading) {
    return reading == LOW;
  }
};
