# Descripción
Bárbara planta $N$ girasoles distintos con una única altura, ordenadas de menor a mayor. Además anota las alturas de los girasoles durante $N$ días consecutivos. Cada día, los girasoles crecen y se vuelven más altos que el día anterior.
<br/><br/>
Ella anota cada una de las medidas en una tabla, con una fila para cada planta, siendo la primera fila el crecimiento del girasol más pequeño y la última fila el crecimiento del girasol más grande. La columna de la izquierda representa la primera medida para cada girasol, y la columna más a la derecha representa las últimas medidas para cada girasol.
<br/><br/>
Si un girasol era más pequeño que otro cuando se plantó inicialmente, permanece siendo más pequeño en cada medida de cada día.
<br/><br/>
Desafortunadamente uno de sus hijos accidentalmente rotó la tabla por un múltiplo de 90 grados en alguna dirección.
<br/><br/>
Tu tarea es ayudar a Bárbara a determinar los datos originales.

# Entrada
La primera línea contiene un entero $N$ $(2 \leq N \leq 100)$. Las siguientes $N$ líneas contienen $N$ enteros positivos separados por un espacio, cada uno menor a $10^9$. Se garantiza que la tabla de la entrada es una rotación de la tabla original.

# Salida
La tabla original, que consiste de $N$ líneas donde cada línea consta de $N$ enteros positivos separados por un espacio.

# Ejemplo
||input
2
1 3
2 9
||output
1 3
2 9
||description
Los datos han sido rotados 360 grados, lo que significa que la tabla rotada de la entrada es la tabla original.
||input
3
4 3 1
6 5 2
9 7 3
||output
1 2 3
3 5 7
4 6 9
||description
La tabla original fue rotada 90 grados a la derecha (sentido de las manecillas del reloj).
||end
