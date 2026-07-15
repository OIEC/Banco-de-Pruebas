# Editorial - Buscar y contar

## Idea

Se nos proporciona una secuencia de \(N\) enteros y, después de ella, un entero \(B\).

Debemos determinar cuántas veces aparece \(B\) dentro de la secuencia.

Para resolverlo, almacenamos los \(N\) elementos en un arreglo. Luego leemos \(B\), recorremos nuevamente la secuencia y aumentamos un contador cada vez que encontramos un elemento igual a \(B\).

Por ejemplo, para la secuencia:

\[
1,\ 7,\ 3,\ 4,\ 3
\]

y \(B = 3\), encontramos dos elementos iguales a \(3\), por lo que la respuesta es \(2\).

## Algoritmo

1. Leer el entero \(N\).
2. Leer y almacenar los \(N\) elementos de la secuencia.
3. Leer el entero \(B\).
4. Inicializar un contador en \(0\).
5. Recorrer todos los elementos de la secuencia:
   - Si el elemento actual es igual a \(B\), aumentar el contador en \(1\).
6. Imprimir el contador.

## Correctitud

Demostraremos que el algoritmo imprime la cantidad de veces que \(B\) aparece en la secuencia.

El algoritmo recorre cada uno de los \(N\) elementos exactamente una vez.

Para cada elemento:

- Si el elemento es igual a \(B\), el algoritmo aumenta el contador en \(1\).
- Si el elemento es diferente de \(B\), el contador no cambia.

Por lo tanto, cada aparición de \(B\) aumenta el contador exactamente una vez y ningún elemento diferente de \(B\) modifica el contador.

Al terminar el recorrido, el contador es igual al número total de posiciones de la secuencia cuyo valor es \(B\).

Por lo tanto, el algoritmo siempre imprime la respuesta correcta.

## Complejidad

El algoritmo recorre los \(N\) elementos de la secuencia.

- Tiempo: \(O(N)\)
- Memoria: \(O(N)\)
