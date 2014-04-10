// Bluetooth Serial Communication

#define LED 12

char val;

void setup(){
 pinMode(LED,OUTPUT); 
 Serial.begin(115200);
}

void loop(){
  Serial.println("Bluetooth");
  Serial.println(val); // Default val = ÿ
  val = Serial.read();
  
  if (val == '1'){
     digitalWrite(LED, HIGH);
     delay(1000);
  } 
  else if (val == '0'){
     digitalWrite(LED, LOW);
     delay(1000);
  } 

  else {
    delay(1000);
  }
}
