/*
 * Temperature and Humidity sensor
 * onto LCD display
 * Alex Munoz
 * alex@napend.com
 * 3/26/20
 */

// Add the libraries for the DHT11 sensor and the LCD.
#include <dht.h>
#include <LiquidCrystal.h>

// Define the pins for the sensor, LCD, and the name for the DHT
// in the code.
dht DHT;
#define DHT11_Pin 8
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup(){
  lcd.begin(16, 2);
}

void loop(){
  // Variables. Converts Celcius to Fahrenheit.
  int fahrenheit = (DHT.temperature * 1.8) + 32;
  int chk = DHT.read11(DHT11_Pin);

  // Temperature output on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(fahrenheit);

  // Humidity output on LCD.
  lcd.setCursor(0, 1);
  lcd.print("Humidity = ");
  lcd.print(DHT.humidity);
  
  delay(1000);
}
