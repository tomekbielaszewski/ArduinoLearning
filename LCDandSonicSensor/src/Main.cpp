#include <Arduino.h>
#include "Main.h"
#include "LiquidCrystal.h"
#include "SonicSensor.cpp"
#include "Diode.cpp"

const int TRIG_PIN = 22;
const int ECHO_PIN = 23;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SonicSensor sonic(TRIG_PIN, ECHO_PIN);
Diode diodes[7] = {
  Diode(40),
  Diode(41),
  Diode(42),
  Diode(43),
  Diode(44),
  Diode(45),
  Diode(46)
};

long timer;
long target;
long distance;

void setup () {
  Serial.begin (9600);
  initComponents();
}

void loop() {
  distance = sonic.getDistance();
  if(distance < 5 || distance > 195) {
    distance = -1;
  }

  drawUI();
  checkTarget();

  delay(100);
}

void initComponents() {
  lcd.begin(16, 2);
  timer = millis();
  randomSeed(analogRead(0));
  setNewTarget();
}

void drawUI() {
  lcd.setCursor(0, 0);
  lcd.print("Distance:     ");
  lcd.setCursor(10, 0);
  if(distance == -1) {
    lcd.print("n/a");
  } else {
    lcd.print(distance);
  }


  lcd.setCursor(0, 1);
  lcd.print("Target:   ");
  lcd.setCursor(7, 1);
  lcd.print(target);

  lcd.setCursor(11, 1);
  lcd.print("t:   ");
  lcd.setCursor(13, 1);
  lcd.print((millis() - timer)/1000);
}

void checkTarget() {
  lightLeds(target - distance);
  if(target == distance) {
    resetTimer();
    setNewTarget();
  }
}


void resetTimer() {
  timer = millis();
}

void setNewTarget() {
  target = random(190) + 5;
}

void lightLeds(long _diff) {
  long diff = abs(_diff);
  long max = 70;
  long scaleFrom = max - (diff > max ? max : diff);
  long scaleTo = 7;
  long scaled = scaleFrom/(max/scaleTo);

  if(scaled == 7) {
    for(int i = 0; i < 7; i++) {
        diodes[i].on();
    }
    for(int i = 0; i < 5; i++) {
        diodes[6].off();
        delay(200);
        diodes[6].on();
        delay(200);
    }
  } else {
    for(int i = 0; i < 7; i++) {
      if(i < scaled) {
        diodes[i].on();
      } else {
        diodes[i].off();
      }
    }
  }
}
