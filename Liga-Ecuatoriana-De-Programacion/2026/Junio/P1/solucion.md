# Editorial - Orden Aparente

## Idea

Se nos dan tres enteros `a`, `b` y `c`.

Debemos determinar cuál de las siguientes situaciones ocurre:

- Todos los números son iguales → imprimir `I`.
- La secuencia es creciente débil (`a <= b <= c`) → imprimir `C`.
- La secuencia es decreciente débil (`a >= b >= c`) → imprimir `D`.
- Ninguna de las anteriores → imprimir `X`.

Observa que si los tres números son iguales, la secuencia es tanto creciente como decreciente. Sin embargo, el enunciado indica que en ese caso debemos responder `I`, por lo que esta condición debe verificarse primero.

## Algoritmo

1. Leer `a`, `b` y `c`.
2. Si `a == b` y `b == c`, imprimir `I`.
3. En caso contrario, si `a <= b` y `b <= c`, imprimir `C`.
4. En caso contrario, si `a >= b` y `b >= c`, imprimir `D`.
5. Si ninguna condición se cumple, imprimir `X`.

## Correctitud

Analicemos los posibles casos:

- Si `a = b = c`, entonces todos los números son iguales y el algoritmo imprime `I`, como exige el enunciado.
- Si no todos son iguales pero `a <= b <= c`, entonces la secuencia es creciente débil y el algoritmo imprime `C`.
- Si no todos son iguales pero `a >= b >= c`, entonces la secuencia es decreciente débil y el algoritmo imprime `D`.
- En cualquier otro caso, la secuencia no es creciente débil ni decreciente débil, por lo que no existe un orden aparente y el algoritmo imprime `X`.

Por lo tanto, el algoritmo siempre produce la respuesta correcta.

## Complejidad

El algoritmo realiza únicamente unas pocas comparaciones.

- Tiempo: **O(1)**
- Memoria: **O(1)**
