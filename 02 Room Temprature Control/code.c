// C++ code
//
#define SENSOR A0

int sensorIn = 0;
int temp = 0;

void setup()
{
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorIn = analogRead(SENSOR);
  temp = (double)sensorIn / 1024;
  temp = temp * 5;
  temp = temp - 0.5;
  temp = temp * 100;
  Serial.print("Current Temperature: ");
  Serial.println(temp);
}