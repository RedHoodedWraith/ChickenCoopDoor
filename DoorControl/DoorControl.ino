/* Light Controlled Door Management Code
by Rowan Rathod

Last Modified 27 June 2016
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
  if  (((light)>512) && ((door)==0))  {
    for(pos = 0; pos <= 180; pos += 5)  //  Open (move in steps of 5)   - Adjust middle value (180)!
      {
        servo.write(pos);
        delay(15);
        
        if((pos) == 180)  {
          door = 1;  //  Door Status is Open
        }
      }
  }
  
  //  Closing the door
  if  (((light)<512) && ((door)==1))  {
      for(pos = 180; pos >= 0; pos -= 5)  //  Close (move in steps of 5)   - Adjust middle value (180)!
      {
        servo.write(pos);
        delay(15);
        
        if((pos) == 0)  {
          door = 0;  //  Door Status is Closed
        }
      }
  }
  
}


