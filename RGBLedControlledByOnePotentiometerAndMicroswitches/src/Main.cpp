#include <Arduino.h>
#include "Main.h"
#include "Microswitch.cpp"
#include "Potentiometer.cpp"
#include "RGBLed.cpp"

const int POTENTIOMETER_PIN = 0;
const int RGB_MICROSWITCH_PINS[] = {7, 6, 5};
int RGB_LED_R = 12;
int RGB_LED_G = 11;
int RGB_LED_B = 10;

Microswitch* rswitch;
Microswitch* gswitch;
Microswitch* bswitch;
Potentiometer* potentiometer;
RGBLed* led;

byte channels[] = {255, 255, 255};

void setup () {
  Serial.begin(9600);
  initComponents();
}

void loop() {
  int channelBright = 255 - potentiometer->get(255);
  Serial.print(channelBright);
  Serial.print(" ->");

  if(rswitch->isPressed()) {
    channels[0] = channelBright;
  } else if(gswitch->isPressed()) {
    channels[1] = channelBright;
  } else if(bswitch->isPressed()) {
    channels[2] = channelBright;
  }

  led->set(channels[0], channels[1], channels[2]);
}

void initComponents() {
  rswitch = new Microswitch(RGB_MICROSWITCH_PINS[0]);
  gswitch = new Microswitch(RGB_MICROSWITCH_PINS[1]);
  bswitch = new Microswitch(RGB_MICROSWITCH_PINS[2]);
  potentiometer = new Potentiometer(POTENTIOMETER_PIN);
  led = new RGBLed(RGB_LED_R, RGB_LED_G, RGB_LED_B);
}
