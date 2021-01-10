# Descripción
La época de pandemia te tiene aburrido y una tarde, ya desesperado, decidiste jugar con puntos en el plano cartesiano. Empezaste con 11 puntos en el plano, y teniendo una atracción desmedida por el equilibrio y el balance, quisiste dividirlos en conjuntos de igual cantidad. Para lograr tu objetivo, trazaste una recta desde el origen a uno de los puntos. De esta forma conseguiste que el plano quedara dividido en dos partes, ambas con 5 puntos en su interior, como se muestra en la figura:

![Figura](figura.png)

Luego de seguir experimentando con distintos puntos e incrementando la cantidad de puntos, te preguntas si esta tarea puede ser automatizada.

# Entrada
Una línea con un entero positivo impar $n$ indicando el número de puntos.
Luego seguirán $n$ líneas, con 2 números (de tipo float) por línea separados por un espacio, representando las coordenadas de cada punto en el plano cartesiano.

# Salida
Una única línea con las 2 coordenadas del punto deseado, separadas por un espacio y redondeadas a 4 decimales. El punto de la salida es el único punto que al formar una recta con el origen, divide al conjunto de puntos en dos subconjuntos de igual tamaño a ambos lados de la recta.

# Ejemplo
||input
5
1.4 -40.1
45.5 37.4
48.3 -5.7
16 -9.1
20.7 49.4
||output
48.3000 -5.7000
||end

#Límites
$ n < 300000 $

$ 0  \leq x_{i} < 100$

$ -200000 \leq y_{i} < 200000 $


#Subtarea 1 [70 puntos]
$ n < 1000 $

#Subtarea 2 [30 puntos]
Sin restricciones.

#Notas
Se garantiza que el punto deseado sea único.





