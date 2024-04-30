#include <Arduino.h>
#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(D4);
}

void loop() {
  // myservo.write(90);
  // for (int i = 0; i <= 180; i++)
  // {
  //   myservo.write(i);
  //   delay(5); // dalam ms
  // }
  // for (int i = 0; i >= 0; i--)
  // {
  //   myservo.write(i);
  //   delay(5);
  // }
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
   
}
