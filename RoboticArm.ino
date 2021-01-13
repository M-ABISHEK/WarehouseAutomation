#include <Servo.h>
int x,y,z,p,i;
Servo myservoa, myservob,myservoc, myservod;
 void setup() 
{
  Serial.begin(9600);
  myservoa.attach(11); //MOUTH OF AN ARM(MOTOR 1)
  myservob.attach(9);  //MIDDLE OF ARM(MOTOR 2)
  myservoc.attach(6);  //BASEMENT OF ARM(MOTOR 3)
  myservoa.write(x);
  myservob.write(y);
  myservoc.write(z);
 }

void loop() 
{

        // MOTOR 3 45 DEG FRONT//
        for (z = 45; z >= 0; z -= 1) 
          { 
            myservoc.write(z);             
            delay(50);                    
          }
   
        //MOTOR 2 90 DEG FRONT//
        for (y = 0; y <= 90; y += 1) 
          {
            myservob.write(y);            
            delay(50);                   
          }
        //MOTOR 1 90 DEG OUTWARDS//
        for (x = 90; x >= 0; x -= 1) 
          { 
            myservoa.write(x);            
            delay(10);                  
          }
        //MOTOR 1 90 DEG INWARDS//
        for (x = 0; x <= 90; x += 1)
          { 
            myservoa.write(x);             
            delay(10);               
          }
        //MOTOR 2 90 DEG BACKWARDS//
        for (y = 90; y >= 0; y -= 1) 
          {
            myservob.write(y);              
            delay(50);                      
          }
  /////////////////////////////////////////////////////////////////////////////////

        
          //MOTOR 3 90 DEG BACKWARDS//
         for (z = 0; z <= 90; z += 1) 
           { 
              myservoc.write(z);              
              delay(50);                      
           }
 
         //MOTOR 2 90 DEG BACKWARDS//
         for (y = 90; y >= 0; y -= 1) 
           {
              myservob.write(y);              
              delay(50);                      
           }
         //MOTOR 1 90 DEG OUTWARDS//
         for (x = 90; x >= 0; x -= 1) 
           { 
              myservoa.write(x);            
              delay(10);                  
           }
         //MOTOR 2 90 DEG FRONT//
         for (y = 0; y <= 90; y += 1) // prev 45 deg 
           {
              myservob.write(y);            
              delay(50);                   
           }
         //MOTOR 1 90 DEG INWARDS//
         for (x = 0; x <= 90; x += 1) 
           { 
              myservoa.write(x);        
              delay(10);               
           }
}
