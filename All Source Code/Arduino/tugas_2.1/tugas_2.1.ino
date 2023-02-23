#define TL_RED 0
#define TL_YEL 1
#define TL_GRE 2
#define CL_RED 8
#define CL_GRE 9
#define BTN 10
#define DITEKAN 0
#define DILEPAS 1
int state = 0;
int standby = DILEPAS; 
static unsigned long t = 1000;
static unsigned long t_awal;
static unsigned long t_setelah;
void cek_lampu();
void state_1();
void state_2();
void state_3();
void state_4();
void state_5();
void state_6();
void state_7();
void setup()
{
 pinMode(TL_RED, OUTPUT);
 pinMode(TL_YEL, OUTPUT);
 pinMode(TL_GRE, OUTPUT);
 pinMode(CL_RED, OUTPUT);
 pinMode(CL_GRE, OUTPUT);
 pinMode(BTN, INPUT_PULLUP);
 t_awal = millis();
}
void loop()
{
 t_setelah = millis() - t_awal;
 standby = digitalRead(BTN);
 switch(state)
 {
 case 0:
 cek_lampu();
 if(t_setelah > t) {state = 1; t_awal = millis();}
 break;
 case 1:
 state_1();
 if(standby == DITEKAN) {
 state = 4;
 t_awal = millis();
 }
 if(t_setelah > t) {state = 2; t_awal = millis();}
 break;
 case 2:
 state_2();
 if(standby == DITEKAN) {
 state = 4;
 t_awal = millis();
 }
 if(t_setelah > t) {state = 3; t_awal = millis();
 }
 break;
 case 3:
 state_3();
 if(standby == DITEKAN) {state = 4;t_awal =millis();}
 if(t_setelah > t) {state = 1;t_awal = millis();}
 break;
 case 4:
 state_4();
 if(t_setelah > t) {state = 5;t_awal = millis();}
 break;
 case 5:
 state_5();
 if(t_setelah > t) {state = 6;t_awal = millis();}
 break;
 case 6:
 state_6();
 if(t_setelah > t) {state = 7;t_awal = millis();}
 break;
case 7:
 state_7();
 if(t_setelah > t) {state = 1;t_awal = millis();}
 break;
 }
}
void cek_lampu()
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, HIGH);
 digitalWrite(TL_GRE, HIGH);
 digitalWrite(CL_RED, HIGH);
 digitalWrite(CL_GRE, HIGH);
 delay(500);
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(CL_RED, LOW);
 digitalWrite(CL_GRE, LOW);
 delay(500);
}
void state_1() 
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(CL_RED, HIGH);
 digitalWrite(CL_GRE, LOW);
}
void state_2() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, HIGH);
 digitalWrite(CL_RED, HIGH);
 digitalWrite(CL_GRE, LOW);
}
void state_3() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, HIGH);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(CL_RED, HIGH);
 digitalWrite(CL_GRE, LOW);
}
void state_4() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, HIGH);
digitalWrite(TL_GRE, LOW);
 digitalWrite(CL_RED, HIGH);
 digitalWrite(CL_GRE, LOW);
}
void state_5() 
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(CL_RED, HIGH);
 digitalWrite(CL_GRE, LOW);
}
void state_6() 
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(CL_RED, LOW);
 digitalWrite(CL_GRE, HIGH);
}
void state_7() 
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(CL_RED, LOW);
 for(int i = 0; i < 3; i++){
 digitalWrite(CL_GRE, HIGH);
 delay(300);
 digitalWrite(CL_GRE, LOW);
 delay(300);
 }
}
