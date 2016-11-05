#include <Arduino.h>
#include "Main.h"
#include "LiquidCrystal.h"
#include <dht11.h>
#define DHT11PIN 22

dht11 DHT11;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup () {
  Serial.begin (9600);
}

void loop() {
  delay(2000);
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK:
		Serial.println("OK");
		break;
    case DHTLIB_ERROR_CHECKSUM:
		Serial.println("Checksum error");
		break;
    case DHTLIB_ERROR_TIMEOUT:
		Serial.println("Time out error");
		break;
    default:
		Serial.println("Unknown error");
		break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  lcd.setCursor(0, 0);
  lcd.print("H: ");
  lcd.print((float)DHT11.humidity);

  Serial.print("Temperature (°C): ");
  Serial.println((float)DHT11.temperature, 2);

  lcd.print(" T: ");
  lcd.print((float)DHT11.temperature);
}
