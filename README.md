#**Instituto Tecnológico de Costa Rica**

#**Campus Tecnológico Local San Carlos**

#**Escuela de Ingeniería en computación**

#**Profesor: Jorge Alfaro**

#**Estudiante: Randald Villegas**

#**Proyecto:**

Sistema de Riego por goteo Automatizado con Arduino

#**Resumen del Prototipo:**

Sitema que analiza la humedad del suelo por medio de un sensor que se encuentra conectado a un Arduino, si el suelo necesita humedad, se activa un relay que permite el paso de corriente a una bomba, esta bomba permite bombear el agua a un sistema de riego por goteo para poder brindar el agua necesaria a las plantas.


#**Condiciones del ciclo de la aplicación:**

1-Si el sensor esta desconectado, la bomba se mantiene apagada.

2-Si el sensor esta en un rango mayor que 4 y menor o igual a 10, entonces se activa la bomba para poder hidratar las plantas.

3-Si el sensor esta en un rango mayor que 10 y menor o igual a 45, entonces se desactiva la bomba porque las plantas tienen la humedad. necesaria.

4-Si el sensor esta en un rango mayor a 65% de humedad, el arduino va a detectar que el sensor se encuentra practicamente dentro del agua.
