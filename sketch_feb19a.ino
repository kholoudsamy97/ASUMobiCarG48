
int led1=10,led2=11,led3=12;
double r ;
void setup() {
  // put your setup code here, to run once:
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  r = analogRead(A2);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);

  if(r>=200&&r<400)
  {
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);

  Serial.println(r);

    }
    if(r>=400&&r<800)
  {
     digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  Serial.println(r);

    }
    if(r>800)
  {
     digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  Serial.println(r);

    }
  


}
