# Descripción

Dadas dos listas $A$ y $B$ de $n$ y $m$ enteros positivos respectivamente, tu tarea consiste en determinar cuántos enteros positivos $k$ existen tales que:

1. Todos los números de la lista $A$ son factores de $k$.

2. $k$ es un factor de todos los elementos de la lista $B$.

# Entrada

- En la primera línea, dos enteros positivos $n$ y $m$ separados por un espacio, que representan la cantidad de elementos de $A$ y $B$, respectivamente.
- En las siguientes $n$ líneas, un elemento de $A$ en cada línea.
- En las siguientes $m$ líneas, un elemento de $B$ en cada línea.

# Salida

Un único entero postivo $k$ que denota la cantidad de enteros que cumplen las condiciones.

# Ejemplo

||input
2 3
12
20
120
720
600
||output
2
||description
Los únicos dos enteros positivos que cumplen las condiciones son 60 y 120.
||end

# Limites

- $1 \leq n,m \leq 1000$.
- $1 \leq A[i] \leq 10^{18}$.
- $1 \leq B[i] \leq 10^{18}$.

# Subtarea 1 [20 Puntos]
- $1 \leq n,m \leq 10$.
- $1 \leq A[i] \leq 1000$.
- $1 \leq B[i] \leq 1000$.

# Subtarea 2 [80 Puntos]
- Sin restricciones







