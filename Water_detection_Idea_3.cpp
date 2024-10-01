//This is the exact same as water_detection_2 but with the faucet lever detection

int check, lever;
int buzzerPin = 8, leverPin = A4, leakPin = A5;

void setup() {
  // put your setup code here, to run once:
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
    Serial.println("Leak detected");
    tone(buzzerPin, 1000);
  }
  else if(check > 0 && lever > 0 && lever < 200)
  {
    Serial.println("Faucet Left Open");
    tone(buzzerPin,4500,200);
    tone(buzzerPin,6000,200);
  }
  else if(check == 0 && lever > 200)
  {
    Serial.println("Error, check sensor and water source");
    noTone(buzzerPin);
  }
  else if(check > 0 && lever > 200)
  {
    Serial.println("Normal Operation");
    noTone(buzzerPin);

  }
  delay(500);

}
