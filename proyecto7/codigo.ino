#include <Servo.h>

const int pinPot = 0;
const int pinServo = 3;
const int pulsoMin = 650; // Para girar servo a 0º
const int pulsoMax = 2550; // Para girar servo a 180º

Servo motor;

int valor;
int angulo;

void setup() {
	Serial.begin(9600);
	motor.attach(pinServo, pulsoMin, pulsoMax);
	// entradas analógicas se configuran automaticamente
}

void loop(){
	
	valor = analogRead(pinPot);
  	Serial.print("Pot: ");
  	Serial.print(valor);
  	Serial.println(".");
  
	angulo = map(valor, 0, 1023, 0, 360);
  	Serial.print("Ángulo: ");
  	Serial.print(angulo);
  	Serial.println(".");
	motor.write(angulo);
	delay(20);

}