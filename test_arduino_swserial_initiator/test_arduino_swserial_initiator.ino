#include <SoftwareSerial.h>

SoftwareSerial mySerialInitiator(10,11);//Rx,Tx
/*
 *  note - we shall establish a protocol to understand things easily. For now, nano1.10-->nano2.11 and vice versa
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("starting...");

  mySerialInitiator.begin(9600);
  mySerialInitiator.println("Hello World from Initiator!");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerialInitiator.available() > 0 ) {
    Serial.println("something from resp. Echoing...");
    Serial.println(mySerialInitiator.read());
  }
}
