# Descripción
El imperio ancestral incaico constaba de $N$ villas ubicadas en distintos puntos de una línea recta. Cada una de estas villas está representada por una posición entera en dicha línea.
<br/><br/>
Cada villa define su **vecindario** como todos los puntos en la línea que están más cerca de esa villa que cualquier otra villa. Un punto que esté igual de cerca de dos villas $A$ y $B$ está en el vecindario de ambas villas $A$ y $B$.
<br/><br/>
Cada vecindario tiene un tamaño que es la diferencia entre el mínimo punto del vecindario (de la izquierda) y el máximo punto del vecindario (de la derecha).
Los vecindarios de las villas de los extremos izquierdos y derechos se definen como que tienen tamaño infinito, mientras que todos los otros vecindarios tienen tamaño finito.
<br/><br/>
Determina el menor tamaño entre todos los vecindarios (con exactamente 1 punto decimal).

# Entrada
La primera línea contiene un número $N$ $(3 \leq N \leq 100000)$ que representa el número de villas. En las siguientes $N$ líneas tendremos un entero por línea, donde la línea $i$ contiene un entero $V_i$ que representa la posición de la villa $i$ $(-1000000000 \leq V_i \leq 1000000000)$. Todas las villas están en distintas posiciones.

# Salida
Un único valor que representa el menor tamaño entre todos los vecindarios, con exactamente 1 punto decimal.

# Ejemplo
||input
5
16
0
10
4
15
||output
3.0
||description
Los vecindarios de la villa 0 y 16 son infinitos. El vecindario de la villa 4 mide 5 unidades (2 a la izquierda y 3 a la derecha). El vecindario de la villa 10 mide 5.5 unidades (3 a la izquierda y 2.5 a la derecha). El vecindario de la villa 15 mide 3.0 unidades (2.5 a la izquierda y 0.5 a la derecha).
<br />
![Figura1](Figura1.png)
<br />
||end

# Subtarea 1 [50 puntos]
$N \leq 100$.

# Subtarea 2 [50 puntos]
Sin restricciones.

# Nota

Para imprimir valores con un punto decimal puedes usar printf("%.1f\n", x) si estás usando C++ y la variable x es de tipo double.
<br/><br/>
Si estás usando Java, usa System.out.printf("%.1f", x) si la variable x es de tipo double.
<br/><br/>
Si estás usando Python puedes usar print(round(x, 1)).
<br/><br/>
Para cualquier otro lenguaje de programación, consulta la referencia oficial del mismo.
