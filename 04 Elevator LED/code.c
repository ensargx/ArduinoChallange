// C++ code
//
void setup()
{
  for(int i = 2; i <= 6; i++)
  {
    pinMode(i, INPUT);
  }
  for(int i = 8; i <= 12; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void switchLed(int numLed)
{
  for(int i = 1; i <= numLed; i++)
  {
    digitalWrite(i + 7, HIGH);
  }
  for(int i = numLed; i <= 5; i++)
  {
    digitalWrite(i + 8, LOW);
  }
   return; 
}

void loop()
{
  int mode;
  for(int i = 2; i <= 6; i++)
  {
    mode = digitalRead(i);
    if (mode == 1)
      switchLed(i - 1);
  }
  delay(100);
}