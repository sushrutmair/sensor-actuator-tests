//A sketch to demonstrate the tone() function

/*
 * You can’t use tone() while also using analogWrite() on pins 3 or 11. If you do – you get some whacky results – neither will work like you expect.
 * That’s because the tone() function uses the same built in timer that analogWrite() does for pins 3 and 11. It’s worth trying just hear the weird noises. 
 * 
 * You cannot generate a tone lower than 31 HZ. You can pass values 31 and less to the tone() function, but it doesn’t mean you will get a good representation of it.
 * 
 * The tone() function cannot be used by two separate pins at the same time. Let’s say you have two separate piezo speakers, each on a different pin.
 * You can’t have them both play at the same time. One has to be on, and then the other. Furthermore, before you can have the other pin use the tone() function,
 * you must call the noTone() function and “turn off” the tone from the previous pin.
 */


//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int piezoPin = 9;

void setup() {

}//close setup

void loop() {
  basicPlay();
}

void basicPlay()
{
  /*Tone needs 2 arguments, but can take three
    1) Pin#
    2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
    3) Duration - how long teh tone plays
  */
  tone(piezoPin, 5000, 500);
  delay(350);
  tone(piezoPin, 1000, 500);
  delay(350);
}

