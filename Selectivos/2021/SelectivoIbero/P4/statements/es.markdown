# Descripción
Matrizlandia es una ciudad de $n$ calles horizontales y $n$ calles verticales, muy parecida a una matriz de $n \times n$. Cada calle, horizontal o vertical, cuenta con exactamente $n$ casas. La dirección de cada casa corresponde al par de números de la calle horizontal y vértical donde se encuentra. Por ejemplo, la casa de la esquina superior izquierda tiene como dirección el par de números $(0,0)$ y la de la esquina inferior derecha tiene como dirección el par $(n-1, n-1)$. Además de la dirección, cada casa tiene un tamaño en metros cuadrados, que puede ser representado por un entero positivo. Los ciudadanos son tan ordenados, que construyeron la ciudad de tal forma en cada calle horizontal, las casas están ordenadas de forma ascendente en base a su tamaño. Lo mismo sucede con las calles verticales, las casas también están ordenadas ascendentemente por su tamaño.

Como parte del equipo del municipio de Matrizlandia, te asignan la tarea de censar la $k$-ésima casa más pequeña. En caso de que existan múltiples casas con ese tamaño, te tocará censar todas.
Para darte una idea previa al censo, agarras el mapa de la ciudad y decides que sería útil saber de qué tamaño es la $k$-ésima casa más pequeña.

# Entrada
En la primera línea el valor de $n$.

En la segunda línea el valor de $k$.

Luego seguirán $n$ líneas con $n$ valores enteros separados por un espacio. Cada línea contiene los tamaños de las casas en orden.

# Salida
Una sola línea, con el tamaño de la $k$-ésima casa más pequeña.

# Ejemplo
||input
3
6
1 4 5
2 5 8
2 6 11

||output
5
||end

#Límites
Los tamaños de las casas son menores a $10^8$.

$ 1 \leq n \leq 2500.$

$ 1 \leq k \leq n^2.$

#Subtarea 1 [20 puntos]
$ n < 1000.$

#Subtarea 2 [80 puntos]
Sin restricciones.

# Notas
Por conveniencia, numeramos las calles desde el 0 hasta $n-1$.