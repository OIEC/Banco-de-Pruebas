#Descripción

Vas caminando por el patio de tu casa cuando te encuentras $n$ piedras en fila. Intrigado por este suceso, decides pesar cada una, pero las regresas a su lugar original. Los pesos pueden ser representados como enteros positivos $a_1, a_2, \ldots , a_n$. Ya que te gusta la idea del equilibrio, quieres dividir las piedras en 2 montones de igual peso. Sin embargo, también te gusta el orden, por lo que no quieres moverlas de su lugar.

Para satisfacer tus condiciones, quieres hallar $r$ tal que:
$$a_1 + a_2 + \ldots + a_r = a_{r+1} + a_{r+2} + \ldots + a_n$$

#Entrada
 - En la primera línea, un entero positivo $n$.
 - En la segunda línea, una lista con $n$ enteros positivos.

#Salida
 - El número $r$ que cumple la condición descrita. Sino existe dicho $r$, imprimir la cadena "No existe".

# Ejemplo
||input
3
4 3 7
||output
2
||description
Notamos que $4 + 3 = 7$, por lo que $r = 2$.

||input
3
3 2 4
||output
No existe
||description
No existe un $r$ que cumpla la condición.
||end

#Subtarea 1 [60 puntos]
$n < 20000$.


#Subtarea 2 [40 puntos]
$n < 1000000$.
