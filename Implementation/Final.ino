
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#define flamePin 12
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
SoftwareSerial BTserial(10, 11);
String BT_input;
int relay = 8;

void setup()
{
 Serial.begin(9600);
 BTserial.begin(9600);
 lcd.begin(16, 2);
 pinMode(flamePin,INPUT);
 pinMode(relay,OUTPUT);
 digitalWrite(relay,HIGH);
delay(300);
lcd.clear();
}

void loop() {
 
int Flame = digitalRead(flamePin);
  if (Flame == LOW)
  {
     lcd.setCursor(0, 0);
     lcd.print("Fire is Detected");
     BTserial.println("Fire is detected...!  Take action immediately ");
     BTserial.print(";");
     Serial.println("Fire is Detected..! Take action immediately");
     digitalWrite(relay, LOW);
  }
  else
  {
     lcd.setCursor(0, 0);
     lcd.print("    No Fire    ");
     BTserial.println("No Fire...!  Stay cool");
     BTserial.print(";");
     Serial.println("No Fire...!  Stay cool");
     digitalWrite(relay, HIGH);
   
     
  }
  delay(1500);
  lcd.clear();
}
