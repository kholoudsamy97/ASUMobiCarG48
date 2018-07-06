 char x ;
 byte de=11,in=6;


  void setup()
  {
  analogWrite(de,155);  // right_side
  analogWrite(in,165.25);  // left_side
    }

    
   void loop() {
  if(x = 'q')
  {
    
Serial.println("circ");
analogWrite(de,96);  
analogWrite(in,232);
forward();
delay(3997);
analogWrite(de,90);  
analogWrite(in,232);
forward();    
delay(3997);


stop_motor();
    }
    
      
    
    
    
    
    }

  
