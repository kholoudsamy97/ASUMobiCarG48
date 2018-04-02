# define RF 4
# define RB  7
# define LF 8
# define LB 12
char x ; byte de =5 , in =6;
int k =255 ;
void forward (){
  digitalWrite (RF , HIGH);
    digitalWrite (RB , LOW);
      digitalWrite (LF , HIGH);
        digitalWrite (LB , LOW);
        Serial.println("forward");
  }
  void backward (){
  digitalWrite (RF , LOW);
    digitalWrite (RB , HIGH);
      digitalWrite (LF , LOW);
        digitalWrite (LB , HIGH);
        Serial.println("backward");
  }
  void right (){
  digitalWrite (RF , LOW);
    digitalWrite (RB , LOW);
      digitalWrite (LF , HIGH);
        digitalWrite (LB , LOW);
        Serial.println("right");
  }
  void left(){
  digitalWrite (RF , HIGH);
    digitalWrite (RB , LOW);
      digitalWrite (LF , LOW);
        digitalWrite (LB , LOW);
        Serial.println("left");
  }
  void stop_motor (){
  digitalWrite (RF , LOW);
    digitalWrite (RB , LOW);
      digitalWrite (LF , LOW);
        digitalWrite (LB , LOW);
        Serial.println("stop");
  }
  
  
  
  

 
void setup() {
  pinMode(RF,OUTPUT);
    pinMode(RB,OUTPUT);
      pinMode(LF,OUTPUT);
        pinMode(LB,OUTPUT);
          pinMode(de,OUTPUT);
            pinMode(in,OUTPUT);

            Serial.begin(9600);

  
  // put your setup code here, to run once:

}

void loop() {
   if(Serial.available()){
    
x==Serial.read();
Serial.print(x);
if(x=='1'){
  forward();
}else if(x=='2'){backward();
   }else if (x=='4'){
  right();}
  else if (x=='3'){left();}
  else if (x=='5'){stop_motor();}
  else if (x=='6'&&k=='255'){analogWrite(de,127.5);
  k=127.5;}
      else if (x=='6'&&k=='127.5'){analogWrite(de,63.75);
  k=63.75;}
else if (x=='6'&&k=='63.75'){analogWrite(de,31.875);
  k=31.875;}
 else if (x=='7'&&k=='31.875'){analogWrite(in,63.75);
  k=63.75;}
else if (x=='7'&&k=='63.75'){analogWrite(in,127.5);
  k=127.5;}
 else if (x=='7'&&k=='127.5'){analogWrite(in,255);
  k=255;}
   
}
    // put your main code here, to run repeatedly:
   
}
