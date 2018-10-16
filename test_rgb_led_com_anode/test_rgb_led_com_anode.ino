
/*
Adafruit Arduino - Lesson 3. RGB LED
 */
 
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

#define delayTime 1500 // fading time between colors

#define RGB_PWR 6 //RGB is Common Anode

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(RGB_PWR, OUTPUT);
  digitalWrite(RGB_PWR, HIGH);
}
void loop()
{
  setColor(255, 0, 0); // red
  delay(delayTime);
  setColor(0, 255, 0); // green
  delay(delayTime);
  setColor(0, 0, 255); // blue
  delay(delayTime);
  setColor(255, 255, 0); // yellow
  delay(delayTime);
  setColor(255, 255, 255); // white
  delay(delayTime);
}
void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

