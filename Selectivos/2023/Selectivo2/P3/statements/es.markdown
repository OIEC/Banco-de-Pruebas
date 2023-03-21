# Descripción

Un **palíndromo** es una cadena de caracteres que se lee igual de izquierda a derecha que de derecha a izquierda.

Dada una cadena de caracteres $s$, debes identificar si es posible reordenar sus caracteres de tal forma que la cadena resultante sea un palíndromo.

# Entrada

En la primera línea un entero $n$ que representa la longitud de la cadena.
En la segunda línea una cadena de caracteres de $n$ caracteres.

# Salida
Imprimir "SI" si la cadena se puede reordenar en un palíndromo y "NO" en caso contrario.

# Ejemplo
||input
7
ssssaad
||output
SI
||description
Notamos que la cadena puede ser reordenada en "assdssa" y por lo tanto imprimimos "SI".

||input
7
asbbbsc
||output
NO
||description
No importa como reordenemos esta cadena, nunca será un palíndromo, y por lo tanto imprimimos "NO"
||end


# Límites
- $n \leq 100$.

# Notas
- Los caracteres son caracteres en minúscula del afabeto en inglés, el cual consta de 26 letras y no incluye la ñ.
