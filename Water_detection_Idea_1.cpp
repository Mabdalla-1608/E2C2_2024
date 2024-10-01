int check;

void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
  check = analogRead(A0);
  if(check > 0)
  {
    Serial.println("Leak detected");
  }
  else
  {
    Serial.println("No Leak detected");
  }
  delay(500);

}
