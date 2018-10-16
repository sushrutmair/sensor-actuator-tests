
#define LDR_SENSE_PIN 0
#define LDR_PWR_PIN     23

void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LDR_PWR_PIN, OUTPUT);
  digitalWrite(LDR_PWR_PIN, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(LDR_SENSE_PIN); //A0

  Serial.println(reading);

  delay(800);

}
