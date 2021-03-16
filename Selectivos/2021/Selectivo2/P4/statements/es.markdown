# Descripción
Daniel se encuentra aburrido en el avión que lo llevará a su primera participación en la IOI. Para pasar el tiempo, y como es su costumbre, saca su cuaderno y se pone a escribir los números enteros en orden ascendente, uno por uno, empezando desde el 1 hasta el cansancio. Luego de un par de horas, llegó hasta un número $N$ y se detuvo por un momento. Orgulloso de la longitud la lista que había escrito, ahora se pregunta emocionado:

¿Si tomo un dígito $d$, cuántas veces aparece dicho dígito en la lista?

Tú también estás aburrido, pero detestas contar manualmente, así que decides escribir un programa que calcule dicho número antes que Daniel lo calcule.

# Entrada
En la primera línea el valor de $N$.

En la segunda línea el valor de $d$.

# Salida
Un solo entero, representando la cantidad de veces que aparece el dígito $d$ en la lista de números del 1 al $N$ (ambos inclusive).

# Ejemplo
||input
22
2
||output
6
||description
El dígito 2 aparece un total de 6 veces en el rango [1, 22] en los números 2, 12, 20, 21, 22.
||end


#Límites

$ 1 \leq n \leq 10^{18}.$

$ 1 \leq d \leq 9.$

#Subtarea 1 [30 puntos]
$ n \leq 10^6.$

#Subtarea 2 [50 puntos]
$ n \leq 10^9.$

#Subtarea 3 [20 puntos]
Sin restricciones.
