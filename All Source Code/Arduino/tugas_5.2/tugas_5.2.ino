#include <avr/pgmspace.h>
#define debug 1
#define serialbufferSize 50
#define progMemBuffer 128

char inputBuffer[serialbufferSize];
int serialIndex = 0;

enum {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20};
const char PROGMEM a1Cmd[] = "1";
const char PROGMEM a2Cmd[] = "2";
const char PROGMEM a3Cmd[] = "3";
const char PROGMEM a4Cmd[] = "4";
const char PROGMEM a5Cmd[] = "5";
const char PROGMEM a6Cmd[] = "6";
const char PROGMEM a7Cmd[] = "7";
const char PROGMEM a8Cmd[] = "8";
const char PROGMEM a9Cmd[] = "9";
const char PROGMEM a10Cmd[] = "10";
const char PROGMEM a11Cmd[] = "11";
const char PROGMEM a12Cmd[] = "12";
const char PROGMEM a13Cmd[] = "13";
const char PROGMEM a14Cmd[] = "14";
const char PROGMEM a15Cmd[] = "15";
const char PROGMEM a16Cmd[] = "16";
const char PROGMEM a17Cmd[] = "17";
const char PROGMEM a18Cmd[] = "18";
const char PROGMEM a19Cmd[] = "19";
const char PROGMEM a20Cmd[] = "20";
const char* const Cmd_table[] PROGMEM = {a1Cmd, a2Cmd,
                                         a3Cmd, a4Cmd, a5Cmd, a6Cmd, a7Cmd, a8Cmd, a9Cmd,
                                         a10Cmd, a11Cmd, a12Cmd, a13Cmd, a14Cmd, a15Cmd, a16Cmd, a17Cmd, a18Cmd, a19Cmd,
                                         a20Cmd
                                        };
int cmdCount = sizeof(Cmd_table) / sizeof(Cmd_table[0]);
char buffer[progMemBuffer];
char* getStringfromProgMem(const char* const Table[], int i)
{
  strcpy_P(buffer, (char*)pgm_read_word(&(Table[i])));
  return buffer;
};
int findCommand(char* searchText)
{
  int startCount = 0;
  int foundIndex = -1; // -1 = not found
  while (startCount < cmdCount)
  {
    if (strcmp(searchText, getStringfromProgMem(Cmd_table,
               startCount)) == 0)
    {
      foundIndex = startCount;
      break;
    }
    startCount++;
  }
  return foundIndex;
}

void setup()
{
  Serial.begin(9600);
  delay(200);
  Serial.println("Hello, please enter the number between 1-20 to Turn ON the LED and Reset for Turn Off all LED");
  Serial.println();
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
}
void loop() {
  if (CheckSerial()) DoCommand(inputBuffer);
}
boolean DoCommand(char* commandBuffer) {
  int cmdID = findCommand(commandBuffer);
  switch ( cmdID) {
    case 1: digitalWrite(0, HIGH); break;
    case 2: digitalWrite(1, HIGH); break;
    case 3: digitalWrite(2, HIGH); break;
    case 4: digitalWrite(3, HIGH); break;
    case 5: digitalWrite(4, HIGH); break;
    case 6: digitalWrite(5, HIGH); break;
    case 7: digitalWrite(6, HIGH); break;
    case 8: digitalWrite(7, HIGH); break;
    case 9: digitalWrite(8, HIGH); break;
    case 10: digitalWrite(9, HIGH); break;
    case 11: digitalWrite(10, HIGH); break;
    case 12: digitalWrite(11, HIGH); break;
    case 13: digitalWrite(12, HIGH); break;
    case 14: digitalWrite(13, HIGH); break;
    case 15: digitalWrite(1, HIGH); digitalWrite(2, HIGH); break;
    case 16: digitalWrite(1, HIGH);digitalWrite(2, HIGH);digitalWrite(3, HIGH); break;
    case 17: digitalWrite(1, HIGH);digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH); break;
    case 18: digitalWrite(1, HIGH);digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH);digitalWrite(5, HIGH); break;
    case 19: digitalWrite(1, HIGH);digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH);digitalWrite(5, HIGH);digitalWrite(6, HIGH); break;
    case 20: digitalWrite(1, HIGH);digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH);digitalWrite(5, HIGH);digitalWrite(6, HIGH);digitalWrite(7, HIGH); break;
    default: {
        Serial.print("I don't understand what you said! \nYou said: ");
        Serial.println(commandBuffer);
        break;

      }
  }
#if debug
  Serial.print("Free Ram = "); Serial.println(freeRam(), DEC);
#endif
  return true;
}
boolean CheckSerial()
{
boolean lineFound = false;
// if there's any serial available, read it:
while (Serial.available() > 0) {
//Read a character as it comes in:
//currently this will throw away anything after the buffer isfull or the \n is detected
char charBuffer = Serial.read();
if (charBuffer == '\r') {
inputBuffer[serialIndex] = 0; // terminate the string
lineFound = (serialIndex > 0); // only good if we sent more than an empty line
serialIndex=0; // reset for next line of data
}
else if(serialIndex < serialbufferSize && lineFound ==
false) {
/*Place the character in the string buffer:*/
inputBuffer[serialIndex++] = charBuffer; // auto increment index
}
}
return lineFound;
}
#if debug
int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start :
                     (int)__brkval);
}
#endif
