# Semaforo y Alarma con reedswitch y sensor PIR Arduino

Introducción
------------
La siguiente práctica es la unión entre un semáforo peatonal y vehicular con 2 tipos de alarma: magnético y movimiento.

**Semáforo vehicular y peatonal:** El proyecto consiste en un cruce de semáforos, uno de vehículos y otro de peatones. El semáforo de vehículos está normalmente verde (y el de peatones rojo), hasta que algún peatón pulsa el pulsador. Entonces, el amarillo de los vehículos parpadea durante un tiempo prudencial y pasa a rojo. En ese momento el semáforo de peatones pasa a verde y se emite un sonido para indicar el cruce. Tras unos segundos el verde de los peatones pasa a rojo terminando el sonido emitido para cruce. En ese momento el de los vehículos pasa a verde.

**Alarma con reedswitch y PIR:** Se pueden encontrar en los sensores de las puertas y ventanas de las alarmas antirrobo, el imán va unido a la puerta y el reed switch al marco. Vamos a implementar con Arduino una Alarma. Cuando el Reed Switch está en nivel alto debido a la presencia del imán la alarma está desactivada, pero al quitar el imán la alarma se activa haciendo sonar un Buzzer Piezo eléctrico y parpadear un Led. 

**El sensor de movimiento** es un dispositivo electrónico que actúa cuando detecta movimiento en el área vigilada. Sus utilidades son diversas, en algunos casos se utiliza para seguridad y otras como automatización. Dentro de los sensores infrarrojos hay variedades según la utilidad o conveniencia del usuario. Algunos casos se usa para seguridad, por lo tanto estos detectores varían principalmente en la tensión de trabajo.

Objetivo
--------
Realización de programa y circuito de un semáforo vehicular y peatonal poder de cambio al pulsar un botón. Alarma en la cual, al detectar un campo magnético o detecte un movimiento de entrada suene la alarma de aviso y encienda el led correspondiente.

Material
--------
*GENERAL:*
-	Arduino UNO
-	9 resistencias 270 Ω o 330 Ω
  * Semáforo
     - 2 Led rojo
     - 2 led verde
     - 1 led amarillo
     - 1 boton
     - 1 zumbador (buzzer)
  * Alarma
     - Reedswitch
     - Sensor PIR
     - 2 Leds  dediferente color
     - zumbador (buzzer)

**Zumbador (Buzzer)**
Zumbador, buzzer en inglés, es un transductor electroacústico que produce un sonido o zumbido continuo o intermitente de un mismo tono.  Es un tipo de altavoz basado en la propiedades de los cristales piezoeléctricos (poliéster o cerámica), que se deforman cuando se les aplica una tensión entre sus caras y que actuando como transductor electroacústico es utilizado para la reproducción de sonido.

**Reedswitch**
Un reed switch  es un interruptor eléctrico activado por un campo magnético. El campo magnético puede estar generado por un imán permanente o por una bobina. Se pueden encontrar en los sensores de las puertas y ventanas de las alarmas antirrobo, el imán va unido a la puerta y el reed switch al marco.

**Sensor de movimiento PIR**
Los sensores infrarrojos pasivos (PIR) son dispositivos para la detección de movimiento. Son baratos, pequeños, de baja potencia, y fáciles de usar. Por esta razón son frecuentemente usados en juguetes, aplicaciones domóticas o sistemas de seguridad. En realidad cada sensor está dividido en dos campos y se dispone de un circuito eléctrico que compensa ambas mediciones. Si ambos campos reciben la misma cantidad de infrarrojos la señal eléctrica resultante es nula. Por el contrario, si los dos campos realizan una medición diferente, se genera una señal eléctrica. El otro elemento restante para que todo funcione es la óptica del sensor. Básicamente es una cúpula de plástico formada por lentes de fresnel, que divide el espacio en zonas, y enfoca la radiación infrarroja a cada uno de los campos del PIR.

Diagrama de circuito
--------------------

![Imagen_Arduino](/Images/semalarma_bb.png "Diagrama Semaforo y Alarma")


