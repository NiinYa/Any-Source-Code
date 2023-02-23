#define debug 1
#define serialbufferSize 50
#define progMemBuffer 128
char inputBuffer[serialbufferSize] ;
int serialIndex = 0;
enum {welcomeText0, webText0, webText1, webText2,errorText };
const char PROGMEM welcomeTxt_0[] = "Hello, please askmesomething\ntype ";
const char PROGMEM webTxt_0[] = "HTTP/1.1200OK\nContentType: text/html\nConnection: close\n";
const char PROGMEM webTxt_1[] ="<!DOCTYPEhtml><html><head><title>Hellofromwww.thebreadboard.ca</title></head><body>";
const char PROGMEM webTxt_2[] = "</body></html>\n";
const char PROGMEM errorTxt_0[] = "I dont understand you\nYousaid: ";
const char* const Txt_table[] PROGMEM ={ welcomeTxt_0,webTxt_0, webTxt_1, webTxt_2, errorTxt_0};
enum {web, q,w,e,r,t,y,u,i,o,p,a,s,d,f,g,h,j,k,l,z};
const char PROGMEM webCmd[] = "web";
const char PROGMEM aCmd[] = "q";
const char PROGMEM bCmd[] = "w";
const char PROGMEM cCmd[] = "e";
const char PROGMEM dCmd[] = "r";
const char PROGMEM eCmd[] = "t";
const char PROGMEM fCmd[] = "y";
const char PROGMEM gCmd[] = "u";
const char PROGMEM hCmd[] = "i";
const char PROGMEM iCmd[] = "o";
const char PROGMEM jCmd[] = "p";
const char PROGMEM kCmd[] = "a";
const char PROGMEM lCmd[] = "s";
const char PROGMEM mCmd[] = "d";
const char PROGMEM nCmd[] = "f";
const char PROGMEM oCmd[] = "g";
const char PROGMEM pCmd[] = "h";
const char PROGMEM qCmd[] = "j";
const char PROGMEM rCmd[] = "k";
const char PROGMEM sCmd[] = "l";
const char PROGMEM tCmd[] = "z";
const char* const Cmd_table[] PROGMEM = {webCmd, qCmd, wCmd, eCmd, rCmd, tCmd, yCmd, uCmd, iCmd, oCmd,pCmd, aCmd, sCmd, dCmd, fCmd, gCmd, hCmd, jCmd, kCmd, lCmd,zCmd };
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
if (strcmp(searchText, getStringfromProgMem(Cmd_table startCount)) == 0)
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
Serial.print(getStringfromProgMem(Txt_table,welcomeText0));
Serial.print ("q,w,e,r,t,y,u,i,o,p,a,s,d,f,g,h,j,k,l,z \n");
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
void loop()
{
if (CheckSerial()) DoCommand(inputBuffer);
}
boolean DoCommand(char * commandBuffer)
{
int cmdID = findCommand(commandBuffer);
switch ( cmdID)
{
case web : processWebCmd("<H1>Test1</H1>"); break;
case q : digitalWrite(0, HIGH); break;
case w : digitalWrite(1, HIGH); break;
case e : digitalWrite(2, HIGH); break;
case r : digitalWrite(3, HIGH); break;
case t : digitalWrite(4, HIGH);break;
case y : digitalWrite(0, LOW); break;
case u : digitalWrite(1, LOW); break;
case i : digitalWrite(2, LOW); break;
case o : digitalWrite(3, LOW); break;
case p : digitalWrite(4, LOW); break;
case a : digitalWrite(5, HIGH); break;
case s : digitalWrite(7, HIGH);break;
case d : digitalWrite(9, HIGH); break;
case f : digitalWrite(11, HIGH); break;
case g : digitalWrite(13, HIGH); break;
case h : digitalWrite(6, HIGH); break;
case j : digitalWrite(8, HIGH); break;
case k : digitalWrite(10, HIGH); break;
case l : digitalWrite(12, HIGH); break;
case z : digitalWrite(13, HIGH); break;
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
while (Serial.available() > 0) {
char charBuffer = Serial.read();
if (charBuffer == '\r') {
inputBuffer[serialIndex] = 0;
lineFound = (serialIndex > 0);
serialIndex=0;
}
else if (serialIndex < serialbufferSize && lineFound ==false) {
inputBuffer[serialIndex++] = charBuffer;
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
void processWebCmd(char* webText)
{
Serial.print(getStringfromProgMem(Txt_table, webText0));
Serial.print(getStringfromProgMem(Txt_table, webText1));
Serial.print(webText);
Serial.print(getStringfromProgMem(Txt_table, webText2));
}
