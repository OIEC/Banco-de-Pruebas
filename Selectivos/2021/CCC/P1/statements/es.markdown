#Descripción

Es el primer día en tu nuevo trabajo como programador en la compañía de videojuegos MultiStation. Tu primer proyecto consiste en implementar una versión online del tradicional juego de Sudoku. Además de la interfaz gráfica y otros detalles, debes implementar el proceso de validación del tablero. La validación ocurre cada vez que el usuario ingresa un número en una casilla. Dado un tablero de Sudoku, tu tarea es escribir un programa que determine si es posible continuar con la resolución del Sudoku o no.

![Figura](tablero.jpg)

#Entrada
9 líneas con 9 dígitos en cada una, separados por un espacio. Por simplicidad, el 0 simboliza una casilla vacía.

#Salida
"Posible" en caso que el Sudoku sea válido y se pueda continuar resolviendo.
"Imposible" en caso que el tablero de Sudoku sea inválido.

#Ejemplo

||input
0 4 0 0 0 1 7 5 8
0 0 0 0 0 0 0 1 9
2 0 0 0 0 0 4 0 0
0 9 0 0 8 0 0 0 0
4 5 0 0 3 2 1 0 0
3 2 0 0 0 0 0 9 0
0 0 0 0 0 0 0 7 3
0 0 0 0 0 7 9 0 5
5 0 0 0 4 0 8 0 0
||output
Posible
||description
El tablero es válido porque cumple todas las condiciones de un tablero de Sudoku.

||input
0 4 0 0 0 1 7 5 8
0 0 0 0 0 0 0 1 9
2 0 0 0 0 0 4 0 0
0 9 0 0 8 0 0 0 0
4 5 0 0 3 2 1 0 0
3 2 0 0 0 0 0 9 0
0 0 7 0 0 0 0 7 3
0 0 0 0 0 7 9 0 5
5 0 0 0 4 0 8 0 0
||output
Imposible
||description
El tablero es inválido porque en la séptima columna hay dos números iguales.
||end

#Notas
- Un tablero de Sudoku es válido si ninguna de sus filas, columnas, ni los 9 tableros contiguos de 3x3 contienen números repetidos. Nota los 9 subtableros de 3x3 en la figura. El primer subtablero de la figura contiene los números 1, 3, 2 y las demás casillas están vacías.
- El tablero puede estar incompleto. Para simbolizar esto, una casilla vacía se simboliza con el dígito 0.
- La validez del tablero se determina con los números que están presente al momento de validarlo. Es posible que un tablero válido con casillas vacías sea imposible de completar, pero sigue siendo válido al momento de la evaluación. En este caso, tu programa debe imprimir "Posible".

#Consideraciones
- Los casos de prueba están agrupados de tal forma que solamente recibirás el puntaje correspondiente a un grupo si tu código resuelve todos los casos que pertenecen a ese grupo.
