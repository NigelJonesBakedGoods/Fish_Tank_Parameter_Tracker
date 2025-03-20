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

const int cycleButton = 24;
const int resetButton = 25;
int menuCycle;

//reset times in day, week order
const int time24H = 86400000;
const int time168H = 604800000;
int foodTime = time24H;
int waterChangeTime = time168H;
bool foodIsReady = false; 
bool waterChangeIsReady = false;


void setup() {
  pinMode(cycleButton, INPUT_PULLUP);
  pinMode(resetButton,  INPUT_PULLUP);
  sensors.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Hello, World!");
}

void loop() {
  while(foodIsReady == false && waterChangeIsReady == false){  

    if(digitalRead(cycleButton) == HIGH){
      menuCycle = (menuCycle + 1) % 5;
      while(digitalRead(cycleButton) == HIGH){}
    }

  //the cycle manager is reaaaaaalllly shit, i cant figure out arrays with text which is what a would like but oh well
    if(menuCycle == 0){
      displayFoodTime(foodTime);
    }else if(menuCycle == 1){
      displayWaterChangeTime(waterChangeTime);
    }

    //Timer Manager
    foodTime -= 10;
    waterChangeTime -= 10;

    if (foodTime == 0 || waterChangeTime == 0){

    }
    delay(10);
  }

  if(foodIsReady == true){
    //print lcd Please Feed Fish and Spam the fuck out of the alarm
    if 
  }else if (waterChangeIsReady){
    //print lcd Please change fish tank water and spam the fuck out of the alarm

  }


}


//for the displays i want to create a class so i can just call foodtime.timer() to pull values. figure it out, or dont i mean we can just fuck around a little lol
void displayFoodTime(int(time)){

}

void displayWaterChangeTime(int(time)){

}



/*
//prints temp in C
void printTemp() {
  lcd.setCursor(0, 1);
  lcd.print(sensors.getTempCByIndex(0)+ ((char)176) + "C");


}
*/
