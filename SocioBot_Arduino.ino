#include <Servo.h>

#define LED 12

Servo myservo;
Servo myservo2;
int pos = 0;
char val;

void setup(){
  myservo.attach(10);
  myservo2.attach(11);

  Serial.begin(115200);
}

void loop(){
  Serial.println("Bluetooth");

  val = Serial.read();
  Serial.println(val); // Default val = ÿ

  if (val == '1'){
    for(pos = 0; pos < 180; pos += 10) {
        myservo.write(pos);
        myservo2.write(pos);
        delay(15);
    }

    delay(1000);
  } else if (val == '0') {
    for(pos = 180; pos>=1; pos-=10) {
      myservo.write(pos);
      myservo2.write(pos);
      delay(15);
    }

    delay(1000);
  } else {
    delay(1000);
  }
}
