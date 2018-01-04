const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin

int ledState = 0; // variable for the led status 0=>led off 1=>led on

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastState = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  if ((buttonState == HIGH) && (lastState==0)) {
  	ledState = 1 - ledState;
    delay(20);
  }
  
  lastState = buttonState;

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (ledState == 1) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}