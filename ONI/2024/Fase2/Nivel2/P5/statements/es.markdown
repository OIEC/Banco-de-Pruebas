# Descripción
El **Ecuavóley** es una adaptación del deporte voleibol, y fue inventado en Ecuador. Juanito y Pepito son muy fans del ecuavóley.
Cada equipo de la liga de ecuavóley jugó $N$ partidos esta temporada.
Cada partido fue entre dos equipos y el equipo que hizo más puntos ganó el partido. No hubieron empates.
<br/><br/>
El equipo favorito de Juanito son **Los Cóndores**.
Juanito anotó los resultados de todos sus partidos en una cadena de caracteres $S$.
$S_i = W$ si los Cóndores ganaron su partido $i$ o $S_i = L$ si los Cóndores perdieron su partido $i$.
También anotó la cantidad de puntos $A_i$ que los Cóndores hicieron en el partido $i$.
<br/><br/>
El equipo favorito de Pepito son **Las Iguanas**.
Pepito anotó los resultados de todos sus partidos en una cadena de caracteres $T$.
$T_i = W$ si las Iguanas ganaron su partido $i$ o $T_i = L$ si las Iguanas perdieron su partido $i$.
También anotó la cantidad de puntos $B_i$ que las Iguanas hicieron en el partido $i$.
<br/><br/>
Juanito y Pepito anotaron los resultados y los puntos en el orden en que sus equipos favoritos jugaron.
<br/><br/>
Un **clásico** es un partido en el que los Cóndores y las Iguanas se enfrentaron entre sí.
Ya que ni Juanito ni Pepito anotaron los oponentes a los que sus equipos se enfrentaron, no están seguros acerca de cuáles partidos (si es que existieron),
fueron clásicos. Se preguntan cuál es la máxima cantidad posible de puntos hechos por ambos equipos en partidos clásicos con la información que anotaron.

# Entrada
La primera línea contiene un número $N$ $(1 \leq N \leq 1000)$ que representa la cantidad de partidos.

La segunda línea contiene la cadena $S$ de longitud $N$ con caracteres $W$ y $L$ como se explicó previamente.

La tercera línea contiene $N$ enteros $A_1 , \cdots, A_N$ $(1 \leq A_i \leq 1000000)$ que representan los puntajes de los Cóndores en cada partido.

La cuarta línea contiene la cadena $T$ de longitud $N$ con caracteres $W$ y $L$ como se explicó previamente.

La quinta línea contiene $N$ enteros $B_1 , \cdots, B_N$ $(1 \leq B_i \leq 1000000)$ que representan los puntajes de las Iguanas en cada partido.

# Salida
Un único entero que representa la máxima cantidad posible de puntos hechos por ambos equipos en partidos clásicos.

# Ejemplo
||input
1
W
2
W
3
||output
0
||description
Ambos equipos ganaron sus partidos por lo que no pudieron haber existido clásicos.
||input
4
WLLW
1 2 3 4
LWWL
6 5 3 2
||output
14
||description
El cuarto partido de cada equipo pudo haber sido un clásico en el que los Cóndores ganaron 4 a 2. El tercer partido de los Cóndores y el segundo partido de las Iguanas pudo haber sido un clásico donde las Iguanas ganaron 5 a 3. Los puntos totales en clásicos son $4 + 2 + 5 + 3 = 14$ y este es el máximo posible.

Nótese que el primer partido de los Cóndores fue una victoria por 1 punto. Este partido no puede ser contra las Iguanas, ya que en ningún partido las Iguanas anotaron 0 puntos. De la misma manera, el primer partido de las Iguanas no puede haber sido contra los Cóndores, ya que las Iguanas perdieron e hicieron 6 puntos, y en ningún partido los Cóndores hicieron 7 puntos o más.
||end

# Subtarea 1 [40 puntos]
$N \leq 10$.

# Subtarea 2 [60 puntos]
Sin restricciones.

# Nota
Para este problema no asumas ninguna regla real del ecuavóley, solamente que gana el equipo que anota más puntos al final del intervalo de tiempo del partido.
