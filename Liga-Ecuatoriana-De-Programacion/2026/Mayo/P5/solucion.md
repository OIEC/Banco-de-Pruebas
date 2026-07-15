# Editorial - El suelo es lava

## Idea

Tenemos una gráfica no dirigida con $N$ habitaciones y $M$ túneles. Cada túnel conecta dos habitaciones y tiene una temperatura asociada.

Para atravesar un túnel de temperatura $t$, el nivel de enfriamiento de las botas debe ser exactamente $t$. Cambiar el nivel de enfriamiento en $d$ unidades cuesta $d$ monedas.

Inicialmente, el nivel de enfriamiento de las botas es $0$.

Supongamos que utilizamos una secuencia de túneles cuyas temperaturas son:

$$
w_1,w_2,\ldots,w_k
$$

Antes de utilizar el primer túnel debemos cambiar el nivel desde $0$ hasta $w_1$, lo cual cuesta $w_1$ monedas.

Después, para pasar de un túnel con temperatura $w_{i-1}$ a otro con temperatura $w_i$, debemos pagar:

$$
|w_i-w_{i-1}|
$$

Por lo tanto, el costo total de esa ruta es:

$$
w_1+\sum_{i=2}^{k}|w_i-w_{i-1}|
$$

El objetivo es encontrar una ruta desde la habitación $1$ hasta la habitación $N$ que minimice esta expresión.

## Estados del grafo auxiliar

En lugar de representar únicamente la habitación actual, representaremos también el último túnel utilizado.

Por cada túnel creamos dos estados, uno por cada uno de sus extremos.

Si un túnel $e$ conecta las habitaciones $u$ y $v$, tendremos:

- Un estado correspondiente al extremo de $e$ ubicado en $u$.
- Otro estado correspondiente al extremo de $e$ ubicado en $v$.

Ambos estados se conectan con costo $0$.

Esto representa atravesar el túnel: una vez que el nivel de las botas coincide con su temperatura, desplazarse de un extremo al otro no requiere monedas adicionales.

## Cambiar de túnel dentro de una habitación

Supongamos que varios túneles llegan a una misma habitación y que sus temperaturas, ordenadas de menor a mayor, son:

$$
x_1\leq x_2\leq\cdots\leq x_k
$$

Cambiar directamente de un túnel de temperatura $x_i$ a otro de temperatura $x_j$ cuesta:

$$
|x_i-x_j|
$$

Una posibilidad sería conectar cada pareja de túneles de la habitación. Sin embargo, una habitación podría tener muchos túneles y esto produciría demasiadas conexiones.

No es necesario conectar todas las parejas. Basta con conectar los túneles consecutivos según su temperatura.

Por ejemplo, si:

$$
x\leq y\leq z
$$

entonces:

$$
|x-z|=(y-x)+(z-y)
$$

Esto significa que pasar de $x$ a $z$ utilizando primero la transición hacia $y$ cuesta exactamente lo mismo que hacer el cambio directamente.

En general, si queremos pasar de $x_i$ a $x_j$, podemos recorrer las temperaturas consecutivas entre ambas. La suma de sus diferencias es:

$$
|x_i-x_j|
$$

Por lo tanto, para cada habitación solamente conectamos estados consecutivos después de ordenarlos por temperatura.

## Estado inicial

Inicialmente estamos en la habitación $1$ con nivel de enfriamiento $0$.

Si queremos utilizar como primer túnel uno de temperatura $c$, debemos pagar $c$ monedas para ajustar las botas desde $0$ hasta $c$.

Por ello, todos los estados correspondientes a túneles incidentes en la habitación $1$ se insertan inicialmente en Dijkstra con distancia igual a la temperatura de su túnel.

## Estado final

Podemos llegar a la habitación $N$ mediante cualquiera de sus túneles incidentes.

Por lo tanto, la respuesta es la menor distancia entre todos los estados asociados con la habitación $N$.

Si $N=1$, ya nos encontramos en el destino y la respuesta es $0$.

## Algoritmo

1. Leer las $M$ aristas de la gráfica.
2. Por cada túnel, crear dos incidencias:
   - Una para cada habitación conectada por el túnel.
3. Ordenar todas las incidencias utilizando:
   - Primero la habitación.
   - Después la temperatura.
4. Para cada túnel, conectar sus dos incidencias con costo $0$.
5. Para cada habitación, conectar las incidencias consecutivas en el orden de temperatura.
   - El costo de la conexión es la diferencia entre sus temperaturas.
