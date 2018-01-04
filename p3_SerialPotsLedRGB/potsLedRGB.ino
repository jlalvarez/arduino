// Comunicación Serial con Led RGB controlado por tres potenciometros

const int ledRojo = 6; 		// Patilla rojo RGB en pin 6
const int ledAzul = 5;		// Patilla azul RGB en pin 5
const int ledVerde = 3; 	// Patilla verde RGB en pin 3	

const int potRojo=0;	// Potenciometro rojo en A0
const int potAzul=1;	// Potenciometro azul en A1
const int potVerde=2;	// Potenciometro verde en A2

int crojo = 0;
int cazul = 0;
int cverde = 0;

void setup() {
	Serial.begin(9600);
	pinMode(ledRojo, OUTPUT);
	pinMode(ledAzul, OUTPUT);
  	pinMode(ledVerde, OUTPUT);
}

void loop() {
  
  	int crojo = analogRead(potRojo) / 4;
  	int cazul = analogRead(potAzul) / 4;
  	int cverde = analogRead(potVerde) / 4;
  
  	analogWrite(ledRojo, crojo);
  	analogWrite(ledAzul, cazul);
  	analogWrite(ledVerde, cverde);
  
  	Serial.print("RGB: (");
  	Serial.print(crojo);
  	Serial.print(", ");
  	Serial.print(cazul);
  	Serial.print(", ");
  	Serial.print(cverde);
  	Serial.println(").");

	delay(500);


}