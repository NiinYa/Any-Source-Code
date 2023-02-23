#define TL_RED 0
#define TL_YEL 1
#define TL_GRE 2
#define TL_STDBY 6
int state=0;
static unsigned long t_awal;
static unsigned long t_setelah;
static unsigned long t=1000;
void cek_lampu();
void state_0();
void state_1();
void state_2();
void state_3();
void setup() {
pinMode(TL_RED, OUTPUT);
pinMode(TL_YEL, OUTPUT);
pinMode(TL_GRE, OUTPUT);
pinMode(TL_STDBY, INPUT_PULLUP);
t_awal=millis();
}
void loop() {
t_setelah = millis()-t_awal;
switch(state){
case 0:
cek_lampu();
if(t_setelah > 0) {state = 1; t_awal = millis();}
break;
case 1:
state_1();
if(t_setelah > t) {state = 2; t_awal = millis();}
break;
case 2:
state_2();
if(t_setelah > t) {state = 3; t_awal = millis();}
break;
case 3:
state_3();
if(t_setelah > t) {state = 1; t_awal = millis();}
break;
}
}
void cek_lampu() {
digitalWrite(TL_RED, HIGH);
digitalWrite(TL_YEL, HIGH);
digitalWrite(TL_GRE, HIGH);
delay(500);
digitalWrite(TL_RED, LOW);
digitalWrite(TL_YEL, LOW);
digitalWrite(TL_GRE, LOW);
delay(500);
}
void state_1(){
digitalWrite(TL_RED, HIGH);
digitalWrite(TL_YEL, LOW);
digitalWrite(TL_GRE, LOW);
}
void state_2(){
digitalWrite(TL_RED, LOW);
digitalWrite(TL_YEL, LOW);
digitalWrite(TL_GRE, HIGH);
}
void state_3(){
digitalWrite(TL_RED, LOW);
digitalWrite(TL_YEL, HIGH);
digitalWrite(TL_GRE, LOW);
}
