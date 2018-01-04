
const int ledPin =  3;      // the number of the LED pin
const int ledPinPot =  5;
const int pinPot = 0; // Pin A0

int brillo2;
int brillo;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // pin analogicos están como entradas por defecto

}

void loop() {

  brillo2 = analogRead(pinPot);
  brillo2 = map(brillo2, 0, 1023, 0, 255);
  analogWrite(ledPinPot, brillo2);
  
  for(brillo=0; brillo<256; brillo++) {
  	analogWrite(ledPin, brillo);
    delay(10);
  }
  for(brillo=255; brillo>=0; brillo--) {
  	analogWrite(ledPin, brillo);
    delay(10);
  }
  
}