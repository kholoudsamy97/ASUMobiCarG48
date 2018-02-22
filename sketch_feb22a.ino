const byte ledPin = 3;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 for(int n = 0 ; n <= 255 ; n++)
 {
  analogWrite(ledPin,n);
  delay(10);
  }
  for(int n = 0 ; n >= 255 ; n--)
  {
    analogWrite(ledPin,n);
    delay(10);
    }
}
