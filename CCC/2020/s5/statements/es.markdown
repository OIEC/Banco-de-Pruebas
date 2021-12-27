#Descripción
De camino a una olimpiada, José, su entrenador, y sus $N-2$ compañeros de equipo deciden hacer una parada en un puesto de hamburguesas que ofrece $M$ opciones distintas de platos. Después de decidir qué hamburguesas van a pedir, los miembros del equipo se alinean, con el entrenador en la primera posición y José en la última, para finalmente realizar la orden. Desafortunadamente el entrenador olvida su elección de hamburguesa, así que escoge una al azar y se va. Los otros miembros del equipo, ordenadamente, eligen su hamburguesa favorita si está disponible, o una al azar si ya no hay más. ¿Cuál es la probabilidad de que José, siendo el último en la fila, logre comer su hamburguesa favorita?

#Entrada
La primera línea contiene un número $N$ que representa el número total de personas y hamburguesas.

La siguiente línea contiene $N$ números, siendo $b_i$, el término $i$, que denota el número del item de la hamburguesa favorita de la persona en posición $i$.

La primera persona en la fila es el entrenador y la última es José.

#Salida
Un solo número $P$, la probabilidad de que José pueda ordenar su hamburguesa favorita, $b_N$. 

Si la respuesta correcta es $C$, se considerará correcta una respuesta $P$, tal que $|P-C|<10^{-6}$.

# Ejemplo
||input
3
1 2 3
||output
0.5
||description
El entrenador escoge aleatoriamente entre tres hamburguesas. 
Con $1/3$ de probabilidad, él escoge su hamburguesa favorita (hamburguesa 1), y José puede comer su hamburguesa favorita (hamburguesa 3).

 Con probabilidad de $1/3$, escoge la hamburguesa favorita de José y José se queda sin comer su hamburguesa favorita. 

Con probabilidad $1/3$, escoge la hamburguesa favorita de la segunda persona; hay una probabilidad de $1/2$ que la segunda persona escoja la hamburguesa favorita de José, dejándolo sin comer su hamburguesa favorita.
||input
7
1 2 3 1 1 2 3
||output
0.57142857
||description
||end

#Límites
- $3 \leq N \leq 1000000$

#Subtarea 1 [35 puntos]
$N \leq 100000$ y $M \leq 1000$.

#Subtarea 2 [35 puntos]
$M \leq 5000$.

#Subtarea 3 [30 puntos]
Sin restricciones
