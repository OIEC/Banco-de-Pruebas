# Descripción

La profesora de matemáticas, cada día más excéntrica, se ha inventado una nueva propiedad. Según ella, una pareja de enteros distintos se le llama "k-olímpica" si el valor absoluto de la diferencia entre los enteros de la pareja es divisible para $k$. Emocionada por su nueva propiedad, te asignó como tarea el contar cuántas parejas "k-olímpicas" existen en una lista gigante de enteros que se inventó. Ella pensó que esta tarea te llevaría toda la tarde, pero como de costumbre descubriste que es posible escribir un programa que te haga la tarea.

# Entrada

En la primera línea los enteros $n$ y $k$ separados por un espacio. 
En la segunda línea $n$ enteros distintos separados por un espacio.


# Salida

La cantidad de parejas "k-olímpicas" que se pueden formar en base a los enteros de la lista.

# Ejemplo

||input
5 3
1 6 9 2 0
||output
3
||description
Las 3 parejas de enteros "3-olímpicas" son: (6,9), (6,0), (9,0).
||end

#Límites

Los enteros de la lista son menores a tres millones.

$ n \leq 100000 $

$ k < 1000 $


#Subtarea 1 [60 puntos]
$ n \leq 500 $

#Subtarea 2 [40 puntos]
Sin restricciones.

#Notas

La pareja de enteros (a,b) es la misma que la pareja (b,a), por lo que ambas se cuentan solamente una vez.




