# Editorial - Lápices coloridos

## Idea

Tenemos $N$ lápices distribuidos entre $M$ colores. Para crear una imagen debemos escoger exactamente un lápiz de cada color.

Antes de crearla podemos cambiar temporalmente el color de, como máximo, un lápiz. Después, el lápiz recupera su color original.

Además, debemos responder después de varios cambios permanentes en los colores o las bellezas de los lápices.

### La mejor respuesta sin cambiar ningún color

Para cada color $c$, definamos $m_c$ como el lápiz de mayor belleza de ese color.

Si no hacemos ningún cambio temporal, la mejor decisión es escoger $m_c$ para cada color. Sea:

$$
T=\sum_{c=1}^{M}P_{m_c}
$$

Entonces $T$ es la máxima belleza que podemos obtener sin recolorear ningún lápiz.

### Qué lápiz conviene recolorear

Dividimos los lápices en dos grupos:

- Los lápices $m_c$, que son los mejores de sus respectivos colores.
- Todos los demás lápices.

Supongamos que queremos utilizar un lápiz adicional de belleza $P_i$. Podemos cambiar temporalmente su color al de otro color $d$.

En ese color ya habíamos escogido un lápiz de belleza $P_{m_d}$. Después del cambio, podemos conservar el mejor entre ambos.

Por lo tanto, la nueva respuesta sería:

$$
T-P_{m_d}+\max(P_{m_d},P_i)
$$

Para maximizar esta expresión:

- Conviene utilizar el lápiz de mayor belleza que no sea el máximo de su color.
- Conviene enviarlo al color cuyo lápiz máximo tenga la menor belleza.

Definamos:

- $R$ como la mayor belleza entre los lápices que no son máximos de su color.
- $L$ como la menor belleza entre los máximos de cada color.

Entonces la mejor respuesta obtenida usando un cambio temporal es:

$$
T-L+\max(L,R)
$$

Esto equivale a:

$$
\max(T,T-L+R)
$$

Si todos los lápices son máximos de su color, es decir, si $N=M$, no existe un lápiz adicional que podamos recolorear sin dejar a su color original sin una opción.

En ese caso, la respuesta es simplemente $T$.

### Estructuras que debemos mantener

Para responder eficientemente a los cambios mantenemos:

1. Una estructura ordenada por color y belleza que permite conocer el lápiz más bello de cada color.
2. La suma $T$ de las bellezas máximas.
3. Un conjunto ordenado con todos los lápices clasificados en:
   - Tipo $0$: no es máximo de su color.
   - Tipo $1$: es máximo de su color.

Al ordenar primero por tipo y después por belleza:

- El primer elemento de tipo $1$ contiene la menor belleza entre los máximos.
- El último elemento de tipo $0$ contiene la mayor belleza entre los no máximos.

Para ahorrar memoria, ambos grupos pueden almacenarse dentro de un único conjunto ordenado.

### Procesamiento de un cambio

Un cambio de belleza solo puede modificar el máximo de un color.

Un cambio de color únicamente puede modificar los máximos de:

- El color anterior del lápiz.
- El nuevo color del lápiz.

Por lo tanto, antes de aplicar un cambio:

1. Retiramos de las estructuras globales los máximos actuales de los colores afectados.
2. Retiramos el lápiz modificado.
3. Aplicamos el cambio.
4. Calculamos nuevamente los máximos de los colores afectados.
5. Reclasificamos únicamente los lápices que pudieron cambiar entre máximo y no máximo.

La cantidad de lápices reclasificados en cada consulta es constante.

## Algoritmo

### Inicialización

1. Leer los $N$ lápices.
2. Insertar cada lápiz en una estructura ordenada por:
   - Color.
   - Belleza.
   - Identificador.
3. Encontrar el lápiz máximo de cada color.
4. Calcular la suma $T$.
5. Clasificar cada lápiz como máximo o no máximo.

### Obtener la respuesta

1. Inicializar la respuesta con $T$.
2. Obtener la menor belleza $L$ entre los máximos.
3. Si existe algún lápiz no máximo:
   - Obtener la mayor belleza $R$ entre ellos.
   - Considerar la respuesta:

