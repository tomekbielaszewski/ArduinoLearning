#include <Arduino.h>
#include "Main.h"
#include "Diode.cpp"
#include "Microswitch.cpp"

const int DIODE_PIN = 8;
const int DIODE2_PIN = 9;
const int MICROSWITCH_PIN = 4;

Diode* diode;
Diode* diode2;
Microswitch* microswitch;
bool diode2Activated = false;

void setup () {
  Serial.begin (9600);
  initComponents();
}

void loop() {
  if(microswitch->isPressed()) {
    diode->on();
  } else {
    diode->off();
  }

  if(microswitch->isClicked()) {
    diode2Activated = !diode2Activated;
  }

  diode2->set(diode2Activated);
}

void initComponents() {
  diode = new Diode(DIODE_PIN);
  diode2 = new Diode(DIODE2_PIN);
  microswitch = new Microswitch(MICROSWITCH_PIN);
}
