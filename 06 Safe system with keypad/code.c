// C++ code
//

#include <Keypad.h>

#define time_t unsigned long

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

time_t time_old = millis();
int state = 0;

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  kirmiziYak();
}

char sifre[16] = {'1', '2', '3'};
char input[16];
int idx = 0;

void sariYak()
{
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}

void yesilYak()
{
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void kirmiziYak()
{
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}


void loop()
{
  char key = keypad.getKey();// Read the key
  time_t delay = millis() - time_old;
  
  if(delay > 1500 && state == 1)
  {
    // STRCMP İLE KONTROL ET ŞİFRE DOGRU MU
    if(strcmp(sifre, input) == 0)
    {
      Serial.println("ACCESS GRANTED");
      state = 2;
      // LED YEŞİL
      yesilYak();
      for(int i = 0; i < 16; i++)
      {
        input[i] = 0;
      }
    }
    else
    {
      Serial.println("WTF");
      state = 0;
      for(int i = 0; i < 16; i++)
      {
        input[i] = 0;
      }
    // LEDI KIRIMIYA ÇEVİR
      kirmiziYak();
    }
  }
  
  if(key)
  {
    if(state == 0)
    {
      state = 1;
      idx = 1;
      input[0] = key;
      // LEDİ SARIYE ÇEVİR
      sariYak();
      time_old = millis();

    }
    else if(state == 1)
    {
      input[idx++] = key; 
    }
  }
  

}