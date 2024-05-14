#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 15, 1); // (address, columns, rows)
int SDA_pin = D4;
int SCL_pin = D3;

void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Halo nama saya gatau ini apaan si gajelas jir");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}
