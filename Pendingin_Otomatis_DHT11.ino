#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h" 
#define DHTPIN 2     
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

int temp;
int led = 13;
float min_temp = 32.00;
float max_temp = 32.20;
const int PIN = 3;

void setup() {
  dht.begin();
  lcd.begin();
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(PIN3, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  if(temp >= max_temp) {
    digitalWrite(led, HIGH);
    lcd.print("Pendingin Aktif ");
    digitalWrite(PIN3, HIGH);
  }
  
  if(temp <= min_temp) {
    digitalWrite(led, LOW);
    lcd.print("Pendingin Mati ");
    digitalWrite(PIN3, LOW);
  }
  
  else {
    lcd.print("Otomatis");
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Suhu: ");
  lcd.print(temp);
  lcd.print("C");
  delay(1000);
  lcd.clear();
}
