/* Light Controlled Door Management Code
by Rowan Rathod

Last Modified 16 September 2016
*/

const int leftclose = 13;
const int rightopen = 12;

#include <Servo.h>

Servo servo;

int pos = 0; /*  The servo's position (starting at 0)*/
int door;

void setup ()  {
  Serial.begin(9600);
  /*pinMode(leftclose, INPUT);
  pinMode(rightopen, INPUT);*/
  
  servo.attach(9); // The servo is attached at Digital Pin 9
}

void loop  ()  {
  //  Minor Setup
  int lightSensor = analogRead(A0);
  int light = 1023 - lightSensor;

/*  int open = digitalRead(rightopen);
  int close = digitalRead(leftclose); */

  Serial.print("Door Status: ");
  Serial.println(door);
  Serial.print("Light Readings: ");
  Serial.println(light);

/*//  Door Statuses
   if((open) == HIGH)  {  // If door button is at "open" position because it is PUSHING THE OPEN BUTTON
          door = 1;  //  Make Door Status Open
        }

   if((close) == HIGH)  {  // If door button is at "closed" position because it is PUSHING THE CLOSE BUTTON
          door = 0;  //  Make Door Status Close
        }
 */
  
  //  Opening the door
  if  ( ( (light)>512) && ( (door)==0) )  {   // If light is above threshold and door is has "closed" status, then open the door.

   Serial.println("Operation: Opening");
   servo.write(45); //Servo spins Anticlockwise to open the door
   
  }
  
  //  Closing the door
  if  ( ( (light)<512) && ( (door)==1) )  {  // If light is below threshold and door is has "open" status, then close the door.

   Serial.println("Operation: Closing");
   servo.write(135); //Servo spins Clockwise to close the door
      
  }

  if (( ((light)>512) && ((door)==1) ) || ( ((light)<512) && ((door)==0) ))  {  //If the light and door conditions are neither of the above, then do nothing.
    
   Serial.println("Operation: Idle");
   servo.write(90); //Servo doesn't spin to leave the door where it is
  }

  Serial.println("---------------------------------");
  
 delay(1000);
} 


