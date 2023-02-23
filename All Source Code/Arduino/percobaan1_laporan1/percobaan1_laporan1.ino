char pinsCount = 6;
int pins[] = {3,5,6,9,10,11};
void setup() {
for (int i = 0; i<pinsCount; i++){
  pinMode(pins[i], OUTPUT);
}
}
void loop() {
for (int i = 0; i < pinsCount; i++){
digitalWrite(pins[i], HIGH);
delay(1000);
digitalWrite(pins[i], LOW);
}
}
