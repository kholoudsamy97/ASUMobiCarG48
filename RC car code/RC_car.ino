//our L298N control pins
const int LeftMotorForward = 8;
const int LeftMotorBackward = 12;
const int RightMotorForward = 4;
const int RightMotorBackward = 7;
 int getDistance ;
#define RF 4 //right forward 
#define RB 7 // right backward
#define LF 8  //left forward
#define LB 12 //left backward 
char x ;
byte de=11,in=6;
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

}

void loop() {
   
  /*digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
     long duration = pulseIn(echoPin,HIGH);*/
     
 int duration, distance;    //Adding duration and distance
  
  digitalWrite(trigPin, HIGH); //triggering the wave(like blinking an LED)
  delay(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
  
  Serial.print(distance);    //printing the numbers
  Serial.print("cm");       //and the unit
  Serial.println(" ");      //just printing to a new line

  if(distance == 100)
  {
    stop_motor();
    delay(5000);
    
    }
  
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
      
      }
    
      }

  // put your main code here, to run repeatedly:


