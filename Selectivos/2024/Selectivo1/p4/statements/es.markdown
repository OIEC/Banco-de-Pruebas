# Descripción
Hace mucho tiempo en una galaxia muy lejana habían $N$ planetas numeradas de 1 al $N$. Cada planeta tiene $M$ ciudades numeradas del 1 al $M$. Denotemos la ciudad $f$ del planeta $e$ como $(e, f)$.
<br/><br/>
Hay $N \times P$ vuelos de ida y vuelta en la galaxia. Para cada planeta $e$ $(1 \leq e \leq N)$, hay $P$ vuelos numerados de 1 a $P$. El vuelo $i$ conecta las ciudades $(e, a_i)$ y $(e, b_i)$ y cuesta $c_i$ energía diaria de mantener.
<br/><br/>
Hay $M \times Q$ portales de ida y vuelta en la galaxia. Para todas las ciudades numeradas $f$ $(1 \leq f \leq M)$ hay $Q$ portales numerados de 1 a $Q$. El portal $j$ conecta las ciudades $(x_i, f)$ y $(y_i, f)$ y cuesta $z_j$ energía diaria de mantener.
<br/><br/>
Es posible viajar entre cada par de ciudades usando solamente vuelos y/o portales.
<br/><br/>
Tiempos duros han llegado a la galaxia. Se decidió que algunos de los vuelos y/o portales cerrarán para conservar energía, pero aún debe ser posible viajar entre cada par de ciudades luego de hacer los ajustes.
<br/><br/>
¿Cuál es la máxima cantidad de energía que se puede ahorrar diariamente?

# Entrada
La primera línea contiene cuatro enteros positivos $N, M, P, Q$ separados por un espacio $(1 \leq N, M, P, Q \leq 10^{5})$.

Luego siguen $P$ líneas, donde la $i$-ésima línea contiene tres enteros positivos $(1 \leq a_i, b_i, \leq N)$ $(1 \leq c_i \leq 10^{8})$.
<br/><br/>
Luego siguen $Q$ líneas, donde la $j$-ésima línea contiene tres enteros positivos $(1 \leq x_i, y_i, \leq N)$ $(1 \leq z_i \leq 10^{8})$.
<br/><br/>
Se garantiza que es posible viajar entre cada dos ciudades usando vuelos y/o portales. Pueden haber múltiples vuelos o partales entre cada par de ciudades o un vuelo o portal entre una ciudad y si misma.

# Salida
Un único entero positivo, que representa la máxima cantidad de energía que puede ser ahorrada diariamente luego de los ajustes.

# Ejemplo
||input
2 2 1 2
1 2 1
2 1 1
2 1 1
||output
3
||input
2 3 4 1
2 3 5
3 2 7
1 2 6
1 1 8
2 1 5
||output
41
||description
Una manera posible es de quitar los vuelos entre las ciudades (1, 1) y (1, 1), (2, 1) y (2, 1), (1, 1)
y (1, 2), (1, 3) y (1, 2), (2, 3) y (2, 2), y quitar los portales entre las ciudades (2, 3) y
(1, 3) para un ahorro de energía de $8 + 8 + 6 + 7 + 7 + 5 = 41$.
||end

# Subtarea 1 [13 puntos]
$P, Q \leq 100$ y $c_i = 1$ para todo $1 \leq i \leq P$, y $z_j = 1$ para cada $1 \leq i \leq Q$.

# Subtarea 2 [13 puntos]
$P, Q \leq 200$.

# Subtarea 3 [33 puntos]
$N, M \leq 200$.

# Subtarea 4 [41 puntos]
Sin restricciones.
