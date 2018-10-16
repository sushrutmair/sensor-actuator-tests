
int velostatPwrPin = 2;//D2;
int potPwrPin = 3;//D3;
int veloVinPin = A0;

int AZeroVal = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(velostatPwrPin, OUTPUT);
  pinMode(potPwrPin, OUTPUT);
  pinMode(veloVinPin, INPUT);

  digitalWrite(velostatPwrPin, HIGH);
  digitalWrite(potPwrPin, HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

    AZeroVal = analogRead(veloVinPin);
    Serial.println(AZeroVal);

    delay(500);

}

