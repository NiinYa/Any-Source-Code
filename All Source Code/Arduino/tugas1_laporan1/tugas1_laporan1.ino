#define tombol A0
char pinsCount = 6;
int pins[] = {3, 5, 6, 9, 10, 11};
int val = 0;
int i;
void setup() {
  for (i = 0; i < pinsCount; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(tombol, INPUT_PULLUP);
}
void perulangan() {
  for (int j = 0; j <= 255; j++) {
    analogWrite(pins[i], j);
    delay(5);
  }
  for (int j = 255; j >= 0; j--) {
    analogWrite(pins[i], j);
    delay(5);
  }
}
void loop() {
  val = digitalRead(tombol);
  if (val == HIGH) {
    for (i = 0; i < pinsCount; i++) {
      perulangan();
    }
  }
  else if (val == LOW) {
    for (i = pinsCount - 1; i >= 0; i--) {
      perulangan();
    }
  }
}
