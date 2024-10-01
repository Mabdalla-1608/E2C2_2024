//This is the exact same as water_detection_3 but with the LCD screen to display the messages
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);
int check, lever;
int buzzerPin = 8, leverPin = A4, leakPin = A5;

#include <LiquidCrystal.h>

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(leverPin,INPUT);
  pinMode(leakPin,INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(5,HIGH);
  check = analogRead(leakPin);
  lever = analogRead(leverPin);
  Serial.print("Check:");
  Serial.println(check);
  Serial.print("Lever:");
  Serial.println(lever);

  if(check > 0 && lever == 0)
  {
    lcd.clear();
    lcd.print("Leak detected");
    tone(buzzerPin, 1000);
  }
  else if(check > 0 && lever > 0 && lever < 200)
  {
    lcd.clear();
    lcd.print("Faucet Left Open");
    tone(buzzerPin,4500,200);
    tone(buzzerPin,6000,200);
  }
  else if(check == 0 && lever > 200)
  {
    lcd.clear();
    lcd.print("Error, check");
    lcd.setCursor(0, 1);
    lcd.print("sensor & water");
    lcd.setCursor(0, 0);
    noTone(buzzerPin);
  }
  else if(check > 0 && lever > 200 )
  {
    lcd.clear();
    lcd.print("Normal Operation");
    noTone(buzzerPin);

  }
  else
  {
    lcd.clear();
    lcd.print("Normal Operation");
    noTone(buzzerPin);
  }
  delay(500);

}
