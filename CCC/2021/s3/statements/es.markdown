#Descripción
Llegó la hora del almuerzo en tu escuela. Tus $N$ amigos están parados en una cancha larga, como siempre. La cancha puede ser representada como una recta numérica, con el amigo número $i$ inicialmente en la posición de $P_i$ metros en la recta numérica.  El amigo $i$ puede caminar en cualquier dirección en la cancha a 1 metro por $W_i$ segundos, y su oído es lo suficientemente bueno para poder escuchar música hasta $D_i$ metros desde su posición. Múltiples estudiantes pueden ocupar la misma posición en la cancha, inicialmente y luego si están caminando también.
Vas a tener un pequeño concierto en una posición de $c$ metros en la cancha (donde $c$ es un entero decidido por ti), y les envías un mensaje a tus amigos. Una vez hecho esto, cada uno camina a lo largo de la cancha por la mínima cantidad de tiempo de tal forma que ellos terminan siendo capaces de escuchar tu concierto (en otras palabras, que cada amigo $i$ termina en $D_i$ distancia de $c$).
Te gustaría escoger $c$ que minimice la suma de todos los tiempos de caminata de tus $N$ amigos. ¿Cuál es la mínima suma (en segundos)? Por favor nota que el resultado quizá no quepa en un entero de 32 bits.

#Entrada
La primera línea contiene el valor de $N$.
Las siguientes $N$ líneas contienen tres enteros separados por un espacio $P_i, W_i$ y $D_i$ $(1 \leq i \leq N)$.

#Salida
Un entero que es la mínima suma de tiempos de caminata (en segundos) para todos tus $N$ amigos, de tal forma que puedan escuchar tu concierto.

# Ejemplo
||input
1
0 1000 0
||output
0
||description
Si tomas $c = 0$, tu único amigo no necesita caminar para nada para escucharte.
||end

||input
2
10 4 3
20 4 2
||output
20
||description
Un posible $c$ óptimo es 14, ya que requeriría tu primer amigo de caminar hasta la posición 11 (tomando $4 \times 1 = 4$ segundos) y a tu segundo amigo de caminar a la posición 16 (tomando $4 \times 4 = 16$ segundos), para un total de 20 segundos.
||end

||input
3
6 8 3
1 4 1
14 5 2
||output
43
||end


#Límites
 - $1 \leq N \leq 200000$ 
 - $0 \leq P_i \leq 1000000000$
 - $1 \leq W_i \leq 1000$
 - $0 \leq D_i \leq 1000000000$

#Subtarea 1 [27 puntos]
$N \leq 2000$, $P_i \leq 2000$, $W_i \leq 1000$, $D_i \leq 2000$

#Subtarea 2 [60 puntos]
$N \leq 200000$, $P_i \leq 1000000$, $W_i \leq 1000$, $D_i \leq 1000000$

#Subtarea 3 [13 puntos]
Sin restricciones.

