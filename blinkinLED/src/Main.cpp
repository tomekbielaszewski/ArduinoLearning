#include <Arduino.h>
#include "Main.h"
#include "Diode.cpp"

const int DIODE_COUNT = 10;
const int INITIAL_DIODE_PIN = 30;

Diode* diodes[DIODE_COUNT];

void setup () {
  Serial.begin (9600);
  initDiodes();
}

void loop() {
  onEveryDiode();
  delay(1);
}

void initDiodes() {
  for (byte i = 0; i < DIODE_COUNT; i++) {
    diodes[i] = new Diode(i + INITIAL_DIODE_PIN);
  }
}

void onEveryDiode() {
    for (byte i = 0; i < DIODE_COUNT; i++) {
      diodes[i]->blink();
    }
}
