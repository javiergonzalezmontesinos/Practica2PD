# Práctica 2 Processadors Digitals

# Ejercicio B: Interrupción por Timer

El objetivo de este ejercicio es comprender el funcionamiento de las interrupciones por Timer en un ESP32, utilizando un temporizador para generar interrupciones periódicas y contar el número de interrupciones.

---

## **Descripción del Proyecto**

En este ejercicio, se utiliza un **temporizador (timer)** interno del ESP32 para generar interrupciones periódicas. Cada vez que ocurre una interrupción, se incrementa un contador, y el número total de interrupciones se muestra en el **monitor serie**.

### **Características principales**:
- Uso de un temporizador para generar interrupciones periódicas.
- Contador de interrupciones que se muestra en el monitor serie.
- Manejo de interrupciones en un entorno de multitarea.

---

## **Requisitos**

### **Hardware**
- Placa ESP32.
- **No se requieren componentes externos**: Este ejercicio se basa únicamente en el uso del temporizador interno del ESP32.

### **Software**
- PlatformIO (recomendado) o Arduino IDE.
- Librerías estándar de Arduino para ESP32.

---

## **Configuración del Hardware**

Este ejercicio no requiere hardware adicional, ya que se basa en el uso del temporizador interno del ESP32.


## Ramas del repositorio

**Tanto el ejercicio A como el ejercicio B se encuentran en ramas separadas de este mismo repositorio**