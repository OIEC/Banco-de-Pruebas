# Descripción
Se tiene una matriz de $n$ x $n$, en la que se puede hacer 3 tipos de operaciones, usando los comandos $F$, $C$, y $G$, con las siguientes reglas:

- El comando $F$ permite intercambiar filas.
- El comando $C$ permite intercambiar columnas.
- El comando $G$ permite transponer la matriz.

Tu trabajo es hallar la matriz resultante después de haber realizado las operaciones dadas. Por ejemplo: $F$ $1$ $2$, intercambia la fila 1 con la fila 2, $C$ $1$ $2$, intercambia la columna 1 con la columna 2, y $G$ transpone la matriz.

# Notas
La transpuesta de una matriz es una operación en la cual cada fila se intercambia por la respectiva columna, es decir, la fila 1 se intercambia por la columna 1, la fila 2 por la columna 2, y así sucesivamente. Por ejemplo dada una matriz de $3 \times 3$:

```
1 2 3
4 5 6
7 8 9
```
Al transponerla da como resultado:
```
1 4 7
2 5 8
3 6 9
```


# Entrada
- En la primera línea, dos enteros $n$ y $k$, que representan las dimensiones de la matriz y el número de operaciones respectivamente.
- Luego, $n$ líneas con $n$ enteros cada una para formar la matriz.
- Finalmente, $k$ líneas compuestas de 3 elementos: Un caracter que puede ser $G$, $F$, $C$, dependiendo de la operación a realizar, y 2 enteros que representan las filas o columnas a intercambiar en caso de que el caracter sea $F$ o $C$, si es $G$, la línea solo contendrá el caracter $G$.

# Salida
La matriz resultante de las operaciones aplicadas.

# Ejemplo
||input
3 3
1 2 3
4 5 6
7 8 9
F 1 2
C 1 2
G
||output
5 2 8
4 1 7
6 3 9
||description
La primera transformación intercambia la fila 1 con la fila 2:
```
4 5 6
1 2 3
7 8 9
```
La segunda transformación intercambia la columna 1 con la columna 2:
```
5 4 6
2 1 3
8 7 9
```
Finalmente, la tercera transformación transpone la matriz.
```
5 2 8
4 1 7
6 3 9
```
||end
#Límites
- $2 < n < 10000$
- $1 < k < 500$

#Subtareas
## Subtarea 1 [30 puntos]
- Únicamente operaciones para intercambiar filas de la matriz.

## Subtarea 2 [30 puntos]
- Operaciones para intercambiar filas y columnas.

## Subtarea 3 [40 puntos]
- Todas las operaciones disponibles.
