# Descripción
Como nueva alcalde de Kitchener, el primer trabajo de Alanna es mejorar las carreteras de
la ciudad.
Las carreteras de Kitchener puede ser representada como un conjunto de $N$ intersecciones
con $M$ calles, donde la calle $i$ tenía longitud $l_i$ metros, cuesta $c_i$ dólares por año para
mantenerla, y conecta las intersecciones $u_i$ y $v_i$. Para crear un plan, Alanna debe selecciones
un subconjunto de $M$ calles para mantener, y el costo de ese plan es la suma del costo de
mantenimiento de todas las calles de ese subconjunto.
Para bajar el gasto anual, Alanna le gustaría minimizar el costo del plan. Sin embargo, la
ciudad requiere que minimice las distancias entre intersecciones y va a rechazar cualquier
plan que no se ajuste a esas reglas. Formalmente, para cualquier par de intersecciones $(i, j)$,
si existe un camino de $i$ a $j$ que tome $l$ metros en el plan existente, el plan de Alanna debe
incluir un camino entre esas intersecciones que tenga a lo mucho $l$ metros.

# Entrada
La primera línea contiene enteros $N$ y $M$.
Cada una de las siguientes $M$ líneas contiene enteros $u_i$, $v_i$, $l_i$, y $c_i$, los cuales implican que
existe una calle formada por la intersección $u_i$ a $v_i$ con longitud $l_i$ con costo $c_i$ ($1 \leq u_i, v_i \leq N, u_i \leq v_i$).

# Salida
Un único entero, el costo mínimo posible de un plan que cumpla con los requerimientos.

# Ejemplo
||input
5 7
1 2 15 1
2 4 9 9
5 2 5 6
4 5 4 4
4 3 3 7
1 3 2 7
1 4 2 1
||output
25
||description
Cada arista está marcada con un par $(l, c)$ denotando que tiene longitud $l$ metros y costo
$c$ dólares. Adicionalmente, las calles que son partes del plan están en azul, con costo total
$7 + 1 + 6 + 7 + 4 = 25$.
Puede ser demostrado que no podemos crear un plan más barato que también respete los
requerimientos de la ciudad.
||end

<br />
![Figura](figura.jpg)
<br />

# Subtarea 1 [20 puntos]
$1 \leq N, M \leq 2000$

$l_i = 0$

$1 \leq c_i \leq 10^9$

Sin restricciones adicionales.

# Subtarea 2 [40 puntos]
$1 \leq N, M \leq 2000$

$1 \leq l_i \leq 10^9$

$1 \leq c_i \leq 10^9$

Hay a lo mucho una calle entre cada par no ordenado de intersecciones.

# Subtarea 3 [40 puntos]
$1 \leq N, M \leq 2000$

$0 \leq l_i \leq 10^9$

$1 \leq c_i \leq 10^9$

Sin restricciones adicionales.
