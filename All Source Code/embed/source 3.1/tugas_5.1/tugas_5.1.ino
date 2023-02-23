#define debug 1
#define serialbufferSize 50
char inputBuffer[serialbufferSize];
int serialIndex = 0;
void setup()
{
  Serial.begin(115200);
  Serial.println("Hello, please enter the number between 1-20 to Turn ON the LED and Reset for Turn Off all LED");
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
  if (strstr(commandBuffer, "1")) {
    digitalWrite(0, HIGH);
  }
  else if (strstr(commandBuffer, "2")) {
    digitalWrite(1, HIGH);
  }
  else if (strstr(commandBuffer, "3")) {
    digitalWrite(2, HIGH);
  }
  else if (strstr(commandBuffer, "4")) {
    digitalWrite(3, HIGH);
  }
  else if (strstr(commandBuffer, "5")) {
    digitalWrite(4, HIGH);
  }
  else if (strstr(commandBuffer, "6")) {
    digitalWrite(5, HIGH);
  }
  else if (strstr(commandBuffer, "7")) {
    digitalWrite(6, HIGH);
  }
  else if (strstr(commandBuffer, "8")) {
    digitalWrite(7, HIGH);
  }
  else if (strstr(commandBuffer, "9")) {
    digitalWrite(8, HIGH);
  }
  else if (strstr(commandBuffer, "10")) {
    digitalWrite(9, HIGH);
  }
  else if (strstr(commandBuffer, "11")) {
    digitalWrite(10, HIGH);
  }
  else if (strstr(commandBuffer, "12")) {
    digitalWrite(11, HIGH);
  }
  else if (strstr(commandBuffer, "13")) {
    digitalWrite(12, HIGH);
  }
  else if (strstr(commandBuffer, "14")) {
    digitalWrite(13, HIGH);
  }
  else if (strstr(commandBuffer, "15")) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (strstr(commandBuffer, "16")) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  }
  else if (strstr(commandBuffer, "17")) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  else if (strstr(commandBuffer, "18")) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  else if (strstr(commandBuffer, "19")) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);

  }
  else if (strstr(commandBuffer, "20")) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
  else if (strstr(commandBuffer, "Reset")) {
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(0, LOW);
  }
  else {
    Serial.print("I don't understand what you said! \nYou said: ");
    Serial.println(commandBuffer);
  }
#if debug
  Serial.print("Memory kosong: ");
  Serial.println(freeRam(), DEC);
#endif
  return true;
}
boolean CheckSerial() {
  boolean lineFound = false;
  while (Serial.available() > 0) {
    char charBuffer = Serial.read();
    if (charBuffer == '\r') {
      inputBuffer[serialIndex] = 0;
      lineFound = (serialIndex > 0);
      serialIndex = 0;
    }
    else if (serialIndex < serialbufferSize && lineFound == false) {
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
  return (int) &v - (__brkval == 0 ? (int) &__heap_start :
                     (int)
                     __brkval);
}
#endif
