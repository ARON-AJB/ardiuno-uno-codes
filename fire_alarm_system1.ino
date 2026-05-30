#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int tempPin = A0;
int buzzer = 10;
int led=9;

void setup()
{
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  int value = analogRead(tempPin);

  float voltage = value * (5.0 / 1023.0);

  float tempC = (voltage - 0.5) * 100;

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  //lcd.print((char)223);
  lcd.print("°C   ");

  lcd.setCursor(0,1);

  if(tempC > 80)
  {
    lcd.print("FIRE ALERT!!!");
    digitalWrite(buzzer, HIGH);
    digitalWrite(led,HIGH);
    tone(buzzer,3000);
    
}
 
  else
  {
    lcd.print("Status: SAFE ");
    digitalWrite(buzzer, LOW);
    noTone(10);
    digitalWrite(led,LOW);
    
  }

  delay(500);
}