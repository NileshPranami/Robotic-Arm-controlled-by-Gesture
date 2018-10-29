#include<SoftwareSerial.h>
#include<VarSpeedServo.h>
#include<BlynkSimpleSerialBLE.h>
#define BLYNK_PRINT Serial
VarSpeedServo myservo1,myservo2,myservo3,myservo4;
SoftwareSerial SwSerial(10,11);
char auth[]="a594506c698844b09bf9730b2673eb59";
SoftwareSerial SerialBLE(10,11);

BLYNK_WRITE(V1){
 
  int x=param[0].asFloat();
   Serial.println("getting x as "+x);
  x=map(x,-10,10,0,37);
  Serial.println("mapped value X as "+x);
  myservo1.write(x,20,true);
  Serial.println("Movement in X axis by "+x);
  
  int y=param[1].asFloat();
  Serial.println("getting y as "+y);
  y=map(y,-10,10,0,80);
  myservo2.write(y,20,true);
  Serial.println("Movement in Y axis by "+y);
  
  int z=param[2].asFloat();
  Serial.println("getting z as "+z);
  z=map(z,-10,10,5,170);
  myservo3.write(z,20,true);
  Serial.println("Movement in Z axis by "+z);
  }
/*  BLYNK_WRITE(V2) {
  int proximity = param.asInt();
  if (proximity) {
     myservo4.write(120,20,true);
      Serial.println("Claw open");
  } else {
     myservo4.write(15,20,true);
     Serial.println("Claw closed");
  }
}*/
void setup() {
  Serial.begin(9600);
 SerialBLE.begin(9600);
 Blynk.begin(SerialBLE,auth);
myservo1.attach(9);
myservo1.write(0,10,true);
myservo2.attach(8);
myservo2.write(0,10,true);
myservo3.attach(7);
myservo3.write(0,10,true);
myservo4.attach(6);
myservo4.write(20,10,true);
Serial.println("Network is connecting....");

}

void loop() {
  Blynk.run();

}
