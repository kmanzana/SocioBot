// Servo Motor Control
#include <Servo.h>

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
 Serial.begin(9600);
}

// Void Loop
void loop(){
  //Serial.println("Bluetooth");
  blueVal = Serial.read();
  //Serial.println(blueVal); // Default val = ÿ
   Serial.println("Void Loop");
   
   if (blueVal == '1'){
      // Go Home
      Serial.println("Home");
      homePose();
      delay(1000);
   } 
   else if (blueVal == '2'){
      // Move Servos to specified angles
      Serial.println("Move");
      moveServos(leftElbowAngle, leftShoulderXAngle, leftShoulderZAngle, rightElbowAngle, rightShoulderXAngle, rightShoulderZAngle); 
      delay(1000);
   }
   else {
    delay(200);
   }
}


// ---- Functions ---- //

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

// Move Servos to Angles
int moveServos(int LEA, int LSAX, int LSAZ, int REA, int RSAX, int RSAZ){

      leftElbow.write(LEA);         
  
      rightElbow.write(REA);         

      leftShoulderX.write(LSAX);         
  
      rightShoulderX.write(RSAX);         
     
      leftShoulderZ.write(LSAZ);         
   
      rightShoulderZ.write(RSAZ);         
}
