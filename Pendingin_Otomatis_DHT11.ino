#include <Wire.h>                           // Memasukkan library komunikasi I2C
#include <LiquidCrystal_I2C.h>              // Memasukkan library I2C LCD
#include "DHT.h"                            // Memasukkan library DHT
#define DHTPIN 2                            // Menggunakan pin 2 untuk Sensor DHT
#define DHTTYPE DHT11                       // Menggunakan tipe DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);         // Mengubah alamat 0x27 dengan alamat I2C
DHT dht(DHTPIN, DHTTYPE);                   // Pengaturan pin yang dipilih dan tipe DHT

int led = 13;                               // Menetapkan variabel led untuk pin 13 untuk LED
float min_temp = 32.00;                     // Menetapkan nilai variabel min_temp
float max_temp = 32.20;                     // Menetapkan nilai variabel max_temp
const int PIN = 3;                          // Menetapkan variabel PIN untuk pin 3 untuk Relay Module

void setup() {
  dht.begin();                              // Komunikasi DHT dengan Arduino
  lcd.begin();                              // Komunikasi LCD dengan Arduino
  pinMode(led, OUTPUT);                     // Menyatakan led sebagai OUTPUT
  pinMode(PIN3, OUTPUT);                    // Menyatakan PIN3 sebagai OUTPUT
}

void loop() {
  float temp = dht.readTemperature();       // Menyimpan nilai Temperature pada variabel temp
  if(temp >= max_temp) {                    // Keadaan ketika nilai temp lebih/sama dengan max_temp
    digitalWrite(led, HIGH);                // LED menyala
    lcd.print("Pendingin Aktif ");          // Ditampilkan di LCD
    digitalWrite(PIN3, HIGH);               // Relay dalam keadaan menyala/mengalirkan listrik
  }
  
  if(temp <= min_temp) {                    // Keadaan ketika nilai temp kurang/sama dengan min_temp
    digitalWrite(led, LOW);                 // LED mati
    lcd.print("Pendingin Mati ");           // Ditampilkan di LCD
    digitalWrite(PIN3, LOW);                // Relay dalam keadaan mati/tidak mengalirkan listrik
  }
  
  else {
    lcd.print("Otomatis");                  // Ditampilkan di LCD
  }
  
  lcd.setCursor(0, 1);                      // Baris Kedua
  lcd.print("Suhu: ");                      // "Suhu: "itampilkan di LCD
  lcd.print(temp);                          // Nilai temp ditampilkan di LCD
  lcd.print("C");                           // Ditampilkan di LCD
  delay(1000);                              // Delay LCD
  lcd.clear();                              // Membersihkan LCD
}
