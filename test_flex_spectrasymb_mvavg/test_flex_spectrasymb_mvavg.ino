int flexSensorPin = A0; //analog pin 0

//for the 1st flex sensor I got, marked '1' in roman numeral on 'Top' side.

//for vdiv 33.6 kohms
//int minReading = 500;//531;//568;
//int maxReading = 750;//795;//809;

//for vdiv 47 kohms
int minReading = 542;//550;
int maxReading = 800;

const int winMA = 10;
int flexSensorReading[winMA] = { 0 };
int delayms = 2500 / winMA;
int maTmp = 0;
int incr = 0;

void initflex()
{
  //initial readings to prime for moving avg calculations...
  for (int x = 0; x < winMA; x++)
  {
    flexSensorReading[x] = analogRead(flexSensorPin);
    delay(50);
  }

  for (int y = 0; y < winMA; y++)
  {
    maTmp += flexSensorReading[y];
    //Serial.println(flexSensorReading[y]);
  }

  //Serial.println("-----------");
  int flexdeg = map(maTmp / winMA, minReading, maxReading, 180, 0);
  Serial.println(flexdeg);
}

void setup() {
  Serial.begin(9600);

  delay(500);
  initflex();

}

void DoFlexSnsrOps()
{
  incr++;
  if (incr > winMA)
  {
    incr = 1;
  }

  for (int x = 0; x < incr; x++)
  {
    flexSensorReading[x] = analogRead(flexSensorPin);
    //Serial.println(flexSensorReading[x]);
    //Serial.println("------------");
    delay(50);
  }

  long maTotal = 0;
  for (int y = 0; y < winMA; y++)
  {
    maTotal += flexSensorReading[y];
  }

  //Using map(), you can convert min, max to a range like 0-100.
  int flex0to180 = map(maTotal / winMA, minReading, maxReading, 180, 0);
  Serial.print(flex0to180); Serial.println(" degrees");
  
}

void loop() {

  DoFlexSnsrOps();
  delay(delayms); //just here to slow down the output for easier reading
}

