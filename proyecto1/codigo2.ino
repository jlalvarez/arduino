const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin

int ledState = 0; // variable for the led status 0=>led off 1=>led on


int buttonState = 0;         
int lastState = 0;

const int DebounceTime = 10;

boolean anti_debounce(int pin) {

	boolean status;
	boolean lastStatus=false;
	int cont = 0;

	do {
		status = digitalRead(pin);
		if(status!=lastStatus) {
			cont = 0;
			lastStatus = status;
		} else {
			cont++;
		}
		delay(1);
	} while(cont<DebounceTime);

	return status;	

}


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastState) {
    if(anti_debounce(buttonPin)) {
      ledState = 1 - ledState;
    }
    
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