#Descripción

Calcular los valores exactos de potencias muy grandes es difícil, pero es fácil calcular el resto de una potencia en la división para otro entero.
Dados enteros positivos $a$, $b$ y $c$, escribir un programa que muestre el resto de $a^b$ en la división para $c$.
El resto $r$ debe ser un entero $0 \le r < c$.


#Entrada
 - En la primera línea, el número $a$.
 - En la segunda línea, el número $b$.
 - En la tercera línea, el número $c$.

#Salida
El resto de $a^b$ en la división para $c$.

#Ejemplo
||input
4
3
10
||output
4
||description
El resto de la división de $4^3$ para $10$ es $4$.
||end

#Límites
- $c < 1000$

#Subtarea 1 [60 puntos]
 - $a^b<10^6$

#Subtarea 2 [40 puntos]
 - $a < 10^6$
 - $b \leq 2020$

