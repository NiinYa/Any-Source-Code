#define TL_RED 0
#define TL_YEL 1
#define TL_GRE 2
#define TL_STDBY 6
void cek_lampu();
void setup() {
pinMode(TL_RED,OUTPUT);
pinMode(TL_YEL,OUTPUT);
pinMode(TL_GRE,OUTPUT);
pinMode(TL_STDBY,INPUT_PULLUP);
cek_lampu();
}
void loop() {
digitalWrite(TL_RED,HIGH);
digitalWrite(TL_YEL,LOW);
digitalWrite(TL_GRE,LOW);
delay(1000);
digitalWrite(TL_RED,LOW);
digitalWrite(TL_YEL,LOW);
digitalWrite(TL_GRE,HIGH);
delay(1000);
digitalWrite(TL_RED,LOW);
digitalWrite(TL_YEL,HIGH);
digitalWrite(TL_GRE,LOW);
delay(1000);
}
void cek_lampu(){
digitalWrite(TL_RED,HIGH);
digitalWrite(TL_YEL,HIGH);
digitalWrite(TL_GRE,HIGH);
delay(500);
digitalWrite(TL_RED,LOW);
digitalWrite(TL_YEL,LOW);
digitalWrite(TL_GRE,LOW);
delay(500);
}
