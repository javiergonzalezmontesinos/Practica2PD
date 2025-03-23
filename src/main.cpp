#include <Arduino.h>

volatile int interruptCounter;
int totalInterruptCounter;

hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer() {
    portENTER_CRITICAL_ISR(&timerMux);
    interruptCounter++;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void setup() {
    Serial.begin(115200);

    // Configura el temporizador
    timer = timerBegin(0, 80, true);  // Timer 0, prescaler 80 (1 MHz), cuenta ascendente
    timerAttachInterrupt(timer, &onTimer, true);  // Asocia la función de interrupción
    timerAlarmWrite(timer, 1000000, true);  // Configura el periodo del timer en microsegundos (1 segundo)
    timerAlarmEnable(timer);  // Habilita el temporizador
}

void loop() {
    if (interruptCounter > 0) {
        portENTER_CRITICAL(&timerMux);
        interruptCounter--;
        portEXIT_CRITICAL(&timerMux);

        totalInterruptCounter++;
        Serial.print("An interrupt has occurred. Total number: ");
        Serial.println(totalInterruptCounter);
    }
}