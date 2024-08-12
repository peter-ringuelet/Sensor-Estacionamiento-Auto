const int trigPin = 6;  // Pin de Trigger del HC-SR04
const int echoPin = 7;  // Pin de Echo del HC-SR04
const int buzzerPin = 8; // Pin para controlar la bocina (buzzer)
long duration;          // Variable para almacenar la duración del pulso de eco
float distance;         // Variable para almacenar la distancia calculada
int delayTime;          // Tiempo de espera entre los parpadeos del buzzer

void setup() {
  pinMode(trigPin, OUTPUT);  // Configurar el pin Trig como salida
  pinMode(echoPin, INPUT);   // Configurar el pin Echo como entrada
  pinMode(buzzerPin, OUTPUT); // Configurar el pin 8 como salida
  Serial.begin(9600);        // Iniciar la comunicación serial a 9600 bps
}

void loop() {
  // Enviar un pulso de 10 microsegundos desde el pin Trig
  digitalWrite(trigPin, LOW);   // Asegurarse de que el pin Trig esté en LOW
  delayMicroseconds(2);         // Esperar 2 microsegundos
  digitalWrite(trigPin, HIGH);  // Enviar un pulso de 10 microsegundos
  delayMicroseconds(10);        // Mantener el pulso durante 10 microsegundos
  digitalWrite(trigPin, LOW);   // Volver el pin Trig a LOW

  // Leer la duración del pulso en el pin Echo
  duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en metros
  distance = duration * 0.034 / 200;

  // Mostrar la distancia en el Monitor Serial
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" m");

  // Si la distancia es menor a 0.5m, ajustar la frecuencia de parpadeo
  if (distance > 0.15 && distance <= 0.5) {
    // Calcular el tiempo de delay basado en la distancia
    delayTime = map(distance * 100, 15, 50, 25, 300); // Mapea la distancia a un rango de 100ms a 1000ms
    digitalWrite(buzzerPin, HIGH);  // Encender la bocina
    delay(delayTime);               // Esperar
    digitalWrite(buzzerPin, LOW);   // Apagar la bocina
    delay(delayTime);               // Esperar
  }  else if (distance <= 0.15 ){
    digitalWrite(buzzerPin, HIGH);
  }
   else {
    digitalWrite(buzzerPin, LOW);   // Asegurarse de que la bocina esté apagada
  }
  delay(50);
}
