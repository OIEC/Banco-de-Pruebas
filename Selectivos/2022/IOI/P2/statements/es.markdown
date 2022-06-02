# Descripción
Te gustan mucho las matemáticas, pero te gusta más programar patrones matemáticos. De todos, el más divertido para ti es el triángulo de Pascal, pues este sigue un patrón bastante particular: Cada dígito se obtiene sumando los 2 dígitos consecutivos de la fila de arriba, respectivamente. La fórmula para obtener el valor de la posición $x$ en la fila $n$ es 

$$P[n][1] = 1$$
$$P[n][n] = 1$$
$$P[n][x] = P[n-1][x]+P[n-1][x-1]$$

Este es un ejemplo de las primeras cuatro filas del triángulo:
```
   1
  1 1
 1 2 1
1 3 3 1
```
Tu tarea es imprimir la $n$-ésima fila del triángulo de Pascal.

# Entrada
Un entero positivo $n$ indicando la fila que hay que imprimir.

# Salida
La $n$-ésima fila del triángulo de Pascal.

# Límites
$1 \leq n \leq 30$

# Ejemplo
||input
3
||output
1 2 1
||description
La tercera fila del triángulo de Pascal.
||end

# Subtarea 1 [35 puntos]
$n \leq 10$

# Subtarea 2 [65 puntos]
$n \leq 30$
