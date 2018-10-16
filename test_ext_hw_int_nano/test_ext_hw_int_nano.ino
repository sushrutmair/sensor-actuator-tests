
#define INTR_PIN 2

volatile boolean g_bLED13On = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(INTR_PIN, INPUT);
  //pinMode(INTR_PIN, INPUT_PULLUP);

  digitalWrite(13, LOW);

  attachInterrupt(digitalPinToInterrupt(INTR_PIN), isr, CHANGE);

}

void isr()
{
  g_bLED13On = true;
}

boolean ManageInterrupts()
{
  byte oldSREG = SREG; //save current interrupt state

  noInterrupts(); //disable all interrupts so that it doesnt interfere with shared var access
  boolean bSetLEDState = g_bLED13On;

  SREG = oldSREG; //restore interrupt state

  return bSetLEDState;
}

void loop() {
  // put your main code here, to run repeatedly:
  if( ManageInterrupts() )
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
    g_bLED13On = false;
  }

}

