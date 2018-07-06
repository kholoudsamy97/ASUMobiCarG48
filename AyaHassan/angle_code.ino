float th =(0.43/180) ;

void angle (float g)
{
 // Serial.println(g);
float t = th * g;
Serial.println(t);
right();
delay(t*1000);
stop_motor();
}

void loop {
else if(x=='0'){
      Serial.println("enter angle");
      delay(1500);
      char k =Serial.read ();
     int sum=0;
      if(k=='t'){              // for two numbers
         
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
        if(k=='r'){         // for three numbers
         
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
}
