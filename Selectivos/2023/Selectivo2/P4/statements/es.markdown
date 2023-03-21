# Descripción

En el *Juego de los Dígitos* cada paso consiste en arbitrariamente sustraer uno de los dígitos del número que se tiene en ese momento. El juego termina cuando se llega al valor de 0 luego de una cantidad finita de pasos.

Por ejemplo, empezando con el valor de 25, un posible juego puede ir de la siguiente forma:

Restando 2: 25 -> 23
Restando 2: 23 -> 21
Restando 2: 21 -> 19
Restando 1: 19 -> 18
Restando 8: 18 -> 10
Restando 1: 10 -> 9
Restando 9: 9 -> 0.

Este juego tomó 7 pasos hasta llegar a 0, pero es posible escoger los dígitos en cada paso de tal forma que tome 5 pasos:

Restando 5: 25 -> 20
Restando 2: 20 -> 18
Restando 8: 18 -> 10
Restando 1: 10 -> 9
Restando 9: 9 -> 0.

Dada una lista de $n$ números, tu tarea es averiguar cuál es la menor cantidad de pasos necesarios para llegar a 0 para cada uno de los $n$ números de la lista.

# Entrada
La primera línea consta de un entero positivo $n$. La segunda línea contiene $n$ enteros positivos separados por un espacio.
# Salida
$n$ enteros positivos separados por un espacio. Cada valor $n_i$ de la salida representa la menor cantidad de pasos que toma llegar a 0 si el juego empieza con dicho número de la lista.

# Ejemplo
||input
3
25 7 10
||output
5 1 2
||description
- Para 25, toma 5 pasos:
25 -> 20 -> 18 -> 10 -> 9 -> 0.
- Para 7, toma 1 paso: 7 -> 0.
- Para 10, toma 2 pasos: 10 -> 9 -> 0.
||end

# Límites
- $1 < n < 100000$
- $0 < n_i < 100000$

#Subtarea 1 [40 puntos]
 - $n<13000$

#Subtarea 2 [60 puntos]
Sin restricciones.

