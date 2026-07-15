# Editorial - Criptograma infinito

## Idea

La cadena $S$ representa un patrón comprimido mediante codificación por longitud de carrera o RLE.

Cada bloque está formado por:

- Una letra minúscula.
- Un número que indica cuántas veces consecutivas aparece esa letra.

Por ejemplo:

```text
a4b1c2d10
```

representa el patrón:

```text
aaaabcdddddddddd
```

Después de descomprimirlo, este patrón se repite infinitamente. Debemos encontrar el carácter ubicado en la posición $c$, considerando que los índices comienzan desde $0$.

No podemos construir explícitamente la cadena infinita. Además, incluso una sola copia del patrón podría tener una longitud muy grande, porque cada cantidad de repeticiones puede llegar hasta $10^{12}$.

### Reducir la posición al patrón original

Supongamos que la longitud total del patrón descomprimido es $L$.

Como el patrón vuelve a comenzar cada $L$ posiciones, el carácter ubicado en la posición $c$ es el mismo que el ubicado en:

$$
p=c\bmod L
$$

dentro de una sola copia del patrón.

Por ejemplo, si el patrón tiene longitud $4$, las posiciones $0$, $4$, $8$, $12$ y todas las demás posiciones múltiplos de $4$ corresponden al primer carácter del patrón.

Gracias a esta operación, la posición que debemos buscar siempre cumple:

$$
0\leq p<L
$$

### Encontrar el bloque que contiene la posición

Después de calcular $p$, recorremos los bloques comprimidos en el mismo orden en que aparecen en $S$.

Para cada bloque formado por una letra $x$ y una cantidad $k$:

- Si $p<k$, la posición buscada se encuentra dentro del bloque actual. Como todos sus caracteres son iguales, la respuesta es $x$.
- Si $p\geq k$, la posición buscada aparece después del bloque actual. Restamos $k$ a $p$ y continuamos con el siguiente bloque.

De esta forma procesamos cada bloque completo de una sola vez, sin generar individualmente todos sus caracteres.

### Lectura de cantidades de varios dígitos

Las cantidades no necesariamente están formadas por un solo dígito.

Por ejemplo, en:

```text
d10
```

la letra `d` se repite $10$ veces, no una vez seguida de un bloque separado con cantidad $0$.

Por ello, después de leer una letra debemos consumir todos los dígitos consecutivos que aparecen después de ella.

Si los dígitos son:

$$
d_1,d_2,\ldots,d_k
$$

construimos la cantidad aplicando repetidamente:

$$
cantidad=cantidad\cdot 10+d_i
$$

Por ejemplo, para los dígitos `1`, `2` y `5`:

$$
((0\cdot10+1)\cdot10+2)\cdot10+5=125
$$

## Algoritmo

1. Leer la cadena comprimida $S$ y la posición $c$.
2. Recorrer la cadena $S$ de izquierda a derecha.
3. Cada vez que se encuentre una letra:
   - Guardarla como la letra del bloque actual.
   - Leer todos los dígitos consecutivos posteriores.
   - Construir la cantidad de repeticiones del bloque.
   - Guardar la pareja formada por la letra y su cantidad.
   - Sumar la cantidad a la longitud total $L$ del patrón.
4. Calcular:

$$
p=c\bmod L
$$

5. Recorrer los bloques comprimidos:
   - Si $p$ es menor que la cantidad del bloque actual, imprimir la letra de ese bloque y terminar.
   - En caso contrario, restar la cantidad del bloque actual a $p$.
6. Continuar hasta encontrar el bloque que contiene la posición.

## Correctitud

Demostraremos que el algoritmo imprime el carácter ubicado en la posición $c$ del criptograma infinito.

### Lema 1: reducir la posición módulo $L$ conserva el carácter buscado

Sea $L$ la longitud del patrón descomprimido.

El criptograma infinito está formado por copias consecutivas del mismo patrón. Por lo tanto, para cualquier posición $c$, podemos escribir:

$$
c=qL+p
$$

donde:

$$
0\leq p<L
$$

Las primeras $qL$ posiciones corresponden exactamente a $q$ copias completas del patrón. Después de ellas, la posición restante dentro de la siguiente copia es $p$.

Como:

$$
p=c\bmod L
$$

el carácter de la posición $c$ del criptograma infinito es el mismo que el carácter de la posición $p$ dentro de una sola copia del patrón.

### Lema 2: al procesar cada bloque, $p$ representa la posición dentro de los bloques restantes

Inicialmente, $p$ representa la posición buscada dentro del patrón completo.

Consideremos un bloque de longitud $k$.

- Si $p<k$, la posición pertenece al bloque actual.
- Si $p\geq k$, las primeras $k$ posiciones corresponden completamente al bloque actual.

En el segundo caso, después de descartar ese bloque, la posición relativa dentro de los bloques restantes es:

$$
p-k
$$

Por lo tanto, al restar $k$, el algoritmo mantiene correctamente la posición buscada respecto a la parte del patrón que todavía no ha procesado.

### Lema 3: cuando el algoritmo imprime una letra, esa letra es la respuesta correcta

El algoritmo imprime la letra $x$ de un bloque únicamente cuando:

$$
p<k
$$

donde $k$ es la cantidad de repeticiones de $x$ en ese bloque.

Esto significa que la posición buscada pertenece a una de las $k$ apariciones consecutivas de $x$.

Por lo tanto, el carácter ubicado en esa posición es exactamente $x$.

### Teorema

Por el lema 1, podemos reemplazar la posición original $c$ por $p=c\bmod L$ sin cambiar el carácter buscado.

Por el lema 2, el recorrido de los bloques conserva correctamente la posición relativa dentro de la parte no procesada del patrón.

Por el lema 3, cuando el algoritmo encuentra el bloque que contiene esa posición, imprime exactamente su carácter.

Por lo tanto, el algoritmo siempre imprime el carácter ubicado en la posición $c$ del criptograma infinito.

## Complejidad

Sea $|S|$ la longitud de la cadena comprimida.

Cada carácter de $S$ se procesa una cantidad constante de veces al identificar las letras y construir las cantidades.

Después, se recorren los bloques comprimidos una vez.

Por lo tanto:

- Tiempo: $O(|S|)$
- Memoria: $O(|S|)$
