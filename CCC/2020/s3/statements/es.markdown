#Descripción
Dada una cadena $N$, llamada la aguja, y una cadena $H$, llamada el pajar, las cuales solo contienen letras minúsculas (a-z).

Crea un programa que cuenta el número de permutaciones distintas de $N$ que son subcadenas de $H$ al menos una vez. Nota que $N$ tiene entre $1$ y $|N|!$ permutaciones distintas en total, por ejemplo la cadena "aab" tienen tres distintas permutaciones ("aab", "aba", "baa").

#Entrada
La primera línea contiene a la cadena de la aguja $N$.

La segunda línea contiene a la cadena del pajar $H$.


#Salida
Un entero, el número de permutaciones distintas de $N$ que son subcadenas de $H$.


# Ejemplo
||input
aab
abacabaa
||output
2
||description
Las permutaciones "aba" y "baa" aparecen como subcadenas en $H$, mientras que la permutación "aab" no aparece.
||end


#Límites
-  $(1\leq |N| \leq 200000)$
-  $(1\leq |H| \leq 200000)$.

#Subtarea 1 [20 Puntos]
$|N| \leq 8$ y $|H| \leq 200$.

#Subtarea 2 [13.33 Puntos]
$|N| \leq 200$ y $|H| \leq 200$.

#Subtarea 3 [13.33 Puntos]
$|N| \leq 2000$ y $|H| \leq 2000$.

#Subtarea 4 [53.34 Puntos]
Sin restricciones.


