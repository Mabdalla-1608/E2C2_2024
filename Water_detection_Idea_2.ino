//This is the exact same as water_detection_1 but with the tweeter to buzz

int check;
int buzzer = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  pinMode(A5,INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
  check = analogRead(A5);
  if(check > 0)
  {
    Serial.println("Leak detected");
    tone(buzzer, 1000);
  }
  else
  {
    Serial.println("No Leak detected");
    noTone(buzzer);
  }
  delay(500);

}
