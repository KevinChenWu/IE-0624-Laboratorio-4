# Laboratorio 4
Universidad de Costa Rica

Escuela de Ingeniería Eléctrica

IE-0624 Laboratorio de Microcontroladores

III-2022

Estudiante: Kevin Chen Wu

Carné: B92215

Este es el repositorio del Laboratorio 4 para el curso

---
### Observaciones importantes

Después de clonar este repositorio, se debe ubicar en la carpeta <em><strong>src/libopencm3</strong></em> y darle <strong><em>make</em></strong> en la terminal. Esto es para compilar la biblioteca.

Una vez terminada lo anterior, ya puede proceder con la compilación de seismograph.c

---
### Uso del make y script de Python

Se debe ubicar en la carpeta <em>src</em> para realizar todo lo siguiente:

Para compilar el código y cargarlo a la tarjeta, ejecute el siguiente comando en la terminal:
<ul>
<li><strong><em>make seismograph.stlink-flash</em></strong></li>
</ul>

Para establecer la conexión con ThingsBoard, ejecute el siguiente comando en la terminal:
<ul>
<li><strong><em>./iot.py</em></strong></li>
</ul>
