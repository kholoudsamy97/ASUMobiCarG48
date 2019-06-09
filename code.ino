
float c =( 2.26/160);
float th =(0.43/180) ;
//our L298N control pins
const int LeftMotorForward = 8;
const int LeftMotorBackward = 12;
const int RightMotorForward = 4;
const int RightMotorBackward = 7;
#define RF 4 //right forward 
#define RB 7 // right backward
#define LF 8  //left forward
#define LB 12 //left backward 
 int trigPin =2;
 int echoPin =3;
 int duration,distance;
char x ;
byte de=11,in=6;
float k=255;
////**** FUNCTIONS ****////
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
  digitalWrite(RB,LOW );
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);  
  Serial.println("right");
  }


void left(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LF,HIGH );
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
   analogWrite(de,155);  //right
  analogWrite(in,165.25);
  Serial.begin(9600);
    
    }
     pinMode(trigPin, OUTPUT); //defining pins
      pinMode(echoPin, INPUT);




void Distance (float g)
{
 // Serial.println(g);
float t = c * g;
Serial.println(t);
forward();
delay(t*1000);
stop_motor();
}

void angle (float g)
{
 // Serial.println(g);
float t = th * g;
Serial.println(t);
right();
delay(t*1000);
stop_motor();
}

    
    void loop() {
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
    delay(1000);
  angle(270);
  
  }
      
      if (Serial.available()){
    x = Serial.read() ; 
      Serial.print(x);

    if (x=='1'){
   /*  analogWrite(de,155); 
  analogWrite(in,165.25);*/
  analogWrite(de,255); 
  analogWrite(in,255);
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
 else if(x=='9'){
      Serial.println("enter distance");
      delay(3000);
      char k =Serial.read ();
     int sum=0;
      if(k=='t'){
         
           for(int i=1;i>-1;i--)
       {char k =Serial.read ();
        int m =k-'0';
       Serial.println(m);
      m=m*(pow(10,i)) ;
     // Serial.println(m);
      sum=sum+m ;
     // Serial.println(sum);
      }
        }
        if(k=='r'){
         
           for(int i=2;i>-1;i--)
      {char k =Serial.read ();
       int m =k-'0';
      // Serial.println(m);
      m=m*(pow(10,i)) ;
      //Serial.println(m);
      sum=sum+m ;
     // Serial.println(sum);
      
          }
          sum=sum+1;
        }
      
      
  Serial.println(sum);
      Distance (sum);
       
      }

 else if(x=='0'){
      Serial.println("enter angle");
      delay(1500);
      char k =Serial.read ();
     int sum=0;
      if(k=='t'){
         
           for(int i=1;i>-1;i--)
       {char k =Serial.read ();
        int m =k-'0';
       Serial.println(m);
      m=m*(pow(10,i)) ;
     // Serial.println(m);
      sum=sum+m ;
     // Serial.println(sum);
      }
        }
        if(k=='r'){
         
           for(int i=2;i>-1;i--)
      {char k =Serial.read ();
       int m =k-'0';
      // Serial.println(m);
      m=m*(pow(10,i)) ;
      //Serial.println(m);
      sum=sum+m ;
     // Serial.println(sum);
      
          }
          sum=sum+1;
        }
      
      
 Serial.println(sum);
      angle (sum);
       
 }


else if(x = 'q')
 {

 forward();
  delay(1000);
  stop_motor();



  
Serial.println("circ");
  
analogWrite(de,100);  
analogWrite(in,240);
forward();
delay(3997);
analogWrite(de,100);  
analogWrite(in,240);
forward();    
delay(3997);


stop_motor();
delay(2000);

Serial.println("inf");
     
  analogWrite(de,230);  
  analogWrite(in,90);
forward();
 
  delay(2000);
/*   
     analogWrite(de,155);  //right
  analogWrite(in,165.25);
forward();
 delay(200);*/
  
 analogWrite(de,70);  
  analogWrite(in,250);
forward();
  
    delay(5000);
    stop_motor();


//delay(5000);
  

  
 
/* 
 Serial.println("rec");
   analogWrite(de,155);  //right
  analogWrite(in,165.25);


        Distance(30);
         delay(100);
         Distance(30);
      delay(100);
        Distance(30);
       delay(100);
     Distance(20); 
    delay(100);
                       angle(150);
      Distance(30);
         delay(100);
         Distance(30);
      delay(100);
        Distance(30);
       delay(100);
     Distance(20); 
    delay(100);
                   angle(150); 
    Distance(30);
         delay(100);
         Distance(30);
      delay(100);
        Distance(30);
       delay(100);
     Distance(20); 
    delay(100);
                     angle(150);
      Distance(30);
         delay(100);
         Distance(30);
      delay(100);
        Distance(30);
       delay(100);
     Distance(20); 
    delay(100); */

  }
      
    }

      
    
      
      }
      
