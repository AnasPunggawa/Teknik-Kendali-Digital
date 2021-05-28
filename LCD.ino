#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.setCursor(5,0);
  lcd.print("P");delay(1000); lcd.print("T");delay(300);
  lcd.print("I");delay(300); lcd.print("K");delay(300);
  lcd.print("-");delay(300); lcd.print("B");delay(300);

  lcd.setCursor(1,1);
  lcd.print("B");delay(200); lcd.print("E");delay(200);
  lcd.print("L");delay(200); lcd.print("A");delay(200);
  lcd.print("J");delay(200); lcd.print("A");delay(200);
  lcd.print("R ");delay(200); lcd.print("A");delay(200);
  lcd.print("R");delay(200); lcd.print("D");delay(200);
  lcd.print("U");delay(200); lcd.print("I");delay(200);
  lcd.print("N");delay(200); lcd.print("0");delay(3000);
  lcd.clear();
}

void loop() {
  int u;
  lcd.setCursor(1, 0);
  lcd.print("Kelompok 13 - Risdar - Anas - Angga - Ayu");
  for (u = 0 ; u < 16; u++) {
    lcd.scrollDisplayLeft();
    //lcd.scrollDisplayRight();
    delay(500);
  }
}
