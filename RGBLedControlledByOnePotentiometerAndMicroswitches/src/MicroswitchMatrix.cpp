#include <Arduino.h>
#include <Microswitch.cpp>

class MicroswitchMatrix {
public:
  MicroswitchMatrix(Microswitch *firstMicroswitch, byte amount) {
    _microswitches = firstMicroswitch;
    _amount = amount;
    _lastClicked = -1;

    for (byte i = 0; i < _amount; i++) {
      Microswitch* microswitch = firstMicroswitch + i;
      Serial.print(microswitch->getPin(), OCT);
      Serial.print(" ");
    }
    Serial.println();
    Serial.println();

    for (byte i = 0; i < _amount; i++) {
      Microswitch* microswitch = _microswitches + i;
      Serial.print(microswitch->getPin(), OCT);
      Serial.print(" ");
    }
    Serial.println();
  }

  bool isSwitched() {
    for (byte i = 0; i < _amount; i++) {
      Microswitch* microswitch = _microswitches + i;
      Serial.print(microswitch->getPin(), OCT);
      Serial.print(" ");

      // if(microswitch.isClicked()) {
      //   Serial.println("T");
      // }
      // if(microswitch->isClicked() && !isClickedLast(microswitch)) {
      //   setLastClicked(microswitch);
      //   return true;
      // }
    }
    Serial.println();
    return false;
  }

  byte getSwitchedTo() {
    return _lastClicked;
  }

protected:
  Microswitch *_microswitches;
  byte _amount;
  byte _lastClicked;

  bool isClickedLast(Microswitch* microswitch) {
    return _lastClicked == microswitch->getPin();
  }

  void setLastClicked(Microswitch* microswitch) {
    _lastClicked = microswitch->getPin();
  }
};
