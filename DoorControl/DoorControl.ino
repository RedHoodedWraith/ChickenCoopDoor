/* Light Controlled Door Management Code
by Rowan Rathod

Last Modified 30 June 2016
*/

#include <Servo.h>

Servo servo;

int pos = 0; /*  The servo's position (starting at 0)*/
int door = 0;

void setup ()  {
  Serial.begin(9600);
  
  servo.attach(9); // The servo is attached at Digital Pin 9
}

void loop  ()  {
  //  Minor Setup
  int lightSensor = analogRead(A0);
  int light = 1023 - lightSensor;
  
  Serial.println(light);
  
  //  Opening the door
  if  (((light)>512) && ((door)==0))  {   // If light is above threshold and door is has "closed" status, then open the door.
  
    myservo.write(45);
        
        if(() == )  {  // If servo is at "open" position
          door = 1;  //  Make Door Status Open
        }
      }
      
  
  
  //  Closing the door
  if  (((light)<512) && ((door)==1))  {  // If light is below threshold and door is has "open" status, then close the door.
  
    myservo.write(135);
        
        if((pos) == 90)  {  // If servo is at "close" position
          door = 0;  //  Make Door Status Closed
        }
      
      
  }
  
 delay(1000);
}