$$
T-L+R
$$

4. Imprimir el mayor valor entre esta respuesta y $T$.

### Procesar una consulta

1. Determinar los colores afectados.
2. Restar de $T$ los máximos anteriores de esos colores.
3. Retirar de las estructuras globales los lápices que podrían cambiar de clasificación.
4. Aplicar el cambio de color o belleza.
5. Encontrar los nuevos máximos de los colores afectados.
6. Sumarlos nuevamente a $T$.
7. Reclasificar los lápices afectados.
8. Imprimir la nueva respuesta.

## Correctitud

Demostraremos que el algoritmo imprime la máxima belleza posible antes de cualquier cambio y después de cada consulta.

### Lema 1: $T$ es la mejor respuesta sin recolorear lápices

Para cada color debemos escoger exactamente un lápiz.

El lápiz $m_c$ es el de mayor belleza del color $c$, por lo que ninguna otra elección para ese color puede aportar más belleza.

Al escoger $m_c$ para todos los colores obtenemos:

$$
T=\sum_{c=1}^{M}P_{m_c}
$$

Por lo tanto, $T$ es la máxima belleza posible sin cambiar colores.

### Lema 2: existe una solución óptima que recolorea un lápiz no máximo

Supongamos que una solución recolorea al lápiz máximo de un color.

Después de recolorearlo, debe seleccionarse otro lápiz de su color original para que ese color siga representado.

Podemos intercambiar los papeles de estos dos lápices:

- Conservamos el lápiz máximo en su color original.
- Recoloreamos el otro lápiz.

El lápiz máximo continúa aportando su belleza al color original, mientras que el otro lápiz puede competir en el color de destino.

Este intercambio no reduce la belleza total.

Por lo tanto, siempre existe una solución óptima que recolorea un lápiz que no es máximo de su color.

### Lema 3: el mejor cambio utiliza $R$ y reemplaza a $L$

Sea $P_i$ la belleza de un lápiz no máximo que se recolorea al color $d$.

La belleza obtenida es:

$$
T-P_{m_d}+\max(P_{m_d},P_i)
$$

Para maximizarla, debemos escoger el mayor $P_i$ disponible entre los lápices no máximos. Este valor es $R$.

También debemos escoger el menor $P_{m_d}$ entre los máximos, cuyo valor es $L$.

Por lo tanto, la mejor belleza alcanzable con un cambio es:

$$
T-L+\max(L,R)
$$

Si $R\leq L$, el cambio no mejora la respuesta y conservamos $T$.

Si $R>L$, obtenemos:

$$
T-L+R
$$

En ambos casos, la respuesta es:

$$
\max(T,T-L+R)
$$

### Lema 4: las estructuras permanecen correctas después de cada consulta

Una modificación de belleza solo puede cambiar el máximo del color del lápiz modificado.

Una modificación de color solo puede cambiar el máximo del color anterior y del nuevo color.

El algoritmo elimina la información anterior de esos colores, aplica el cambio y vuelve a calcular sus máximos. Ningún otro color es alterado.

Después de reclasificar los lápices involucrados:

- Cada color vuelve a tener identificado correctamente su máximo.
- $T$ vuelve a ser la suma de todos los máximos.
- Todos los demás lápices quedan clasificados como no máximos.

Por lo tanto, las estructuras conservan sus invariantes después de cada consulta.

### Teorema

Por el lema 1, $T$ representa la mejor solución sin recolorear.

Por los lemas 2 y 3, la mejor solución que recolorea un lápiz es calculada correctamente utilizando el mejor no máximo y el menor máximo.

Por el lema 4, toda la información necesaria se mantiene correctamente después de cada modificación.

Por lo tanto, el algoritmo imprime siempre la máxima belleza posible.

## Complejidad

La inicialización inserta los $N$ lápices en estructuras ordenadas, por lo que requiere:

$$
O(N\log N)
$$

Cada consulta modifica una cantidad constante de elementos y cada inserción, eliminación o búsqueda cuesta $O(\log N)$.

Por lo tanto:

- Tiempo: $O((N+Q)\log N)$
- Memoria: $O(N+M)$
