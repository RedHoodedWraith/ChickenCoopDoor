const int buttonPin = 2;     // the number of the pushbutton pin


// variables will change:
int buttonState;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  Serial.print("Button State: ");
  Serial.println(buttonState);

  delay(1000);
}
