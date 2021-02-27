#Descripción
Ana es una excelente matemática que ama la geometría, sobre todo le encanta dibujar triángulos. Un día, su amigo Pedro le da una lista de $n$ enteros positivos y la desafía a dibujar todos los posibles triángulos usando dichos números como lados.

Para no quedarse sin espacio en su cuaderno, Ana primero quiere saber cuántos triángulos tendrá que dibujar. Para esto, ella te pide que la ayudes a calcular la cantidad de triángulos distintos que se pueden formar, usando los números dados por Pedro.

#Entrada
 - La cantidad $n$ de números en la lista de Pedro.
 - Los $n$ números de la lista, separados por un espacio. Puedes asumir que todos los números son distintos.

#Salida
 - El número de triángulos distintos que se pueden formar a partir de la lista de Pedro.

#Ejemplo
||input
3
2 3 4
||output
1
||description
Se puede formar el triángulo (2, 3, 4).
||input
4
2 4 3 5
||output
3
||description
Se pueden formar los triángulos (2, 4, 3), (2, 4, 5) y (4, 3, 5).
||end

#Subtarea 1 [40 puntos]
 - $n \leq 100$

#Subtarea 2 [60 puntos]
 - $n \leq 2500$

#Límites
 - Los números dados en la entrada no exceden el valor de $10^6$.
 - La cantidad de triángulos posibles no excede el valor de $10^9$.

# Notas
 - Los triángulos deben ser distintos. Es decir, no pueden ser permutaciones entre sí. Por ejemplo, los triángulos (2, 3, 4) y (4, 2, 3) son los mismos y se cuentan como solamente un triángulo.
 - Recuerda que los lados de un triángulo deben cumplir la desigualdad triangular: Para un triángulo con lados $a, b, c$ debe cumplirse incondicionalmente que $a + b > c$, $a + c > b$ y $b + c > a$.
