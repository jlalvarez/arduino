// #include <Ping.h>  // ThinkerCad no dispone de la librería Ping
// Por lo que se utiliza el código disponible en https://www.arduino.cc/en/Tutorial/Ping

const int zumbador=6;
const int led=8;
// this constant won't change. It's the pin number of the sensor's output:
const int pingPin = 4;

// Ping ping = Ping(pingPin);

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm, distancia;
  int pausa=10; // Tiempo de parpadeo
  
  //ping.fire();
  // distancia = ping.centimeters();
  

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  
  distancia = cm;
  
  if (distancia < 100) {
  	pausa = distancia * 10;
	digitalWrite(zumbador, HIGH);
	digitalWrite(led, HIGH);
	delay(pausa);
  }
  
  digitalWrite(zumbador, LOW);
  digitalWrite(led, LOW);
  delay(pausa);
  
  
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}