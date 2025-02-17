/*
  The Fish tank parameter tracker is a program designed for the Arduino mega 2560 to track different variable in my fish tank.
*/
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Setup for Temp sensor
#define ONE_WIRE_BUS 22
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Setup for LCD display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  sensors.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Hello, World!");
}

void loop() {
  

}

//prints temp in C
void printTemp() {
  lcd.setCursor(0, 1);
  lcd.print(sensors.getTempCByIndex(0)+ ((char)176) + "C");
}

