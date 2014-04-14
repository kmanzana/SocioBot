// Further modification is needed for the Social Robot Project
// Updated: April 13, 2014
#include <Servo.h>
Servo leftElbow; //L3
Servo leftShoulderX;//L1
Servo leftShoulderZ; // L2
Servo rightElbow; // R3
Servo rightShoulderX;
Servo rightShoulderZ;


int state = 0;
int valOne;
int valTwo;
int valThree;
int valFour;
int valFive;
int valSix;
char serialVal;
String serialString, servoOne, servoTwo, servoThree, servoFour, servoFive, servoSix;

void setup() {   
 leftElbow.attach(10);
 leftShoulderX.attach(11);
 leftShoulderZ.attach(12);
 rightElbow.attach(13); // R3
 rightShoulderX.attach(8); //R1
 rightShoulderZ.attach(9); //R2  
  
  Serial.begin(115200);  
}// end of setup


void loop() {
  switch(state){
    case 0:
        serialRead();
        Serial.println("Serial Read State");
        delay(2000);
        state = 1;
    break;
    
    
    case 1:
      // Home Position
      moveServos(90, 90, 90, 90, 90, 90);
      serialRead();// initialize serial read function
      if(serialString.length() > 17 ){
              state = 2;
      }  
    break;
    
    case 2:
        subStrings();
        delay(200);
        state = 3;
    break;
    
    case 3:
         string2IntConvert();
         delay(200);
        state = 4;
    break;
    
    case 4:// print values state
        serialPrint();//prints all the values
        moveServos(valOne, valTwo, valThree, valFour, valFive, valSix);
        delay(200);
        state = 1;
    break;
    
  }// end of switch
}// end of loop




// Functions
int string2IntConvert(){
    valOne = atoi(servoOne.c_str());
    valTwo = atoi(servoTwo.c_str());
    valThree = atoi(servoThree.c_str());
    valFour = atoi(servoFour.c_str());
    valFive = atoi(servoFive.c_str());
    valSix = atoi(servoSix.c_str());
    serialString = "";// reset serialString so it can cycle back through with new numbers
}


void serialRead() {
 while(Serial.available()){
     delay(1);
       if(Serial.available() > 0) {
          serialVal = Serial.read();
          serialString += serialVal;    
        } // end of if serial.available
      }// end of while 
}

void subStrings(){
    servoOne = serialString.substring(0,3);
    servoTwo = serialString.substring(3,6);
    servoThree = serialString.substring(6,9);
    servoFour = serialString.substring(9,12);
    servoFive = serialString.substring(12,15);
    servoSix = serialString.substring(15,18);
}

void serialPrint(){
    Serial.print("Servo #1: ");
    Serial.println(valOne);
    delay(10);
    Serial.print("Servo #2: ");
    Serial.println(valTwo);
    delay(10);
    Serial.print("Servo #3: ");
    Serial.println(valThree);
    delay(10);
    Serial.print("Servo #4: ");
    Serial.println(valFour);
    delay(10);
    Serial.print("Servo #5: ");
    Serial.println(valFive);
    delay(10);
    Serial.print("Servo #6: ");
    Serial.println(valSix);
    delay(10);
}

int moveServos(int LEA, int LSAX, int LSAZ, int REA, int RSAX, int RSAZ){
    leftElbow.write(LEA);         
    rightElbow.write(REA);         
    leftShoulderX.write(LSAX);         
    rightShoulderX.write(RSAX);         
    leftShoulderZ.write(LSAZ);         
    rightShoulderZ.write(RSAZ);         
}
