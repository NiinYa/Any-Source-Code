#include <avr/wdt.h>
#define tombol1 1
#define tombol2 2

void Percobaan1();
void Percobaan2();

void setup()
{
  MCUSR &= ~(1 << WDRF);
  wdt_disable();

  Serial.begin(9600);
  Serial.println("==BOOTING==");

  delay(1000);

  wdt_enable(WDTO_4S);
  Serial.println("+++++peraturan+++++");
  Serial.println("pencet kedua switch sehingga bisa lanjut ke percobaan selanjutnya");
  delay(2000);
  wdt_reset();
  Serial.println("jika salah atau terlambat maka program akan mengulang ke percobaan pertama");
  delay(2000);
  wdt_reset();
  Serial.println("hitung mundur sebelum program mulai");
  delay(2000);
  wdt_reset();
  Serial.println("3");
  delay(1000);
  wdt_reset();
  Serial.println("2");
  delay(1000);
  wdt_reset();
  Serial.println("1");
  delay(1000);
  wdt_reset();


}
void loop()
{
  Serial.println("percobaan 1 dimulai!");
  delay(500);
  Percobaan1();
  delay(500);
  Serial.println("akan masuk ke percobaan ke2\nhitung mundur mulai");
  delay(1000);
  Serial.println("3\n");
  delay(1000);
  wdt_reset();
  Serial.println("2\n");
  delay(1000);
  Serial.println("1\n");
  delay(1000);
  wdt_reset();
  Serial.println("percobaan 2 dimulai!");
  delay(500);
  Percobaan2();
  delay(500);
  Serial.println("\nSemua Percobaan Sukses, MANTAPS");
  while (1) {}
}

void Percobaan1() {
  wdt_reset();
  int button1, button2;
  bool finishline = false;
  Serial.println("tekan kedua switch\nBatas Waktu 4 detik");
  while (finishline == false) {
    button1 = digitalRead(tombol1);
    button2 = digitalRead(tombol2);
    if (button1 == HIGH && button2 == HIGH) {
      finishline = true;
    }
    wdt_reset();
  }
  Serial.println("Percobaan1 sukses\n");
  delay(1000);
  wdt_reset();
}
void Percobaan2() {
  wdt_reset();
  int button1, button2;
  bool finishline = false;
  Serial.println("tekan kedua switch\nBatas Waktu 4 detik");
  while (finishline == false) {
    button1 = digitalRead(tombol1);
    button2 = digitalRead(tombol2);
    if (button1 != LOW && button2 != LOW) {
      finishline = true;
    }
    wdt_reset();
  }
  Serial.println("Percobaan2 sukses\n");
  wdt_reset();
}
