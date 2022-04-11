# Descripción
Dado un entero $n$ y un arreglo de $m$ enteros positivos distintos, debes encontrar la cantidad de maneras de sumar $n$ usando los números del arreglo tomando en cuenta el orden de los sumandos, es decir, la suma $1+2$ y $2+1$ se consideran diferentes.


# Entrada
- En la primera línea, un número entero positivo $n$.
- En la segunda línea, un número entero positivo $m$ que representa la cantidad de números en el arreglo.
- En la tercera línea, un arreglo de $m$ números enteros positivos distintos separados por un espacio.

# Salida
- La cantidad de maneras de sumar $n$ usando los números del arreglo.

# Ejemplo
||input
4
3
1 2 3
||output
7
||description
Las sumas posibles son: $1+1+1+1$, $2+2$, $1+3$, $1+1+2$, $1+2+1$, $2+1+1$, y $3+1$.
||end


# Limites
- $n \leq 100$.
- $m \leq 20$.
- La salida está dentro de los límites de `int`.

# Subtareas
## Subtarea 1 [40 Puntos]
- $n < 10$

## Subtarea 2 [60 Puntos]
- Sin restricciones
