#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// alamat = 0x27

Servo myServo;
int trigPin = D1;
int echoPin = D2;
int greenLED = D3;
int redLED = D4;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D6;
int SCL_pin = D7;

long duration;
int distance;

void setup()
{
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  myServo.attach(D0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  // lcd.setCursor(0,0);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jarak : ");
  lcd.print(distance);
  lcd.print(" cm");

  if (distance <= 10)
  {
    myServo.write(180);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    lcd.setCursor(4, 1);
    lcd.print("TERBUKA");

    delay(1000);
  }
  else if (distance > 10)
  {
    myServo.write(0);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    lcd.setCursor(4, 1);
    lcd.print("TERTUTUP");
    delay(1000);
  }
}
