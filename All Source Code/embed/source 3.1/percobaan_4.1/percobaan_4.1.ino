#include <avr/wdt.h>
void setup()
{
MCUSR &= ~(1<<WDRF); // Clear WDRF in MCUSR
wdt_disable();
Serial.begin(9600);
Serial.println("==BOOTING==");
// make a delay before enable WDT
// this delay help to complete all initial tasks
delay(2000);
wdt_enable(WDTO_4S);//enabling using 4 sec threshold timer
Serial.println("success enabling wdt");
}
void loop()
{
Serial.println("LOOP started ! ");
for(int i=0; i<=5; i++)
{
Serial.print("Loop : ");
Serial.print(i);
Serial.println();
delay(1000);//delay 1 sec
wdt_reset();//then feed the dog
}
//infinity loop to deliberately hang MCU then reset MCU
while(1){}
}
