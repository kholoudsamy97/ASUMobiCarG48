Serial.println("inf");
     
  analogWrite(de,230);  
  analogWrite(in,90);
forward();
 
  delay(5000);

  
 analogWrite(de,70);  
  analogWrite(in,250);
forward();
  
    delay(5000);
    stop_motor();
