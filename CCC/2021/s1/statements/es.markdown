#Descripción
Necesitas pintar una valla de madera entre tu casa y la de tu vecino. Necesitas determinar el área de la valla, para poder determinar cuánta pintura necesitas usar.
Sin embargo, la valla está hecha de $N$ pedazos de madera no-uniformes, y tu vecino cree que tienen un toque artístico. En particular, las piezas de madera tienen distinta anchura. El lado inferior de cada pedazo de madera es horizontal, ambos lados serán verticales, pero la parte superior puede estar inclinada. A continuación se muestran dos pedazos de madera:

![Figura](figura1.png)

Por suerte, la valla ha sido construida de tal forma que las piezas de madera adyacentes tienen la misma altura en los lados donde se tocan, lo que la hace lucir mejor visualmente.

#Entrada
La primera línea de la entrada contiene un entero positivo $N$ donde $N \leq 10000$.

La segunda línea de entrada contiene $N+1$ enteros separados por un espacio $h_1, . . . , h_{N+1}$ $(1 \leq h_i \leq 100, 1 \leq i \leq N + 1)$ describiendo las alturas de izquierda a derecha, de cada pieza de madera. Específicamente la altura izquierda de la i-ésima pieza de madera es $h_i$ y la altura derecha de la i-ésima pieza de madera es $h_{i+1}$.
La tercera línea de la entrada contendrá $N$ enteros separados por un espacio $w_i$ $(1 \leq w_i \leq 100, 1 \leq i \leq N)$ describiendo el ancho de la $i$-ésima pieza de madera.

#Salida
El área total de la valla.

# Ejemplo
||input
3
2 3 6 2
4 1 1
||output
18.5
||description
Cuando vemos la valla de izquierda a derecha, las áreas individuales delas piezas de madera son 
de $10 = 4 \times (2+3)/2$, $4.5 = 1 \times (3 + 6)/2$, y $4 = 1 \times (6 + 2)/2$, para un área total de 18.5.
||end

![Figura](figura2.png)

||input
4
6 4 9 7 3
5 2 4 1
||output
75
||description
Cuando vemos la valla de izquierda a derecha, las áreas individuales de las piezas de madera son 
de 25, 13, 32, y 5, para un área total de 75.
||end

![Figura](figura3.png)

#Límites
 - $N \leq 10000$
 - $1 \leq h_i \leq 100$, $1 \leq i \leq N + 1$
 - $1 \leq w_i \leq 100$, $1 \leq i \leq N$

