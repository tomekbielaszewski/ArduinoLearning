#include <Arduino.h>

class SonicSensor {
public:
  SonicSensor(byte trigPin, byte echoPin) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    _trig_pin = trigPin;
    _echo_pin = echoPin;
  }

  long getDistance() {
    sendPulse();

    long duration = pulseIn(_echo_pin, HIGH);
    long distance = (duration / 2) / SOUND_MULTIPLIER;

    return distance;
  }

protected:
  const long MAX = 200;
  const long MIN = 5;
  const long SOUND_MULTIPLIER = 29.1;
  byte _trig_pin;
  byte _echo_pin;

  void sendPulse() {
    digitalWrite(_trig_pin, LOW);
    delayMicroseconds(5);
    digitalWrite(_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig_pin, LOW);
  }
};
