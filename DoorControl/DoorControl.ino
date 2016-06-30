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
  
    for(pos = 0; pos <= 180; pos += 5)  //  Open (move in steps of 5)   - Adjust middle value (180)!
      {
        servo.write(pos);
        delay(15);
        
        if((pos) == 180)  {  // If servo is at "open" position
          door = 1;  //  Make Door Status Open
        }
      }
      
  }
  
  //  Closing the door
  if  (((light)<512) && ((door)==1))  {  // If light is below threshold and door is has "open" status, then close the door.
  
      for(pos = 180; pos >= 0; pos -= 5)  //  Close (move in steps of 5)   - Adjust middle value (180)!
      {
        servo.write(pos);
        delay(15);
        
        if((pos) == 0)  {  // If servo is at "close" position
          door = 0;  //  Make Door Status Closed
        }
      }
      
  }
}


