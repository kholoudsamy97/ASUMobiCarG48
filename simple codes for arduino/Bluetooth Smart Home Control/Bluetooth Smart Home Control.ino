int bd;
int led =13;
void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("On 1 Off 2");
pinMode(led,OUTPUT);
}
void loop() {
 // put your main code here, to run repeatedly:
if (Serial.available())
{
 bd=Serial.read();
 Serial.println(bd);
 if(bd=='0')
 {
 digitalWrite(led,HIGH);
 Serial.print("high");
 }
 {
 if (bd=='1')
 {
 digitalWrite(led,LOW);
 Serial.print("low");
 }
 }
 delay(100);
}
}
