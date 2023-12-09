// C++ code
//

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'c','0','=','/'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);
}

int state = 0;
double res;
double in;
double hold;
char islem;

void loop()
{
  // A = +
  // B = -
  // C = *
  // D = /
  // * = clear
  // # = =
  char key = keypad.getKey();// Read the key
  if(key)
  {
    if(key >= '0' && key <= '9')
    {
      in = in * 10;
      in += key - '0';
    }
    switch(key)
    {
    case '+':
      break;
    case '-':
    case '*':
    case '/':
      islem = key;
      hold = in;
      in = 0;
      break;
    case 'c':
      islem = 0;
      hold = 0;
      in = 0;
      res = 0;
    case '=':
      if(islem == '+')
        res = hold + in;
      else if(islem == '-')
        res = hold - in;
      else if(islem == '*')
        res = hold * in;
      else if(islem == '/')
        res = hold / in;
      Serial.print("Cevap :");
      Serial.println(res);
      break;
    }
  }
}