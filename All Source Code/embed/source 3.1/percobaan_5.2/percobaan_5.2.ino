#define debug 1
#define serialbufferSize 50
char inputBuffer[serialbufferSize];
int serialIndex = 0;
void setup()
{
Serial.begin(9600);
Serial.println("Hello, please ask me something");
Serial.println("type \"Hello\", \"Goodby\", \"web\" or \"dosomething\" or make up your own command");
Serial.println();
}
void loop()
{
if (CheckSerial()) DoCommand(inputBuffer);
}
boolean DoCommand(char * commandBuffer)
{
if (strstr(commandBuffer, "Hello")){
Serial.println("Hello back at you ");
}
else if (commandBuffer == "Goodby"){
Serial.println("Goodby back at you ");
}
else if (strcmp(commandBuffer , "dosomething")==0){
Serial.println("Like what ?? ");
}
else if (strstr(commandBuffer , "web")){
Serial.println("HTTP/1.1 200 OK");
Serial.println("Content-Type: text/html");
Serial.println("Connection: close");
Serial.println();
Serial.println("<!DOCTYPE html>");
Serial.println("<html><head><title>TEST</title></head>");
Serial.println("<body><h1>Hello from www.thebreadboard.ca</h1></body>");
Serial.println("</html>");
}
else {
Serial.print("I dont understand you \nYou said: ");
Serial.println(commandBuffer);
}
#if debug
Serial.print("Free Ram = "); Serial.println(freeRam(),DEC);
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
else if(serialIndex < serialbufferSize && lineFound ==false) {

inputBuffer[serialIndex++] = charBuffer;
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
return (int) &v - (__brkval == 0 ? (int) &__heap_start :(int) __brkval);
}
#endif
