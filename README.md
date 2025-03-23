# Practica 2 Processadors Digitals

# Ejercicio A: Interrupción por GPIO

El objetivo de este ejercicio es comprender el funcionamiento de las interrupciones por GPIO en un ESP32, utilizando un pulsador para generar interrupciones y contar el número de pulsaciones.

---

## **Descripción del Proyecto**

En este ejercicio, se utiliza un **pulsador** conectado a un pin GPIO del ESP32 para generar interrupciones. Cada vez que se presiona el pulsador, se incrementa un contador de pulsaciones, y el número total de pulsaciones se muestra en el **monitor serie**.

### **Características principales**:
- Uso de interrupciones por GPIO para detectar pulsaciones.
- Contador de pulsaciones que se muestra en el monitor serie.
- Desactivación automática de la interrupción después de 1 minuto.

---

## **Requisitos**

### **Hardware**
- Placa ESP32.
- Pulsador.
- Resistencia pull-up (opcional, ya que se usa la resistencia pull-up interna del ESP32).

### **Software**
- PlatformIO (recomendado) o Arduino IDE.
- Librerías estándar de Arduino para ESP32.

## Ramas del repositorio

**Tanto el ejercicio A como el ejercicio B se encuentran en ramas separadas de este mismo repositorio**