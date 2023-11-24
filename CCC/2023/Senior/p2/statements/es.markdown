# Descripción
Rebecca es una guía turística y está intentando publicitar las Rocky Mountains para su
revista. Recientemente le tomó una foto de $N$ montañas donde la $i$-ésima montaña desde la
izquierda tiene una altura $h_i$. Ella va a cortar la foto para su revista, posiblemente cortando
alguna de las montañas desde la izquierda y posiblemente cortando algunas montañas desde
la derecha de la foto. Es decir, la foto cortada consiste de montañas consecutivas empezando
desde la montaña $l$ a la montaña $r$ donde $l \leq r$. Para contentar a sus lectores, Rebecca
intentará encontrar la foto cortada más simétrica.

Mediremos el **valor asimétrico** de un corte como la suma de la diferencia absoluta para todos
los pares de montañas equidistantes desde el medio del corte. Para entender la definición, el
valor absoluto de un número $v$, escrito $|v|$, es el valor no-negativo de $v$. El valor asimétrico
del corte es la suma de todos los $|h_{l+i} − h_{r−i}|$
para $0 \leq i \leq \frac{r-l}{2}$. Para poner la fórmula de otra
manera, agrupamos las montañas desde afuera hacia dentro hacia el centro, calculando la
diferencia de altura de cada par, y los sumamos todos.

Ya que Rebecca no sabe que tan ancha la foto debe ser, hallar el valor asimétrico del corte
más simétrico (el corte con el menor valor asimétrico) para todas las posibles longitudes de
corte.

# Entrada
La primera línea consiste de un entero $N$, representando el número de montañas en la foto.
La segunda línea consiste de $N$ enteros separados por un espacio, donde el entero $i$ desde la
derecha representa la altura $h_i$.

# Salida
Salida es una fila de $N$ enteros separados por espacio, donde el entero $i$ desde la izquierda
es el valor asimétrico de la foto más simétrica del corte de longitud $i$.

# Ejemplo
||input
7
3 1 4 1 5 9 2
||output
0 2 0 5 2 10 10
||description
Explicaremos por qué el quinto valor es 2. Computaremos todos los valores asimétricos de
cortes de longitud 5.
La altura de las montañas en el primer corte es [3, 1, 4, 1, 5]. El valor asimétrico del corte es
$|3 − 5| + |1 − 1| + |4 − 4| = 2$.
La altura de las montañas en el segundo corte es [1, 4, 1, 5, 9]. El valor asimétrico del corte
es $|1 − 9| + |4 − 5| + |1 − 1| = 9$.
La altura de las montañas en el tercer corte es [4, 1, 5, 9, 2]. El valor asimétrico del corte es
$|4 − 2| + |1 − 9| + |5 − 5| = 10$.
Por lo tanto, el valor asimétrico del corte más simétrico de longitud 5 es 2.
||input
4
1 3 5 6
||output
0 1 3 7
||description
Este ejemplo satisface la segunda subtarea. Nota que el corte de longitud 4 es [1, 3, 5, 6] donde el valor asimétrico es $|1 − 6| + |3 − 5| = 7$.
||end

# Subtarea 1 [33 puntos]
$1 \leq N \leq 300$

$0 \leq h_i \leq 10^5$

Sin restricciones adicionales.

# Subtarea 2 [33 puntos]
$1 \leq N \leq 5000$

$0 \leq h_i \leq 10^5$

Las alturas están en orden no-decreciente de izquierda a derecha.

# Subtarea 3 [34 puntos]
$1 \leq N \leq 5000$

$0 \leq h_i \leq 10^5$

Sin restricciones adicionales.

