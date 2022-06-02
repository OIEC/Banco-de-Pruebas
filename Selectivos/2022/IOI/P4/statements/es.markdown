# Descripción

Dada una secuencia de matrices (solamente sus dimensiones), tu tarea consiste en hallar la menor cantidad de multiplicaciones que deben ocurrir.
La multiplicación de matrices es asociativa,
por lo que $A(BC) = (AB)C$. Sin embargo, el número de multiplicaciones a realizar es distinto.
Por ejemplo, si $A$ es $10 \times 30$, $B$ es $30 \times 5$
y $C$ es $5 \times 60$. Entonces:

$(AB)C = (10\times30\times5) + (10\times5\times60) = 1500 + 3000 = 4500$ multiplicaciones.


$A(BC) = (30\times5\times60) + (10\times30\times60) = 9000 + 18000 = 27000$ multiplicaciones.

# Entrada

La primera línea consiste en un entero $n$ indicando la cantidad de matrices.
Luego, seguirán $n$ líneas, con 2 enteros $x$ y $y$ por línea separados por un espacio, representando las dimensiones de cada matriz.

# Salida
La salida debe ser un solo número entero indicando el mínimo número de multiplicaciones a ocurrir.

# Ejemplo

||input
3
5 3
3 2
2 1

||output
21

||description
Tenemos 3 matrices, la primera de $5 \times 3$,
la segunda de $3 \times 2$ y la última de $2 \times 1$.
Lo óptimo es primero multiplicar la segunda matriz con la tercera y luego multiplicarla con la primera matriz. Haciendo esto se obtienen
$(3 \times 2 \times 1) + ( 5 \times 3 \times 1) = 21$ multiplicaciones.

||end

# Subtarea 1 [30 puntos]
$N \leq 20$

# Subtarea 2 [70 puntos]
$N \leq 800$

# Notas

**Matriz**

Una matriz de dimensiones $x \times y$ es un arreglo de números con $x$ filas e $y$ columnas.

**Ejemplo**

![matrix](matrix.jpg)

$A$ es una matriz de dimensiones $2 \times 3$ y $B$ una de $3  \times 2$.

**Multiplicación de matrices**

Una matriz $A$ de dimensiones $x\times y$ y otra matriz $B$ de dimensiones $y \times z$
se pueden multiplicar, y su producto es otro matriz $C$ de dimensiones $x \times z$.

Cada elemento del producto está dado por $C_{i,j} = \sum_{k=1}^y A_{i, k} B_{k, j}$.
Por ende, el número total de multiplicaciones que ocurren es $ x \times y \times z$.
