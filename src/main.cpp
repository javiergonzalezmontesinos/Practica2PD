#include <Arduino.h>

// Definimos una estructura para manejar el pulsador
struct Button {
  const uint8_t PIN;           // Pin al que está conectado el pulsador
  uint32_t numberKeyPresses;   // Contador de veces que se ha presionado el pulsador
  bool pressed;                // Indica si el pulsador ha sido presionado
};

// Creamos una instancia de la estructura Button para el pulsador
Button button1 = {18, 0, false};

// Rutina de servicio de interrupción (ISR)
void IRAM_ATTR isr() {
  button1.numberKeyPresses += 1;  // Incrementamos el contador de pulsaciones
  button1.pressed = true;         // Marcamos el pulsador como presionado
}

void setup() {
  Serial.begin(115200);  // Inicializamos la comunicación serial

  // Configuramos el pin del pulsador como entrada con resistencia pull-up
  pinMode(button1.PIN, INPUT_PULLUP);

  // Asociamos la interrupción al pin del pulsador
  // La interrupción se generará en un flanco de bajada (FALLING)
  attachInterrupt(button1.PIN, isr, FALLING);
}

void loop() {
  // Si el pulsador ha sido presionado
  if (button1.pressed) {
      // Mostramos en el monitor serie cuántas veces se ha presionado el pulsador
      Serial.printf("Button 1 has been pressed %u times\n", button1.numberKeyPresses);

      // Marcamos el pulsador como no presionado para evitar múltiples detecciones
      button1.pressed = false;
  }

  // Después de 1 minuto, desactivamos la interrupción
  static uint32_t lastMillis = 0;
  if (millis() - lastMillis > 60000) {
      lastMillis = millis();
      detachInterrupt(button1.PIN);  // Desactivamos la interrupción
      Serial.println("Interrupt Detached!");
  }
}