Al empezar el problema, vamos a crear un arreglo de caracteres `alfabeto`, que va a contener los 26 caracteres del alfabeto inglés en minúsculas ordenados. Este arreglo nos servirá como referencia para rotar los caracteres del mensaje. Para esto, vamos a repetir el siguiente procedimiento (contenido en la función `Rotacion`) en cada caracter `c` que deseemos rotar:

- Primero, vamos a determinar la posición de `c` en el alfabeto. Hacemos esto usando un bucle en el que comparamos a `c` con las entradas de `alfabeto`. Almacenaremos nuestro resultado en la variable `indice`.

- Luego, vamos a determinar la posición del nuevo caracter. Para esto, basta con actualizar el valor de `indice` a `(indice+n)%26`. Usamos el operador de módulo `%` para el caso en el que llegamos al final del arreglo y necesitamos volver al inicio. Si no se conoce el uso del operador modular, podemos incrementar el índice uno por uno en un bucle, y manualmente regresar al inicio del arreglo cuando llegamos al final.

- Finalmente, imprimimos el caracter rotado a través de `alfabeto[indice]`.

- Repetimos el proceso anterior para cada caracter del mensaje original.
