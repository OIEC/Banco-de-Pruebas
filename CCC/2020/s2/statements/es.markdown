#Descripción
Tu tarea es determinar si es posible escapar de un cuarto. El cuarto es un tablero de $M \times N$ donde cada celda contiene un entero positivo. Las filas están numeradas de 1 a M y las columnas están numeradas de 1 a N. Usamos la notación $(r, c)$ para referirnos a la celda en la fila $r$ y columna $c$.

Empiezas en la esquina superior izquierda con coordenada $(1, 1)$ y la salida está en la esquina inferior derecha en $(M, N)$. Si estás en una celda que contiene el valor $x$, puedes saltar a cualquier celda $(a, b)$ que cumpla que $a \times b = x$. Por ejemplo, si te encuentras en una celda con el valor de 6, puedes saltar a la celda $(2, 3)$.

Nota que en una celda que contiene 6, hay hasta 4 celdas a las que puedes saltar: $(2, 3)$, $(3, 2)$, $(1, 6)$ o $(6, 1)$. Si el cuarto es un tablero de $5 \times 6$, no hay una fila 6, entonces solo los primeros 3 saltos serían posibles.


#Entrada
La primera línea es un entero $M$.

La segunda línea es un entero $N$.

El resto de la entrada son los enteros positivos en los casilleros del tablero con $M$ filas y $N$ columnas. Consiste de $M$ líneas donde cada una consta de $N$ enteros positivos, cada uno menor a 1000000, separados por un espacio.


#Salida
Imprimir "yes" en el caso de que se pueda escapar del cuarto. De lo contrario imprimir "no".

#Límites
- $M (1 \leq M \leq 1000)$
- $N (1 \leq N \leq 1000)$

# Ejemplo
||input
3
4
3 10  8 14
1 11 12 12
6  2  3  9
||output
Posible
||description
Empezando en la celda $(1, 1)$ que contiene un 3, una posibilidad es saltar a la celda $(1, 3)$. Esta celda contiene un 8, por lo que puedes saltar a la celda $(2, 4)$. Esto te lleva a una celda que contiene 12 con la cual puedes llegar a la salida en $(3, 4)$.
||end

#Subtarea 1 [6 puntos]
$M = 2$ y $N = 2$.

#Subtarea 2 [13 puntos]
$M = 1$.

#Subtarea 3 [27 puntos]
Todos los enteros de las celdas son únicos.

#Subtarea 4 [27 puntos]
$M \leq 200$ y $N \leq 200$.

#Subtarea 5 [27 puntos]
Sin restricciones.
