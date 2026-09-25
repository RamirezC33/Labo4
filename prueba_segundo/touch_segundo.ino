const int TOUCH_PIN = 4;   // GPIO4 = T0 (pin táctil del ESP32)
const int UMBRAL = 350;     // Ajusta según los valores que veas

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("PRUEBA SENSOR TOUCH");
  Serial.println();
}

void loop() {
  int valorTouch = touchRead(TOUCH_PIN);

  Serial.print("Valor Touch: ");
  Serial.println(valorTouch);

  if (valorTouch < UMBRAL) {
    Serial.println("¡Tocado!");
    Serial.println("Carlos Humberto Ramirez Rodriguez 00084020");
  }

  delay(200);
}