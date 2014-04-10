// Servo Motor Control
#include <Servo.h>
#define LED 12

char blueVal;
int leftElbowAngle = 30;
int rightElbowAngle= 30;
int leftShoulderXAngle = 30;
int rightShoulderXAngle= 30;
int leftShoulderZAngle=30;
int rightShoulderZAngle=30;
int pos = 0;

Servo leftElbow; //L3
Servo leftShoulderX;//L1
Servo leftShoulderZ; // L2
Servo rightElbow; // R3
Servo rightShoulderX;
Servo rightShoulderZ;

// Void Setup
void setup(){
 leftElbow.attach(10);
 leftShoulderX.attach(11);
 leftShoulderZ.attach(12);
 rightElbow.attach(13); // R3
 rightShoulderX.attach(8); //R1
 rightShoulderZ.attach(9); //R2
 Serial.begin(115200);
}

// Void Loop
void loop(){
  Serial.println("Bluetooth");
  blueVal = Serial.read();
  Serial.println(blueVal); // Default val = ÿ
   
   if (blueVal == '1'){
      // Go Home
      homePose();
      Serial.println("Home");
      delay(1000);
   } 
   else if (blueVal == '2'){
      // Move Servos to specified angles
      moveServos(leftElbowAngle, leftShoulderXAngle, leftShoulderZAngle, rightElbowAngle, rightShoulderXAngle, rightShoulderZAngle); 
      Serial.println("Move");
      delay(1000);
   }
   else {
    delay(500);
   }
}

// Home Position
int homePose(){
  pos = 50;
  leftElbow.write(pos);
  rightElbow.write(pos);
  leftShoulderX.write(pos); 
  rightShoulderX.write(pos);
  leftShoulderZ.write(pos);
  rightShoulderZ.write(pos);
}

// Move Servo to Angles
int moveServos(int LEA, int LSAX, int LSAZ, int REA, int RSAX, int RSAZ){
  for(pos = 0; pos < LEA; pos += 3){  
      leftElbow.write(pos);         
   }
   for(pos = 0; pos < REA; pos += 3){  
      rightElbow.write(pos);         
   }
   for(pos = 0; pos < LSAX; pos += 3){  
      leftShoulderX.write(pos);         
  }
   for(pos = 0; pos < RSAX; pos += 3){  
      rightShoulderX.write(pos);         
   }
   for(pos = 0; pos < LSAZ; pos += 3){  
      leftShoulderZ.write(pos);         
   }
   for(pos = 0; pos < RSAZ; pos += 3){  
      rightShoulderZ.write(pos);         
   }
}


