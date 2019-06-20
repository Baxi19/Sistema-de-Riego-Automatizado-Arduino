#*********************************************************PROYECTO************************************************************************
Sistema de Riego por goteo Automatizado con Arduino

#*********************************************************RESUMEN DEL PROTOTIPO***********************************************************
#Sitema que analiza la humedad del suelo por medio de un sensor que se encuentra conectado a un Arduino, si el suelo necesita humedad, se activa un relay que permite el paso de corriente a una bomba, esta bomba permite bombear el agua a un sistema de riego por goteo para poder brindar el agua necesaria a las plantas.


#*************************************************CONDICIONES DEL CICLO DE LA APLICACION**************************************************
#Si el sensor esta desconectado, la bomba se mantiene apagada
#Si el sensor esta en un rango mayor que 4 y menor o igual a 10, entonces se activa la bomba para poder hidratar las plantas
#Si el sensor esta en un rango mayor que 10 y menor o igual a 45, entonces se desactiva la bomba porque las plantas tienen la humedad necesaria.
#Si el sensor esta en un rango mayor a 65% de humedad, el arduino va a detectar que el sensor se encuentra practicamente dentro del agua.
