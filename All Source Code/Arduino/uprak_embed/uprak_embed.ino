#define TL_RED 1
#define TL_YEL 0
#define TL_GRE 2
#define TL_BLU 6
#define TL_ORG 8
#define TL_PRU 11
#define PB_ONE 3
#define PB_TWO 5
#define PB_TRHEE 9
#define PB_FOUR 10
#define PUSH 0
#define FREE 1

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
void state_8();
void state_9();
void setup()
{
 pinMode(TL_RED, OUTPUT);
 pinMode(TL_YEL, OUTPUT);
 pinMode(TL_GRE, OUTPUT);
 pinMode(TL_BLU, OUTPUT);
 pinMode(TL_ORG, OUTPUT);
 pinMode(TL_PRU, OUTPUT);
 pinMode(PB_ONE, INPUT_PULLUP);
 pinMode(PB_TWO,INPUT_PULLUP );
 pinMode(PB_THREE,INPUT_PULLUP );
 pinMode(PB_FOUR,INPUT_PULLUP );
 t_awal = millis();
}
void loop()
{
  cek_lampu();
  
 state_1();
 
 state_2();
 
 state_3();
 
 state_4();
 
 state_5();
 
 state_6();
 
 state_7();

 state_8();

 state_9();
 }

void cek_lampu()
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, HIGH);
 digitalWrite(TL_GRE, HIGH);
 digitalWrite(TL_BLU, HIGH);
 digitalWrite(TL_ORG, HIGH);
 digitalWrite(TL_PRU, HIGH);
 delay(500);
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
 delay(500);
}
void state_1() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, HIGH);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
}
void state_2() 
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
}
void state_3() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, HIGH);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
}
void state_4() 
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, HIGH);
 digitalWrite(TL_GRE, HIGH);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
 delay(500);
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
 delay(500);
}
void state_5() 
{
 digitalWrite(TL_RED, HIGH);
 digitalWrite(TL_YEL, HIGH);
 digitalWrite(TL_GRE, HIGH);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
}
void state_6() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
}
void state_7() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, HIGH);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, LOW);
 
}

void state_8() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, HIGH);
 digitalWrite(TL_PRU, LOW);
}
void state_9() 
{
 digitalWrite(TL_RED, LOW);
 digitalWrite(TL_YEL, LOW);
 digitalWrite(TL_GRE, LOW);
 digitalWrite(TL_BLU, LOW);
 digitalWrite(TL_ORG, LOW);
 digitalWrite(TL_PRU, HIGH);
}
