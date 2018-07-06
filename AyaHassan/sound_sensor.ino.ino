 byte out=5;
void setup() {
   pinMode(out,INPUT);

}

void loop() {
   if(digitalRead(out))
  {
Serial.println("watchout!there is a sound");
  }

}
