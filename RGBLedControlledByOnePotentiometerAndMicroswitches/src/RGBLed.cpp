#include <Arduino.h>

class RGBLed {
public:
  RGBLed(byte rPin, byte gPin, byte bPin) {
    pinMode(rPin, INPUT);
    pinMode(gPin, INPUT);
    pinMode(bPin, INPUT);

    _rPin = rPin;
    _gPin = gPin;
    _bPin = bPin;
  }

  void set(byte r, byte g, byte b) {
    analogWrite(_rPin, r);
    analogWrite(_gPin, g);
    analogWrite(_bPin, b);

    Serial.print  ("   LED: ");
    Serial.print  (r); Serial.print(" ");
    Serial.print  (g); Serial.print(" ");
    Serial.println(b);

  }

  void zero() {
    analogWrite(_rPin, 0);
    analogWrite(_gPin, 0);
    analogWrite(_bPin, 0);
  }

protected:
  byte _rPin;
  byte _gPin;
  byte _bPin;
};
