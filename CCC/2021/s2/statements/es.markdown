#Descripción
Un artista contemporáneo tiene una forma única de crear patrones cuadriculados. La idea es usar un lienzo de $M$ por $N$ que inicialmente es totalmente negro. El artista hace una elección repetitivamente donde escoge una fila o una columna y le pasa su pincel mágico a dicha fila o columna. El pincel cambia el color de cada fila o columna de negro a dorado o de dorado a negro.
Dadas las elecciones del artista, tu tarea es determinar cuánto dorado aparece en el patrón cuadriculado luego de aplicarle las elecciones del artista.

#Entrada
La primera línea contiene un entero positivo $M$. La segunda línea contiene un entero positivo $N$. La tercera línea contiene un entero positivo $K$. El resto de la entrada, contiene $K$ líneas que representan las elecciones del artista. Cada una de estas líneas será una letra 'R' seguida de un espacio y luego un entero que representa el número de Fila, o una letra 'C' seguida de un espacio por un entero que representa el número de la columna. Las filas están numeradas de arriba a abajo del 1 al $M$. Las columnas están numeradas de izquierda a derecha del 1 al $N$.

#Salida
Un entero no-negativo que es igual al número de casillas que están pintadas de dorado en el patrón cuadriculado determinadas por las elecciones del artista.

# Ejemplo
||input
3
3
2
R 1
C 1
||output
4
||description
Luego de pasar el pincel por la primera fila, el lienzo queda así (G es dorado o gold, B es negro o black):

GGG 

BBB

BBB

Luego de pasar el pincel por la primera columna, cuatro de las casillas son doradas en el patrón cuadriculado determinadas por las elecciones del artista:

BGG 

GBB

GBB

||end

||input
4
5
7
R 3
C 1
C 2
R 2
R 2
C 1
R 4
||output
10
||description
Diez de las casillas son doradas en el patrón cuadriculado determinadas por las elecciones del artista:

BGBBB

BGBBB

GBGGG

GBGGG

||end


#Límites
 - $MN \leq 5000000$
 - $K \leq 1000000$

#Subtarea 1 [7 puntos]
$M = 1, N = 1, K \leq 100$ 

#Subtarea 2 [27 puntos]
$M = 1, N \leq 100, K \leq 100$

#Subtarea 3 [33 puntos]
$M \leq 100, N \leq 100, K \leq 100$

#Subtarea 4 [33 puntos]
Sin restricciones.

