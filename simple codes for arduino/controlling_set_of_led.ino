
void setup() {
  // put your setup code here, to run once:
for(byte i=2;i<6;i++)
{
  pinMode(i,OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(byte i=2;i<=6;i++)
{
  digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
  
}
for(byte i=6;i>=2;i--)
{
  digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
}
}

