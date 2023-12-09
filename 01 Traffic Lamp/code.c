// C++ code
//

#include<Servo.h>
Servo servo1;
Servo servo2;
  
void setup()
{
  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
}

int f1, f2, f3, f4;

void loop()
{
  f1 = analogRead(A0);
  f2 = analogRead(A1);
  f3 = analogRead(A2);
  f4 = analogRead(A3);
  servo1.write(f1);
  servo2.write(f3);
}