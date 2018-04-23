

#define de 11 
#define in 6
#define m_sensor 9
#define r_sensor 10
#define l_sensor 13
#define MAX 90
#define kp 15
#define kd 5

int lasterror = 0;
int error = 0;



const int LeftMotorForward = 8;
const int LeftMotorBackward = 12;
const int RightMotorForward = 4;
const int RightMotorBackward = 7;
int duration,distance;

 int getDistance ;
#define RF 4 //right forward 
#define RB 7 // right backward
#define LF 8  //left forward
#define LB 12 //left backward 
char x ;
//byte de=11,in=6;       //AE =de= 11 , in = BE = 6
float k=255;
const int trigPin = 2 ;
const int echoPin = 3 ;


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


/********************************************************************************************************************************line*/
 void line(){
 
  Serial.println("line_follower");

  int8_t sensor_R = 0, sensor_M = 0, sensor_L = 0  ; 
  
 sensor_R = digitalRead(r_sensor);
  sensor_M = digitalRead(m_sensor);
 sensor_L = digitalRead(l_sensor);
  lasterror = error;
  forward();
  if(sensor_R == 1 && sensor_M == 1 && sensor_L == 0){
    error = 2;
  }else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 0){
    error = 1;
  }else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 1){
    error = 0;
  }else if(sensor_R == 1 && sensor_M == 1 && sensor_L == 1){
    error = -3;
  }
  else if(sensor_R == 0 && sensor_M == 0 && sensor_L == 0){
    error = -4;
  }
  else if(sensor_R == 0 && sensor_M == 0 && sensor_L == 1){
    error = -1;
  }
   else if(sensor_R == 0 && sensor_M == 1 && sensor_L == 0){
    error = -6;
  }
else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 1){
    error = -5;
  }
    if(error == -2 || error == -1 ){
      right();
     delay(50);
      stop_motor();
      delay(50);
    }
else if (error == -5 ){
      forward();
     delay(50);
     stop_motor();
     delay(50);
    }
    else if (error == 2 || error == 1  ){
      left();
      delay(50);
      stop_motor();
      delay(50);
    }
else if (error == 0 || error == -3  || error == -4 || error == -6){
      stop_motor();
    }
 

 analogWrite(de , MAX - error*kp - kd*lasterror);
  analogWrite(in , MAX + error*kp + kd*lasterror);  
  
  }
  


  
  void setup() {
    pinMode(RF , OUTPUT);
  pinMode(RB , OUTPUT);
  pinMode(LF , OUTPUT);
  pinMode(LB , OUTPUT);
   pinMode(de , OUTPUT);
  pinMode(in , OUTPUT);
  analogWrite(de,255);
  analogWrite(in,255);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   Serial.begin(9600);
    
  // put your setup code here, to run once:

/*********************************************************************************line***********/
  pinMode(de,OUTPUT);
  pinMode(in,OUTPUT);
  digitalWrite(de,HIGH);
  digitalWrite(in,HIGH);

}



void loop() {
   


  
 
  Serial.print(distance);    //printing the numbers
  Serial.print("cm");       //and the unit
  Serial.println(" ");      //just printing to a new line


  
  //IF YOU WANT THE PORGRAM SPITTING OUT INFORMATION SLOWER, JUST UNCOMMENT(DELETE THE 2 //) THE NEXT LINE AND CHANGE THE NUMBER
  //delay(500);
     
  if (Serial.available()){
    x = Serial.read() ; 
      Serial.print(x);

    if (x=='1'){
      forward();
    }else if(x=='2'){
      backward();
    }else if (x == '4'){
      left();
    }else if (x=='3'){
      right();
    }else if ( x=='5'){
    stop_motor();
    }
     else if(x=='6'&&k==255){
      analogWrite(in,127.5);   
      analogWrite(de,127.5);
      k=127.5;
      Serial.print(k);
    }
     else if(x=='6'&&k==127.5){
      analogWrite(in,63.75);  
      analogWrite(de,63.75);
     k=63.75;
     Serial.print(k);
    }
     else if(x=='6'&&k==63.75){
      analogWrite(in,31.875);    
      analogWrite(de,31.875);
     k=31.875;
     Serial.print(k);
    }
    else if(x=='7'&&k==31.875){
      analogWrite(in,63.75); 
      analogWrite(de,63.75);
      k=63.75;
      Serial.print(k);}
    else if(x=='7'&&k==63.75){
      analogWrite(in,127.5);   
      analogWrite(de,127.5);
      k=127.5;
      Serial.print(k);
    }
    else if(x=='7'&&k==127.5){
      analogWrite(in,255);     
      analogWrite(de,255);
      k=255;
      Serial.print(k);
      }


      else if(x=='8'){
      line();
    }
      }


       
  digitalWrite(trigPin, LOW);       // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);       // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);    // Reads the echoPin, returns the sound wave travel time in microseconds

  distance= duration*0.034/2;             // Calculating the distance
  
 
  Serial.print("Distance: ");              // Prints the distance on the Serial Monitor
  Serial.println(distance);

 if(distance<30 && distance >0) 
  {
    
    stop_motor();
    delay(1500);
  
  }
 
    
      }


   
