// Servo Motor Control
#include <Servo.h>

char blueVal;
int leftElbowAngle = 10;
int rightElbowAngle= 20;
int leftShoulderXAngle = 30;
int rightShoulderXAngle= 40;
int leftShoulderZAngle=50;
int rightShoulderZAngle=60;
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
      //moveServos(leftElbowAngle, leftShoulderXAngle, leftShoulderZAngle, rightElbowAngle, rightShoulderXAngle, rightShoulderZAngle); 
      moveServos(0,0,0,0,0,0);
      
      Serial.println("Move");
      delay(1000);
   }
   else if (blueVal == '3'){
      // Move Servos to specified angles
      moveServos(90,90,90,90,90,90); 
      Serial.println("Movement 3");
      delay(1000);
   }
   else {
    delay(200);
   }
}

// Home Position
int homePose(){
  pos = 70;
  leftElbow.write(pos);
  rightElbow.write(pos);
  leftShoulderX.write(pos); 
  rightShoulderX.write(pos);
  leftShoulderZ.write(pos);
  rightShoulderZ.write(pos);
}

// Move Servo to Angles
int moveServos(int LEA, int LSAX, int LSAZ, int REA, int RSAX, int RSAZ){

      leftElbow.write(LEA);         
  
      rightElbow.write(REA);         

      leftShoulderX.write(LSAX);         
  
      rightShoulderX.write(RSAX);         
     
      leftShoulderZ.write(LSAZ);         
   
      rightShoulderZ.write(RSAZ);         
}
