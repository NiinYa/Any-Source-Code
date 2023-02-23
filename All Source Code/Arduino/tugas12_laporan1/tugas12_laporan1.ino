#define tombol A0
char pinsCount = 6;
int pins[] = {3,5,6,9,10,11};
int val = 0;
int i;
int count = 0;

void setup() {
  for (int i = 0; i<pinsCount; i++){
    pinMode(pins[i], OUTPUT);
    }
  pinMode(tombol, INPUT_PULLUP);
}
void perulangan(int i){
  for (int j = 0; j <= 255; j++){
        analogWrite(pins[i], j);
        delay(5);
        }
      for (int j = 255; j >= 0; j--){
        analogWrite(pins[i], j);
        delay(5);
        }
}
void loop() {
  val = digitalRead(tombol);
  if (val == HIGH) {
    if (count== pinsCount) count = 0;
    perulangan(count);
    count++;
  }
    else if(val ==LOW){
      if (count == -1) count = pinsCount -1;
      perulangan(count);
      count--;
    }
  }
  
