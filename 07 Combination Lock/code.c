// C++ code
//
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  Serial.begin(9600);
}

int pattern[6] = {1, 3, 2, 4, 6, 5};
int ans[6];
int idx;

void reset()
{
  Serial.println("reseting");
  for(int i = 0; i < 6; i++)
    ans[i] = 0;

  for(int i = 2; i < 10; i++)
    digitalWrite(i, LOW);
  
  idx = 0;
  
  return;
}

void openLED(int ledNum)
{
  digitalWrite(ledNum+13, HIGH);
}

int checkValid(int x)
{
  for(int i = 0; i < 6; i++)
  {
    if(ans[i] == x)
      return 0;
  }
  return 1;
}

int getInput()
{
  int in = 0;
  while(true)
  {
    for(int i = 2; i < 8; i++)
    {
      if(digitalRead(i) == LOW)
      {
        in = i - 1;
        if(checkValid(in))
          return in;
      }
    }
  }
}

void loop()
{
  Serial.println(idx);
  if(idx < 6)
  {
    int input = getInput();
    ans[idx++] = input;
    openLED(input);
  }
  else
  {
    int dogru = 1;
    for(int i = 0; i < 6; i++)
    {
      if(ans[i] != pattern[i])
        dogru = 0;
    }
    if(dogru)
    {
      Serial.println("OLDU");
      digitalWrite(9, HIGH);
      delay(5000);
      reset();
    }
    else
    {
      Serial.println("OLMADI");
      digitalWrite(8, HIGH);
      delay(5000);
      reset();
    }
  }
  
}