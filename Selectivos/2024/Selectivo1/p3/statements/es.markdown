# Descripción
Los árboles tienen propiedades fascinantes. Esto es verdad en la naturaleza pero también en la computación. Un caso particular de árbol, **perfectamente balanceado** se define de la siguiente forma.
<br/><br/>
Cada árbol perfectamente balanceado tiene un **peso** entero positivo. Un árbol perfectamente balanceado de peso 1 siempre consta de un único nodo. Caso contrario, si el peso de un árbol perfectamente balanceado es $w \geq 2$, el árbol consiste de una raíz con ramas a $k$ **subárboles**, tal que $(2 \leq k \leq w)$. En este caso los $k$ subárboles deben ser idénticos y perfectamente balanceados.
<br/><br/>
En particular, los $k$ subárboles deben tener el mismo peso. Este peso común debe ser el máximo entero positivo tal que la suma de los pesos de los $k$ subárboles no excede $w$, el peso del árbol total. Por ejemplo, si un árbol perfectamente balanceado de peso 8 tiene 3 subárboles, cada uno de los subárboles debe tener peso 2, ya que $2+2+2 = 6 \leq 8$.
<br/><br/>
Dado $N$, halla el número de árboles perfectamente balanceados de peso $N$.

# Entrada
Un único entero positivo $N$ $(2 \leq N \leq 10^{9})$.

# Salida
Un único entero positivo, que representa el número de árboles perfectamente balanceados con peso $N$.

# Ejemplo
||input
4
||output
3
||description
Un árbol tiene una raíz con cuatro subárboles de peso 1; el segundo árbol tiene una raíz con dos subárboles de peso 2; el tercer árbol tiene una raíz con tres subárboles de peso 1.
||input
10
||output
13
||end

# Subtarea 1 [33 puntos]
$N \leq 1000$.

# Subtarea 2 [13 puntos]
$N \leq 50000$.

# Subtarea 3 [13 puntos]
$N \leq 10^{6}$.

# Subtarea 4 [41 puntos]
Sin restricciones.
