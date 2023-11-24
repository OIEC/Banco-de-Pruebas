# Descripción
Alicia la matemática le gusta estudiar los números reales que existen entre 0 y 1. Su herramienta favorita es el filtro.
Un filtro cubre parte de la recta numérica. Cuando un número se encuentra con un filtro,
pueden suceder dos cosas: Si el número no está cubierto por el filtro, el número pasa por el
filtro. Si el número está cubierto por el filtro, será removida.
Alicia tiene infinitos filtros. Sus 3 filtros se ven de esta forma:

<br />
![Figura](figura.jpg)
<br />

En general, el filtro $k$ puede ser definida de la siguiente forma:

 - Considera la recta numérica del 0 a 1.
 - Particiona la recta numérica entre $3k$ partes iguales. Quedan $3k + 1$ puntos y $3k$
intervalos.
 - El filtro $k$ consiste del 2ndo intervalo, 5to intervalo, 8vo intervalo, y en general, el
$(3i −1)$mo intervalo. Los puntos no forman parte del filtro $k$.

Alicia tiene instrucciones para construir el set de Cantor. Comienza con la recta numérica
del 0 a 1. Aplica todos los filtro a la recta numérica y quita los números que fueron cubiertos.
Los números que quedan son el set de Cantor.
Alicia quiere investigar el set de Cantor y te pide ayuda. Dado un entero $N$, a Alicia le
gustaría saber cual fracción $\frac{x}{N}$ están en el set de Cantor.


# Entrada
La primera línea contiene un entero $N$.

# Salida
Imprimir todos los enteros $x$ donde $0 \leq x \leq N$ y $\frac{x}{N}$ está en el set de Cantor.
Imprimir todas las respuestas en orden creciente. Las respuestas no exceden $10^{6}$.

# Ejemplo
||input
12
||output
0
1
3
4
8
9
11
12
||description
$\frac{5}{12}$, $\frac{6}{12}$ y $\frac{7}{12}$ no están en el set de Cantor porque están cubiertos por el 1er filtro.
Más aún, $\frac{2}{12}$ y $\frac{10}{12}$ no están en el set de Cantor porque están cubiertos por el 2do filtro.
Puede ser demostrado que todas las fracciones que quedan pasan por todos los filtros.
||end

<br />
![Figura2](figura2.jpg)
<br />

# Subtarea 1 [20 puntos]
$3 \leq N \leq 3^{18}$

$N$ es una potencia de 3.

# Subtarea 2 [27 puntos]
$2 \leq N \leq 10^{5}$

Sin restricciones adicionales.

# Subtarea 3 [53 puntos]
$2 \leq N \leq 10^{9}$

Sin restricciones adicionales.
