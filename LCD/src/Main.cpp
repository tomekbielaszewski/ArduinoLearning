#include <Arduino.h>
#include "Main.h"
#include "LiquidCrystal.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup () {
  Serial.begin (9600);
  initComponents();

  lcd.begin(16, 2);
  lcd.print("Hello, World!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
}

void initComponents() {
  // lcd = new LiquidCrystal(12, 11, 5, 4, 3, 2);
}
