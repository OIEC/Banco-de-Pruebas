Para resolver este problema vamos a usar un arreglo de enteros que representa la cantidad de cartas de cada tipo que hay en la mano, para luego leer los 5 números de la entrada y llenar el arreglo respectivamente. Ya que el arreglo es de enteros y estamos leyendo cadenas de caracteres en la entrada, mapeamos cada entrada a su respectivo índice. La carta "J" le damos el índice 11, a la "Q" el 12, la "K" el 13 y la "A" el 14.

También definimos diferentes funciones que atraviesan el arreglo para chequear si tenemos algunos de los juegos:
- Si un número en el arreglo tiene 4 cartas, es un __Póker__.
- Si hay un trío y un par, entonces es un __Full House__.
- Si el arreglo contiene 5 cartas consecutivas con un conteo de uno, es una __Escalera__. También incluimos el caso especial donde la escalera empieza en la "A".
- Si solamente un número tiene 3 cartas, es un __Trío__.
- Si hay dos pares, es __Dos Pares__.
- Si solamente hay un par, es un __Par__.

Finalmente chequeamos cuál es el juego más alto que se puede formar y lo imprimimos.
