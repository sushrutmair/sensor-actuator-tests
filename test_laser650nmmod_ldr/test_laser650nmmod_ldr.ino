
#define LASER_PIN      22 //Dxx--->LASERMOD.S
#define LDR_PWR       23 //Dxx
int LDR_SENSE = A0;

#define MA_WIN 3
int ldrReading[MA_WIN] = {0};
int totalldrReading = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LASER_PIN, OUTPUT);
  pinMode(LDR_PWR, OUTPUT);
  //pinMode(LDR_SENSE, INPUT);
  digitalWrite(LDR_PWR, HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LASER_PIN, HIGH);
  for (int i = 0; i < MA_WIN; i++)
  {
    ldrReading[i] = analogRead(LDR_SENSE);
    //Serial.println(ldrReading);
    delay(12);
  }

  for (int x = 0; x < MA_WIN; x++)
  {
    totalldrReading += ldrReading[x];
  }

  //print the moving average to console
  Serial.println(totalldrReading / MA_WIN);
  totalldrReading = 0;

  /*
    digitalWrite(LASER_PIN, LOW);
    for (int x = 0; x < 10; x++)
    {
      ldrReading = analogRead(LDR_SENSE);
      Serial.println(ldrReading);
      delay(500);
    }
  */

}

