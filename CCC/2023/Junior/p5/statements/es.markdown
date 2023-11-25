# Descripción

En el cazapalabra de la CCC, las palabras están escondidas en un tablero de letras. Las letras de una palabra escondida siempre aparecen en orden en segmentos horizontales, verticales o diagonales en una de dos formas. Una de las formas es que las letras de la palabra aparezcan en un mismo segmento. La otra forma es que las letras de la palabra en un segmento hasta una cierta letra y luego en una segunda línea que forma un ángulo recto en esa letra.

Dada un tablero de letras y una palabra para buscar, tu tarea es determinar la cantidad de veces que esa palabra está escondida en el tablero.

# Entrada
La primera línea de la entrada contiene una cadena de caracteres $W$ de distintas letras mayúsculas que representa la palabra a buscar en el tablero. La longitud de la palabra $W$ es al menos dos. La segunda línea de la entrada es un entero $R$ ($1 \leq R \leq 100$), donde $R$ es el número de filas del tablero. La tercera línea contiene un entero $C$ ($1 \leq C \leq 100$) donde $C$ es el número de columnas en el tablero. Luego vienen $R$ líneas donde cada una contiene $C$ letras mayúsculas separadas por espacio que representan las letras del tablero.

# Salida
Un único entero no negativo $H$, que representa el número de veces que la palabra está escondida en el tablero.

# Ejemplo
||input
MENU
5
7
F T R U B L K
P M N A X C U
A E R C N E O
M N E U A R M
M U N E M N S
||output
3
||description
La palabra MENU aparece 3 veces en el tablero. Una vez horizontalmente, una vez verticalmente y una vez diagonalmente como se muestra.
Note que una letra puede ser usada varias veces.
||end

<br />
![Figura1](figura1.jpg)
<br />

||input
NATURE
6
9
N A T S F E G Q N
S A I B M R H F A
C F T J C U C L T
K B H U P T A N U
D P R R R J D I R
I E E K M E G B E
||output
4
||description
La palabra NATURE aparece 4 veces en el tablero. Una diagonal, una vertical y dos veces en segmentos perpendiculares.
||end

<br />
![Figura2](figura2.jpg)
<br />

# Subtarea 1 [13 puntos]
Las palabras de encuentran en segmentos horizontales solamente.

# Subtarea 2 [13 puntos]
Las palabras de encuentran en segmentos horizontales o verticales solamente.

# Subtarea 3 [13 puntos]
Las palabras de encuentran en segmentos horizontales, verticales o diagonales solamente.

# Subtarea 4 [61 puntos]
Sin restricciones.
