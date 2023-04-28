#include<LiquidCrystal.h>

int Trig = 3;
int Echo = 4;

int Buzzer = 5;
int Led = 6;

const int RS = 8, EN = 9, D4 = 10, D5 = 11, D6 = 12, D7 = 13;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
 
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);

  lcd.begin(16,2);

  pinMode(Led,OUTPUT);
  pinMode(Buzzer,OUTPUT);
 
  
}

void loop() {
 
  digitalWrite(Trig,LOW);
  delayMicroseconds(1);

  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);

  digitalWrite(Trig,LOW);

  int Time = pulseIn(Echo,HIGH);
     Time = Time/2;
  int distance = Time/29;


   if (distance<=10){
    digitalWrite(Led,HIGH);

    lcd.setCursor(0,0);
    lcd.print("Warning Vechile");
    lcd.setCursor(0,1);
    lcd.print("Distance : ");
    lcd.print(distance);
    lcd.print("cm");
    
    digitalWrite(Buzzer,HIGH);
    delay(500);
    digitalWrite(Buzzer,LOW);
    delay(200);
   }
   else{
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);

    lcd.setCursor(0,0);
    lcd.print("                      ");
    lcd.setCursor(0,1);
    lcd.print("                      ");
   }
}
