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

Después de clonar este repositorio, debe eliminar la carpeta <strong><em>libopencm3</em></strong> ubicada dentro de la carpeta <strong><em>src</em></strong>, ya que no contiene la biblioteca como tal. Esto es debido a una configuración errónea de git submodule.

Una vez realizado lo anterior y ubicado en la carpeta <em>src</em>, se debe clonar la biblioteca [libopencm3](https://github.com/libopencm3/libopencm3) mediante SSH usando la terminal.

Se ubica en la carpeta <em>libopencm3</em> (recién clonada) y darle <strong><em>make</em></strong> en la terminal.
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
