# Conjunto Capicúa

## Idea

Se nos proporciona una secuencia de \(N\) dígitos y debemos determinar si puede leerse de la misma manera de izquierda a derecha que de derecha a izquierda.

Para que la secuencia sea capicúa, cada elemento debe ser igual a su elemento simétrico:

- El primer elemento debe ser igual al último.
- El segundo elemento debe ser igual al penúltimo.
- El tercero debe ser igual al antepenúltimo.
- Y así sucesivamente.

Por lo tanto, basta con comparar el elemento ubicado en la posición \(i\) con el elemento ubicado en la posición \(N-1-i\).

Solo necesitamos realizar estas comparaciones durante la primera mitad de la secuencia, ya que después se repetirían las mismas parejas en orden contrario.

Por ejemplo, en la secuencia:

\[
1,\ 3,\ 4,\ 3,\ 1
\]

se cumple que:

- El primer elemento es igual al último.
- El segundo elemento es igual al penúltimo.
- El elemento central no necesita compararse con otro.

Por lo tanto, la secuencia es capicúa.

## Algoritmo

1. Leer el entero \(N\).
2. Leer y almacenar los \(N\) dígitos de la secuencia.
3. Inicializar una variable booleana `capicua` con el valor verdadero.
4. Para cada posición \(i\) desde \(0\) hasta antes de \(N/2\):
   - Comparar el elemento en la posición \(i\) con el elemento en la posición \(N-1-i\).
   - Si son diferentes, asignar falso a `capicua` y terminar el recorrido.
5. Si `capicua` es verdadero, imprimir `SI`.
6. En caso contrario, imprimir `NO`.

## Correctitud

Demostraremos que el algoritmo imprime `SI` si y solo si la secuencia es capicúa.

Una secuencia es capicúa cuando, para cada posición \(i\), el elemento en la posición \(i\) es igual al elemento en la posición simétrica \(N-1-i\).

El algoritmo compara todas las parejas simétricas de la secuencia.

- Si alguna pareja contiene valores diferentes, entonces la secuencia no puede leerse de la misma manera en ambos sentidos. En este caso, el algoritmo imprime `NO`.
- Si todas las parejas simétricas son iguales, entonces cada elemento leído de izquierda a derecha coincide con el elemento correspondiente al leer de derecha a izquierda. En este caso, el algoritmo imprime `SI`.

Cuando \(N\) es impar, el elemento central no afecta el resultado, ya que al invertir la secuencia permanece en la misma posición.

Por lo tanto, el algoritmo imprime `SI` exactamente cuando la secuencia es capicúa y siempre produce la respuesta correcta.

## Complejidad

El algoritmo realiza como máximo \(N/2\) comparaciones.

- Tiempo: \(O(N)\)
- Memoria: \(O(N)\)
