
const byte LED =13 ;
const byte BTN=2;
byte btnstates=0;

void setup()
{
pinMode(LED,OUTPUT);
pinMode (BTN,INPUT);
}

void loop()
{

btnstates = digitalRead (BTN);
if (btnstates==HIGH)
{
digitalWrite(LED,HIGH);
}
else 
{
  digitalWrite(LED,LOW);

}

}
  
  
