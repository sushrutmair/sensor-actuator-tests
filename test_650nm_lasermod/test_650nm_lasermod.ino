
#define LASER_PIN 22 //Dxx --->LASERMOD.S on a digital out

void setup() {
  // put your setup code here, to run once:
  pinMode(LASER_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LASER_PIN, HIGH);
  delay(5000);
  digitalWrite(LASER_PIN, LOW);
  delay(1200);

}
