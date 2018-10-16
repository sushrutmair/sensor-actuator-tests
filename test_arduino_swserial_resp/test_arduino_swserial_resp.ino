#include <SoftwareSerial.h>

SoftwareSerial mySerialResp(10,11);//Rx,Tx
/*
 *  note - we shall establish a protocol to understand things easily. For now, nano1.10-->nano2.11 and vice versa
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("starting...");

  mySerialResp.begin(9600);
  //mySerialResp.println("Hello World from 1!");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerialResp.available() > 0 ) {
    Serial.println("Something from Initiator. Echoing...");
    Serial.write(mySerialResp.read());
  }

  delay(1500);
}

