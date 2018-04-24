#define de 11 
#define in 6
#define m_sensor 9
#define r_sensor 10
#define l_sensor 13
#define MAX 90
#define kp 15
#define kd 5


#define RF 4 //right forward 
#define RB 7 // right backward
#define LF 8  //left forward
#define LB 12 //left backward 

//speed
int enable1=6;
int enable2=11;

int speedcar;

 void line(){
 
  Serial.println("line_follower");

  int8_t sensor_R = 0, sensor_M = 0, sensor_L = 0  ; 
  
 sensor_R = digitalRead(r_sensor);
  sensor_M = digitalRead(m_sensor);
 sensor_L = digitalRead(l_sensor);


  if(sensor_R == 1 && sensor_M == 0 && sensor_L == 1){
  forward();
  //delay (50); 
  if(sensor_R == 1 && sensor_M == 0 && sensor_L == 0)
  {
    left();
    delay (50);  
  }
  else if(sensor_R == 1 && sensor_M == 1 && sensor_L == 0)
  {  
  left();
 }
 /*else if(sensor_R == 1 && sensor_M == 1 && sensor_L == 1){
    stop_motor() ;
  }*/

  /*else if(sensor_R == 0 && sensor_M == 0 && sensor_L == 0){
     forward();
  }*/
  else if(sensor_R == 0 && sensor_M == 0 && sensor_L == 1){
     
     right();
         delay (50);     

  }
   else if(sensor_R == 0 && sensor_M == 1 && sensor_L == 1){
     right();
         delay (50);
      

  }
   

  }
 

  }


 void forward(){
  speedcar=85;
    digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  analogWrite(enable1, speedcar);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  analogWrite(enable2, speedcar);
  }



void right(){
  speedcar=75;
      digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
   analogWrite(enable1, speedcar);
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);  
   analogWrite(enable2, speedcar);
  }


void left(){
   speedcar=75;
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  analogWrite(enable1, speedcar);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  analogWrite(enable2, speedcar);
  }
void stop_motor(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW); 
  Serial.println("stop"); 
  }  



 void setup(){
  
   pinMode(de,OUTPUT);
  pinMode(in,OUTPUT);
  digitalWrite(de,HIGH);
  digitalWrite(in,HIGH);

  
  }


  void loop(){
    int x ;
     if (Serial.available()){
    x = Serial.read() ; 
      Serial.print(x);

      
    if(x=='8'){
      line();
       Serial.println("line_follower");
    }
    }
  }
