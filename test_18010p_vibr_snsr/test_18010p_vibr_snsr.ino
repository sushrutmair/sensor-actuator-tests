//Henry's Bench
//KY-002 Shock Sensor Tutorial

int shockPin = 10; // Use Pin 10 as our Input
int shockVal = HIGH; // This is where we record our shock measurement
boolean bAlarm = false;

unsigned long lastShockTime; // Record the time that we measured a shock

int shockAlarmTime = 500; // Number of milli seconds to keep the shock alarm high

unsigned long hitCount = 0;
int sensorVal = 0;

void setup ()
{
  Serial.begin(9600);
  pinMode (shockPin, INPUT) ; // input from the KY-002
}
void loop ()
{
  shockVal = digitalRead (shockPin) ; // read the value from our sensor
  sensorVal = analogRead(A0);
  //Serial.println(sensorVal);

  if (shockVal == LOW) // If we're in an alarm state
  {
    lastShockTime = millis(); // record the time of the shock
    // The following is so you don't scroll on the output screen
    if (!bAlarm) {
      Serial.print("HIT: ");
      bAlarm = true;
      hitCount++;
      Serial.print(sensorVal);
      Serial.print(" ");
      Serial.println(hitCount);
    }
  }
  else
  {
    if ( (millis() - lastShockTime) > shockAlarmTime  &&  bAlarm) {
      Serial.print("no hit: ");
      Serial.println(sensorVal);
      bAlarm = false;
    }
  }

  //delay(250);
}

