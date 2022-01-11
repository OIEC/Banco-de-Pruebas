#Descripción
Tu profesor de matemáticas te dio una tarea que consiste en inventarte una secuencia de $N$ enteros $A_1, . . . , A_N$ , tal que $1 \leq A_i \leq 1 000 000 000$ para cada $i$.

La secuencia $A$ debe satisfacer M requisitos, con el requisito i siendo que el MCD (Máximo Común Divisor) de la secuencia contigua $A_{X_i},…, A_{Y_i}$ $(1 \leq X_i \leq Y_i \leq N)$ debe ser igual a $Z_i$. Note que el MCD entre una secuencia de enteros es el mayor entero $d$ tal que todos los números de la secuencia son divisibles para $d$.

Encuentra cualquier secuencia válida $A$ consistente con todos estos requisitos, o determina si no existe ninguna secuencia que los cumpla.

#Entrada
La primera línea contiene dos enteros $N$ y $M$ separados por un espacio.
Las siguientes $M$ líneas, cada una contiene tres enteros separados por un espacio, $X_i$, $Y_i$ y $Z_i$ $(1 \leq i \leq M)$.

#Salida
Si ninguna secuencia existe, imprime la cadena “Impossible” en una sola línea. En caso contrario, en una sola línea, imprime $N$ enteros separados por un espacio, representando la secuencia $A_1, . . . , A_N$. Si hay múltiples secuencias válidas, cualquier secuencia será aceptada.

# Ejemplo
||input
2 2
1 2 2
2 2 6
||output
4 6
||description
Si $A_1 = 4$ y $A_2 = 6$, el MCD de $[A_1, A_2]$ es 2 y el MCD de $[A_2]$ es 6, como se requiere. Nota que otras secuencias válidas también serán aceptadas.
||end

||input
2 2
1 2 2
2 2 5
||output
Impossible
||description
No existe ninguna secuencia $[A_1, A_2]$ tal que MCD de $[A_1, A_2]$ es 2 y el MCD de $[A_2]$ es 5.
||end


#Límites
- $1 \leq N \leq 150 000$ 
- $1 \leq M \leq 150 000$ 
- $1 \leq Z_i \leq 16$

#Subtarea 1 [20 puntos]
$N \leq 2000$, $M \leq 2000$, $Zi \leq 2$.

#Subtarea 2 [27 puntos]
$N \leq 2000$, $M \leq 2000$, $Zi \leq 16$.

#Subtarea 3 [53 puntos]
Sin restricciones.

