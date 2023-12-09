// C++ code
//

#define SENSOR 2

int pir, state, gecis;

void setup()
{
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
}

void loop()
{
  pir = digitalRead(SENSOR);
  if (pir == HIGH && state == 0)
  {
    state = 1;
    Serial.print("Toplam gecis: ");
    Serial.println(++gecis);
  }
  if (pir == LOW && state == 1)
  {
    state = 0;
    Serial.write("Gecis yok.\n");
  }
}