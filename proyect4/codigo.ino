// Sensor de temperatura
// Led RGB: rojo si temperatura alta, azul si baja

const int sensor = 0; 	// Sensor Temp LM35 en A0
const int ledRojo = 5;		// Patilla roja RGB en pin 5
const int ledAzul = 6; 		// Patilla azul RGB en pin 6


long milivols;
long temperatura;
int brillo;

void setup() {
	Serial.begin(9600);
	pinMode(ledRojo, OUTPUT);
	pinMode(ledAzul, OUTPUT);
}

void loop() {
  
  	long s = analogRead(sensor);
  	Serial.print("Sensor: ");
  	Serial.println(s);
  	// Cálculos según valores del sensor en Tinkercad
  	int tp = map(s, 20, 358, -40, 125);
  	Serial.print("TP: ");
  	Serial.println(tp);
  
  	// Cálculos reales segun especificaciones sensor
	milivols = (s*5000L) / 1023L;
	temperatura = (milivols / 10);

	brillo = map(temperatura, -40, 125, 0, 255);
	brillo = constrain(brillo, 0, 255);

	analogWrite(ledRojo, brillo);
	analogWrite(ledAzul, 255-brillo);

	
	Serial.print("Temperatura: ");
	Serial.print(temperatura);
	Serial.println(" grados");
	delay(500);


}
