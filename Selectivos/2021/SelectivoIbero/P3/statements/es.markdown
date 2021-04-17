# Descripción

Dado 2 cuadrados, A y B, en una tabla de ajedrez de 1000x1000, retornar cuanto es el minimo numero de pasos para que un caballo puesto en A llegue a B.

# Entrada

2 lineas de 2 numeros enteros cada uno. Primera linea es el cuadro de comienzo
y la segunda linea el cuadro de llegada. 
Coordenada comienza en 0, es decir, (0, 0) es la esquina inferior izquierda.


# Salida

Un solo numero de pasos debe dar el caballo en llegar de A a B.

# Ejemplo

||input
0 5
8 9
||output
4
||end

#Notas

 - El caballo de ajedrez se mueve en L, es decir, desde un cuadrado
con coordenadas (x, y) llegaria a $(x \pm 1, y \pm 2)$  o $(x \pm 2, y \pm 1)$.
 - Se te asegura que el caballo no sale del tablero en su recorrido de A a B.





