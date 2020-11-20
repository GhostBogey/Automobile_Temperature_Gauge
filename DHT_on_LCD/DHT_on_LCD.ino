#include <SimpleDHT.h>
#include <LiquidCrystal.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2

int pinDHT11 = 2;
SimpleDHT11 dht11;

// for LCD
int tempPin = 0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  //Serial.println("Sample DHT11...");
}

void loop() {
  // start working...
  lcd.setCursor(0, 0);
  //lcd.println("=================================");
  //Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    //Serial.print("Read DHT11 failed.");
    return;
  }
  
  lcd.print("Temp         F  ");
  lcd.setCursor(6, 0);
  lcd.print(int(temperature));
  //Serial.print((int)humidity); Serial.println(" %");
  //Serial.print("\n");
  // DHT11 sampling rate is 1HZ.
  delay(500);
}
