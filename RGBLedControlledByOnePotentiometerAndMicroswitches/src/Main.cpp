#include <Arduino.h>
#include "Main.h"
#include "MicroswitchMatrix.cpp"

const int POTENTIOMETER_PIN = 10;
const int RGB_LED_PINS[] = {13, 12, 11};
const int RGB_MICROSWITCH_PINS[] = {7, 6, 5};

MicroswitchMatrix* microswitches;

void setup () {
  Serial.begin(9600);
  initComponents();
}

void loop() {

  microswitches->isSwitched();

  delay(1000);
}

void initComponents() {
  Microswitch microswitchesArray[] = {
    Microswitch(RGB_MICROSWITCH_PINS[0]),
    Microswitch(RGB_MICROSWITCH_PINS[1]),
    Microswitch(RGB_MICROSWITCH_PINS[2])
  };
  microswitches = new MicroswitchMatrix(microswitchesArray, 3);
}
