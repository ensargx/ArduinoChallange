// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

int isLightsOn = false;

void lightsOn()
{
  if(isLightsOn)
    return;
  Serial.write("Turning lights on\n");
  digitalWrite(LED_BUILTIN, HIGH);
  isLightsOn = true;
}

void lightsOff()
{
  if(!isLightsOn)
    return;
  Serial.write("Turning lights off\n");
  digitalWrite(LED_BUILTIN, LOW);
  isLightsOn = false;
}

void loop() {
  int analogValue = analogRead(A0);
  
  if (analogValue < 10)
    lightsOn();
  else
    lightsOff();

  delay(500);
}
