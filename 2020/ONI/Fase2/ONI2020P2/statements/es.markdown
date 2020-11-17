#Descripción
Un gobierno tiene $n$ dólares de fondos para bonos de desempleo. Los ciudadanos desempleados reciben diferentes montos de acuerdo al sueldo que recibían. Tu trabajo es el de crear un programa que pueda encontrar el menor límite entero $k$ tal que:
    
- Si un ciudadano tenía un sueldo mayor a $k$, el ciudadano recibe $k$ dólares de bono.
- Si un ciudadano tenía un sueldo menor o igual $k$, el ciudadano recibe su sueldo original.

El gobierno también debe asegurarse que la suma de los bonos entregados a todos los ciudadanos desempleados no exceda el fondo de $n$ dólares que tiene destinado a ello, por lo que dicho valor tiene que ser menor o igual a $n$, pero tiene que ser lo más cercano posible.

#Entrada
 - En la primera línea, el fondo $n$ de dólares que tiene el gobierno.
 - En la segunda línea, la cantidad $d$ de ciudadanos desempleados.
 - En la tercera línea, los sueldos anteriores de los $d$ ciudadanos desempleados separados por un espacio.

#Salida
El límite $k$  de dólares que reciben los ciuadanos desempleados como bono.

#Ejemplo
||input
100
2
20 90
||output
80
||description
En este caso el gobierno tiene \$100 de fondo y hay 2 ciudadanos desempleados que recibían \$20 y \$90 de sueldo. El límite de bono que se puede dar en este caso es \$80, ya que el primer ciudadano recibe \$20 y el segundo \$80, dando un total de \$100.
||input
100
2
77 22 
||output
77
||description
En este caso el gobierno tiene \$100 de fondo y hay 2 ciudadanos desempleados que recibían \$77 y \$22 de sueldo. El límite de bono que se puede dar en este caso es \$77, ya que el primer ciudadano recibe \$22 y el segundo \$77 dando un total de \$99.
||end

#Límites
- El sueldo de cada ciudadano y el fondo del gobierno son números enteros positivos.
- La suma de todos los sueldos es menor a $2^{30}$.

#Subtarea 1 [70 puntos]
 - $n \leq 10000$
 - $d \leq 10$

#Subtarea 2 [30 puntos]
 - $n \leq 2^{29}$
 - $d \leq 10000$