6. Inicializar la distancia de cada incidencia de la habitación $1$ con la temperatura de su túnel.
7. Ejecutar el algoritmo de Dijkstra sobre el grafo auxiliar.
8. Imprimir la menor distancia con la que se alcanza una incidencia de la habitación $N$.

## Correctitud

Demostraremos que el algoritmo imprime el costo mínimo necesario para llegar desde la habitación $1$ hasta la habitación $N$.

### Lema 1

Atravesar un túnel se representa correctamente mediante una transición de costo $0$ entre sus dos incidencias.

#### Demostración

Antes de atravesar un túnel, el nivel de enfriamiento de las botas ya debe coincidir con su temperatura.

Atravesarlo no modifica el nivel de enfriamiento ni requiere un pago adicional.

Por lo tanto, el desplazamiento entre sus dos extremos tiene costo $0$, exactamente como se representa en el grafo auxiliar.

### Lema 2

Las conexiones entre temperaturas consecutivas permiten cambiar entre cualquier par de túneles de una habitación pagando el costo correcto.

#### Demostración

Consideremos dos túneles de una habitación cuyas temperaturas son $x$ y $y$, con $x\leq y$.

Sean:

$$
x=t_1\leq t_2\leq\cdots\leq t_k=y
$$

las temperaturas ordenadas entre ambos túneles.

El costo de recorrer las conexiones consecutivas es:

$$
(t_2-t_1)+(t_3-t_2)+\cdots+(t_k-t_{k-1})
$$

Esta suma es telescópica y se reduce a:

$$
t_k-t_1=y-x=|x-y|
$$

Este es exactamente el costo de modificar el nivel de enfriamiento desde $x$ hasta $y$.

Por lo tanto, las conexiones consecutivas representan correctamente cualquier cambio de túnel dentro de una habitación.

### Lema 3

Todo recorrido válido en la mazmorra puede representarse mediante un camino del mismo costo en el grafo auxiliar.

#### Demostración

Cada vez que el recorrido atraviesa un túnel, utilizamos la conexión de costo $0$ entre sus dos incidencias.

Cuando el recorrido cambia de un túnel de temperatura $x$ a otro de temperatura $y$ dentro de una habitación, utilizamos las conexiones consecutivas entre esas temperaturas.

Por el lema 2, el costo total de estas conexiones es $|x-y|$.

Para el primer túnel de temperatura $w_1$, la distancia inicial es $w_1$, que coincide con el costo de cambiar el nivel desde $0$ hasta $w_1$.

Por lo tanto, cada acción del recorrido original puede representarse en el grafo auxiliar sin modificar su costo total.

### Lema 4

Todo camino del grafo auxiliar corresponde a un recorrido válido en la mazmorra con el mismo costo.

#### Demostración

Una conexión de costo $0$ entre las incidencias de un mismo túnel representa atravesarlo.

Una conexión entre dos incidencias consecutivas de una habitación representa modificar el nivel de enfriamiento desde una temperatura hasta la otra sin abandonar la habitación.

Ambas acciones están permitidas por el enunciado.

Además, el costo de cada transición coincide con el número de monedas requerido para realizarla.

Por lo tanto, todo camino del grafo auxiliar representa un recorrido válido del mismo costo.

### Teorema

El algoritmo imprime el costo mínimo para llegar desde la habitación $1$ hasta la habitación $N$.

#### Demostración

Por el lema 3, todo recorrido válido tiene un camino equivalente en el grafo auxiliar con el mismo costo.

Por el lema 4, todo camino del grafo auxiliar representa un recorrido válido con el mismo costo.

Por lo tanto, encontrar el recorrido de costo mínimo en la mazmorra equivale a encontrar el camino de costo mínimo en el grafo auxiliar.

Todas las conexiones del grafo auxiliar tienen costos no negativos, por lo que Dijkstra encuentra correctamente las distancias mínimas.

En consecuencia, la menor distancia hacia cualquier estado correspondiente a la habitación $N$ es exactamente el costo mínimo necesario para llegar al destino.

## Complejidad

Existen $2M$ incidencias, una por cada extremo de cada túnel.

Ordenar las incidencias requiere:

$$
O(M\log M)
$$

Cada incidencia se conecta con:

- La otra incidencia de su túnel.
- Como máximo dos incidencias consecutivas de su habitación.

Por lo tanto, el grafo auxiliar tiene $O(M)$ estados y $O(M)$ conexiones.

Dijkstra requiere:

$$
O(M\log M)
$$

En total:

- Tiempo: $O(M\log M)$
- Memoria: $O(M)$
