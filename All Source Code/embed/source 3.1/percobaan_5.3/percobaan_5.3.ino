#include <avr/pgmspace.h>
#define debug 1
#define serialbufferSize 50
#define progMemBuffer 128
char inputBuffer[serialbufferSize] ;
int serialIndex = 0;
enum {welcomeText0, webText0, webText1, webText2, errorText,
      helloReply, goodbyReply, dosomethingReply
     };
const char PROGMEM welcomeTxt_0[] = "Hello, please ask me something\ntype \"Hello\", \"Goodby\", \"web\" or\"dosomething\"\n";
const char PROGMEM webTxt_0[] = "HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: close\n";
const char PROGMEM webTxt_1[] = "<!DOCTYPE html><html><head><title>Hello from www.thebreadboard.ca</title></head><body>";
const char PROGMEM webTxt_2[] = "</body></html>\n";
const char PROGMEM errorTxt_0[] = "I dont understand you \nYou said: ";
const char PROGMEM helloRepTxt_0[] = "Hello back at you ";
const char PROGMEM goodbyRepTxt_0[] = "Goodby back at you ";
const char PROGMEM dosomethingRepTxt_0[] = "Like what?";
const char* const Txt_table[] PROGMEM = {welcomeTxt_0, webTxt_0, webTxt_1, webTxt_2, errorTxt_0, helloRepTxt_0, goodbyRepTxt_0, dosomethingRepTxt_0};
enum {hello, goodby, dosomething, web};
const char PROGMEM helloCmd[] = "Hello";
const char PROGMEM goodbyCmd[] = "Goodby";
const char PROGMEM dosomethingCmd[] = "dosomething";
const char PROGMEM webCmd[] = "web";
const char* const Cmd_table[] PROGMEM = {helloCmd, goodbyCmd, dosomethingCmd, webCmd};
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
    if (strcmp(searchText, getStringfromProgMem(Cmd_table, startCount)) == 0)
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
  Serial.print(getStringfromProgMem(Txt_table, welcomeText0));
}
void loop()
{
  if (CheckSerial()) DoCommand(inputBuffer);
}
boolean DoCommand(char * commandBuffer)
{
  int cmdID = findCommand(commandBuffer);
  switch ( cmdID)
  {
    case hello :
      Serial.println(getStringfromProgMem(Txt_table, helloReply)); break;
    case goodby :
      Serial.println(getStringfromProgMem(Txt_table, goodbyReply)); break;
    case dosomething :
      Serial.println(getStringfromProgMem(Txt_table, dosomethingReply));
      break;
    case web : processWebCmd("<H1>Test1</H1>"); break;
    default : {
        Serial.print(getStringfromProgMem(Txt_table, errorText));
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
    //currently this will throw away anything after the buffer is full or the \n is detected
    char charBuffer = Serial.read();

    if (charBuffer == '\r') {
      inputBuffer[serialIndex] = 0; // terminate the string
      lineFound = (serialIndex > 0); // only good if we sent more than an empty line
      serialIndex = 0; // reset for next line of data
    }
    else if (serialIndex < serialbufferSize && lineFound == false) {
      /*Place the character in the string buffer:*/
      inputBuffer[serialIndex++] = charBuffer; // auto increment index
    }
  }
  return lineFound;
}
#if debug
// check free ram
int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int)
                     __brkval);
}
#endif
void processWebCmd(char* webText)
{
  Serial.print(getStringfromProgMem(Txt_table, webText0));
  Serial.print(getStringfromProgMem(Txt_table, webText1));
  Serial.print(webText);
  Serial.print(getStringfromProgMem(Txt_table, webText2));
}
