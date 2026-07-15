# Editorial - HCF-Diferencia absoluta mínima

## Idea

Se nos proporciona una secuencia de $N$ números enteros y debemos encontrar la menor diferencia absoluta posible entre dos elementos distintos.

Para dos posiciones $i$ y $j$, con $i<j$, la diferencia de la pareja es:

$$
|a_i-a_j|
$$

Como $2\leq N\leq 1000$, podemos revisar todas las parejas posibles mediante dos ciclos anidados.

Las parejas se recorren en el mismo orden en el que aparecen en la entrada:

$$
(0,1),(0,2),\ldots,(0,N-1),(1,2),\ldots
$$

Cuando encontramos una diferencia menor que la mejor conocida, guardamos:

- La nueva diferencia mínima.
- Los dos números que forman la pareja.
- Las posiciones de esos números.

Si encontramos otra pareja con la misma diferencia mínima, no reemplazamos la respuesta. De esta manera, conservamos la primera pareja encontrada según el orden de recorrido.

Por ejemplo, para:

$$
51,\ 47,\ 13,\ 89,\ 2,\ 6,\ 39,\ 27
$$

las parejas $(51,47)$ y $(2,6)$ tienen diferencia absoluta $4$.

Sin embargo, la pareja $(51,47)$ se encuentra primero durante el recorrido, por lo que esa es la pareja que debe imprimirse.

## Algoritmo

1. Leer el entero $N$.
2. Leer los $N$ números de la secuencia.
3. Inicializar la mejor diferencia utilizando la pareja de posiciones $0$ y $1$.
4. Para cada posición $i$ desde $0$ hasta $N-1$:
   - Para cada posición $j$ desde $i+1$ hasta $N-1$:
     1. Calcular:

        $$
        |a_i-a_j|
        $$

     2. Si esta diferencia es estrictamente menor que la mejor diferencia encontrada:
        - Actualizar la diferencia mínima.
        - Guardar $i$ y $j$ como las posiciones de la respuesta.
5. Imprimir:
   - La diferencia absoluta mínima.
   - Los valores ubicados en las posiciones guardadas.
   - Las posiciones guardadas.

## Correctitud

Demostraremos que el algoritmo imprime la diferencia absoluta mínima y la primera pareja que la genera.

### Lema 1: el algoritmo examina todas las parejas posibles

El primer ciclo selecciona una posición $i$ y el segundo ciclo selecciona una posición $j$ que cumple:

$$
i<j
$$

Por lo tanto, cada pareja de posiciones diferentes se procesa una sola vez.

Además, toda pareja de posiciones distintas puede escribirse como $(i,j)$ con $i<j$.

En consecuencia, el algoritmo examina todas las parejas posibles de la secuencia exactamente una vez.

### Lema 2: la diferencia almacenada al finalizar es la mínima posible

Cada vez que el algoritmo encuentra una pareja cuya diferencia absoluta es menor que la mejor diferencia conocida, actualiza la respuesta.

Como por el lema 1 se examinan todas las parejas posibles, al finalizar no puede existir una pareja con una diferencia menor que la almacenada.

Por lo tanto, la diferencia guardada es la mínima diferencia absoluta posible entre dos elementos distintos.

### Lema 3: el algoritmo conserva la primera pareja que produce la diferencia mínima

Las parejas son examinadas en orden creciente de $i$ y, para un mismo valor de $i$, en orden creciente de $j$.

El algoritmo actualiza la respuesta únicamente cuando encuentra una diferencia estrictamente menor.

Es decir, utiliza la condición:

$$
d<d_{\min}
$$

Si posteriormente aparece otra pareja con la misma diferencia mínima, no se realiza ninguna actualización.

Por lo tanto, entre todas las parejas que producen la diferencia mínima, el algoritmo conserva la primera que aparece en el orden de recorrido.

### Teorema

Por el lema 2, el algoritmo obtiene la menor diferencia absoluta posible.

Por el lema 3, conserva la primera pareja que genera dicha diferencia.

En consecuencia, el algoritmo imprime correctamente:

- La diferencia absoluta mínima.
- Los números de la primera pareja que genera esa diferencia.
- Las posiciones originales de dicha pareja.

Por lo tanto, el algoritmo siempre produce la respuesta correcta.

## Complejidad

Se examinan todas las parejas posibles de elementos.

La cantidad total de parejas es:

$$
\frac{N(N-1)}{2}
$$

Por lo tanto:

- Tiempo: $O(N^2)$
- Memoria: $O(N)$
