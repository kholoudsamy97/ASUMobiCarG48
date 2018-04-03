int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int led9 = 5;
int led10 = 4;
int led11 = 3;
int led12 = 2;


int volume;
 
void setup() {                
  Serial.begin(9600); // For debugging
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);  
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
 
}
 
void loop() {
  
  volume = analogRead(A0); // Reads the value from the Analog PIN A0
  /*
    //Debug mode
    Serial.println(volume);
    delay(100);
  */
  
  if(volume>=22){
    digitalWrite(led1, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led1, LOW); // Turn OFF Led
  }
  if(volume>=23){
    digitalWrite(led2, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led2, LOW); // Turn OFF Led
  }
  if(volume>=24){
    digitalWrite(led3, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led3, LOW); // Turn OFF Led
  }
  if(volume>=25){
    digitalWrite(led4, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led4, LOW); // Turn OFF Led
  }
  if(volume>=26){
    digitalWrite(led5, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led5, LOW); // Turn OFF Led
  }
  if(volume>=27){
    digitalWrite(led6, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led6, LOW); // Turn OFF Led
  }if(volume>=28){
    digitalWrite(led7, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led7, LOW); // Turn OFF Led
  }if(volume>=29){
    digitalWrite(led8, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led8, LOW); // Turn OFF Led
  }if(volume>=30){
    digitalWrite(led9, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led9, LOW); // Turn OFF Led
  }if(volume>=31){
    digitalWrite(led10, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led10, LOW); // Turn OFF Led
  }if(volume>=32){
    digitalWrite(led11, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led11, LOW); // Turn OFF Led
  }
  if(volume>=33){
    digitalWrite(led12, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led12, LOW); // Turn OFF Led
  }
 
 
}


