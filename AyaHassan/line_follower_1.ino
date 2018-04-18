
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

 void line(){
 
  Serial.println("line_follower");

  int8_t sensor_R = 0, sensor_M = 0, sensor_L = 0  ; 
  
 sensor_R = digitalRead(r_sensor);
  sensor_M = digitalRead(m_sensor);
 sensor_L = digitalRead(l_sensor);

 // forward();
  if(sensor_R == 1 && sensor_M == 1 && sensor_L == 0){
  left() ;
  delay (1000);
   stop_motor() ;
   
  }else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 0){
    left();
    delay (1000);
     stop_motor() ;
  }else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 1){
    forward();
  }else if(sensor_R == 1 && sensor_M == 1 && sensor_L == 1){
    stop_motor() ;
  }
  else if(sensor_R == 0 && sensor_M == 0 && sensor_L == 0){
     forward();
  }
  else if(sensor_R == 0 && sensor_M == 0 && sensor_L == 1){
     right();
         delay (1000);
          stop_motor() ;

  }
   else if(sensor_R == 0 && sensor_M == 1 && sensor_L == 1){
     right();
         delay (1000);
          stop_motor() ;

  }
   else if(sensor_R == 0 && sensor_M == 1 && sensor_L == 0){
     stop_motor();
  }
else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 1){
    forward() ;
  }


  }


 void forward(){
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  Serial.println("forword");
  }

void backward(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  Serial.println("backward");
  }  

void right(){
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);  
  Serial.println("right");
  }


void left(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);  
  Serial.println("left");
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



    
