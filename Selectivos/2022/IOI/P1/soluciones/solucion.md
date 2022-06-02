# Solución
Sabemos que Alicia tiene `n` caramelos de distintos sabores y puede comer un máximo de `n/2` caramelos. 
El máximo número de sabores que ella puede probar se obtiene cuando prueba uno de cada sabor, pero hay que tomar en cuenta la restricción impuesta por el doctor, que es `n/2` en total. Por lo que la respuesta es el mayor entre la cantidad de sabores y `n/2`.

Hallar la cantidad de distintos sabores se puede hacer de muchas maneras: En el peor de los casos, se puede lograr atravesando el array dos veces en `(O(n^2))`. También se puede ordenar el arreglo y atravesarlo una vez en `(O(n log n))`. Se puede usar un mapa on un set, aunque lo más eficiente es usar un arreglo donde cada elemento representa la cantidad de caramelos de cada sabor en ese índice y contando el número de entradas con valores positivos.
