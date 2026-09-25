#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int TOUCH_PIN = 4;        
const int UMBRAL_TOUCH = 30;    

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);           

  if (!display.begin(OLED_ADDRESS, true)) {
    Serial.println("Error al iniciar la pantalla OLED");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
}

void loop() {
  int valorTouch = touchRead(TOUCH_PIN);

  Serial.print("Valor Touch: ");
  Serial.println(valorTouch);

  display.clearDisplay();
  display.setTextSize(1);

  display.setCursor(26, 0);
  display.println("ESP32 TOUCH");

  display.setCursor(0, 12);
  display.print("Valor: ");
  display.println(valorTouch);

  if (valorTouch < UMBRAL_TOUCH) {
    display.setCursor(15, 26);
    display.println("TOUCH DETECTADO");
    display.fillCircle(105, 40, 4, SH110X_WHITE);
  } else {
    display.setCursor(32, 26);
    display.println("SIN TOQUE");
    display.fillCircle(20, 40, 4, SH110X_WHITE);
  }

  display.setCursor(0, 48);
  display.println("Carlos H. Ramirez R.");
  display.setCursor(0, 56);
  display.println("00084020");

  display.display();
  delay(100);
}