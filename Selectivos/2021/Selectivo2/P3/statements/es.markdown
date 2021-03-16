# Descripción

Últimamente has estado estudiando matemáticas y te tiene asombrado la conjetura de los primos gemelos, que dice lo siguiente:

"Existe un número infinito de primos $p$ tales que $p+2$ también es primo."

No puedes comprender cómo es posible que esta aseveración no ha sido demostrada. De hecho, estás convencido de que no solamente se cumple para $p$ y $p+2$, sino que se cumple para $p$ y $p+d$, para cualquier valor de $d$ par. Una noche, sin poder dormir pensando en esta conjetura, te lanzas a escribir un programa que de todas las parejas de primos con diferencia $d$, donde $d$ es cualquier entero positivo (no necesariamente par).

# Entrada
En la primera línea el valor de $n$.

En la segunda línea el valor de $d$ (no necesariamente par).

# Salida
Todas las parejas de primos menores a $n$ con diferencia $d$. Cada línea consiste de dos números separados por un espacio, representando una pareja de números con diferencia $d$, con el primer número siendo el menor de la pareja. La salida debe cumplir que el primer número de cada línea es menor al primer número de la línea siguiente.


# Ejemplo
||input
10
2
||output
3 5
5 7
||description
Las 2 parejas de números primos menores a 10 con diferencia 2 son (3, 5) y (5, 7).
||end

#Límites
$n \leq 10000000$.

$d \leq 10000000$.

#Subtarea 1 [10 puntos]
$n \leq 50000, d = 2$.

#Subtarea 2 [10 puntos]
$n \leq 500000, d = 2$.

#Subtarea 3 [10 puntos]
$d = 2$.

#Subtarea 4 [10 puntos]
$n \leq 50000, d \leq 50000$.

#Subtarea 5 [20 puntos]
$n \leq 500000, d \leq 500000$.

#Subtarea 6 [40 puntos]
Sin restricciones.

#Notas
Puedes asumir que la salida siempre tendrá al menos una pareja de primos.