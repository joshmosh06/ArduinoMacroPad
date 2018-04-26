#include <LiquidCrystal.h>
#include <dht.h>

#define DHT11_PIN 13
//pins
#define KEY1 3
#define KEY2 4
#define KEY3 5
#define KEY4 6


//keys
#define keypad1 0x55
#define keypad2 0x56
#define keypad3 0x57
#define keypad4 0x58
#define keypad5 0x59


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
dht DHT;
// Keyboard buffer Register
uint8_t buf[8] = {0};
 bool boolArray[4] = {false , false , false , false };
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
 if(digitalRead(KEY1)==HIGH){
      keyPress(keypad2);
      boolArray[1] = true;
  }
  if(digitalRead(KEY1)==LOW && boolArray[0]) {
    keyRelease(keypad2);
    boolArray[0] = false;
  }
   if(digitalRead(KEY2)==HIGH){
      keyPress(keypad3);
      boolArray[2] = true;
  }
  if(digitalRead(KEY2)==LOW && boolArray[1]) {
    keyRelease(keypad3);
    boolArray[1] = false;
  }
   if(digitalRead(KEY3)==HIGH){
     keyPress(keypad4);
      boolArray[2] = true;
  }
  if(digitalRead(KEY3)==LOW && boolArray[2]) {
    keyRelease(keypad4);
    boolArray[2] = false;
  }
   if(digitalRead(KEY4)==HIGH){
     keyPress(keypad5);
     boolArray[3] = true;
  }
  if(digitalRead(KEY4)==LOW && boolArray[3]) {
    keyRelease(keypad5);
    boolArray[3] = false;
  }
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature*(9/5) +32);
  lcd.print((char)223);
  lcd.print("F");
  lcd.setCursor(0,1);
  lcd.print(buf[0]);
  lcd.print(buf[1]);
  lcd.print(buf[2]);
  lcd.print(buf[3]);
  lcd.print(buf[4]);
  lcd.print(buf[5]);
  lcd.print(buf[6]);
  lcd.print(buf[7]);
  lcd.print(buf[8]);
  delay(20);
}

void keyPress(int key) {
  buf[2] = key;
  Serial.write(buf, 8);
}
void keyRelease(int key) {
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}

