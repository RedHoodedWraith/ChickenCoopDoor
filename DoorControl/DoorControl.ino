/* Light Controlled Door Management Code
by Rowan Rathod

Last Modified 11 November 2016
*/

const int leftclose = 1;  // The 'Closed Door' trigger button is connected to Analogue Pin 1
const int rightopen = 0;  // The 'Open Door' trigger button is connected to Analogue Pin 0

#include <Servo.h> // Servo Set up

Servo servo;  // Servo Set up

int door;  // Establishing the Door Status integers

void setup ()  {
  Serial.begin(9600);  //Set up the Serial Port so I can diagnose digital processes
 
  servo.attach(9); // The servo is attached at Digital Pin 9
}

void loop  ()  {
  //  Light Sensor Setup
  int lightSensor = analogRead(A4);  //  Read the Light Sensor from Analogue Pin 4
  int light = lightSensor;

  int open = analogRead(rightopen);  // Read the 'Open Door' trigger Button and assign its values to the 'open' integer
  int close = analogRead(leftclose); // Read the 'Closed Door' trigger Button and assign its values to the 'close' integer

  //  Send Information through the Serial Port for Diagnostics during testing
  Serial.print("Closed Door Detection: ");  //  These tell me what the 'Closed Door' trigger (button) values are through the Serial Port
  Serial.println(close);
  Serial.print("Open Door Detection: "); //These tell me what the 'Open Door' trigger (button) values are through the Serial Port
  Serial.println(open);

  Serial.print("Door Status: ");  // Tells me if the Arduino thinks if the door is opened or closed
  Serial.println(door);
  Serial.print("Light Readings: ");  // Tells me what the readings from the Light Sensor are
  Serial.println(light);

 //  Door Statuses
   if  ( ((open) < 10) && ((close) > 10) )  {  // If door button is at "open" position because it is PUSHING THE OPEN BUTTON and the closed button is not being pushed then...
          door = 1;  //  ...Make Door Status Open
        }

   if  (  ((close) < 10) && ((open) > 10) ) {  // If door button is at "closed" position because it is PUSHING THE CLOSE BUTTON and the opened button is not being pushed then...
          door = 0;  //  ...Make Door Status Close
        }
 
  
  //  Opening the door
  if  ( ( (light)>512) && ( (door)==0) )  {   // If light is above threshold (meaning it's daytime) and door is at "closed" status, then open the door.

   Serial.println("Operation: Opening");  // Tells me in the Serial Port that the door is trying to open.
   servo.write(30); // Servo spins Anticlockwise to open the door.

   
  }
  
  //  Closing the door
  if  ( ( (light)<512) && ( (door)==1) )  {  // If light is below threshold (meaning it's night time) and door is at "open" status, then close the door.

   Serial.println("Operation: Closing");  // Tells me in the Serial Port that the door is trying to close.
   servo.write(100); // Servo spins Clockwise to close the door.
      
  }

  if (( ((light)>512) && ((door)==1) ) || ( ((light)<512) && ((door)==0) ))  {  // If the light and door conditions are neither of the above, then do nothing.
    
   Serial.println("Operation: Idle");
   servo.write(90); // Servo doesn't spin in order to leave the door where it is
  }

  Serial.println("---------------------------------"); // This just makes it easier to read in the Serial Port which information is for what time at a given instance (every 1 second)
  
 delay(1000);  // Wait 1 second before starting this process again starting from the beginning of (loop).
} 


