const byte Led =7;

void setup() {
 pinMode(Led,OUTPUT);

}

void loop() {
digitalWrite(Led,HIGH);
delay(500);
digitalWrite(Led,LOW);
delay (1500);

}
