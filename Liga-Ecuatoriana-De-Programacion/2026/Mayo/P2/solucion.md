# Editorial - Posiciona las pinturas de Pedro

## Idea

Pedro tiene dos pinturas rectangulares:

- La primera tiene base $A$ y altura $B$.
- La segunda tiene base $X$ y altura $Y$.

Las pinturas no pueden rotarse, ya que sus bases deben permanecer paralelas al suelo. Además, deben mostrarse completamente y no pueden superponerse.

Para encontrar la pared rectangular de menor perímetro, debemos considerar las dos maneras en las que las pinturas pueden quedar separadas.

### Caso 1: colocar las pinturas una al lado de la otra

En esta disposición, las bases de ambas pinturas se suman, por lo que el ancho de la pared debe ser:

$$
A+X
$$

La altura de la pared debe ser suficiente para cubrir la pintura más alta:

$$
\max(B,Y)
$$

Por lo tanto, el perímetro de esta disposición es:

$$
P_1=2\left(A+X+\max(B,Y)\right)
$$

### Caso 2: colocar una pintura encima de la otra

En este caso, las alturas se suman:

$$
B+Y
$$

El ancho de la pared debe ser suficiente para cubrir la pintura más ancha:

$$
\max(A,X)
$$

El perímetro correspondiente es:

$$
P_2=2\left(B+Y+\max(A,X)\right)
$$

Finalmente, escogemos el menor de los dos perímetros:

$$
\min(P_1,P_2)
$$

No es necesario probar otras posiciones intermedias. Si las pinturas no se superponen, necesariamente deben estar separadas horizontalmente o verticalmente.

Alinear las pinturas dentro de cada caso produce el rectángulo envolvente más pequeño posible.

## Algoritmo

1. Leer $A$, $B$, $X$ y $Y$.
2. Calcular el perímetro al colocar las pinturas una al lado de la otra:

$$
P_1=2\left(A+X+\max(B,Y)\right)
$$

3. Calcular el perímetro al colocar una pintura encima de la otra:

$$
P_2=2\left(B+Y+\max(A,X)\right)
$$

4. Imprimir:

$$
\min(P_1,P_2)
$$

## Correctitud

Demostraremos que el algoritmo encuentra el menor perímetro posible.

Como las pinturas son rectángulos que no pueden rotarse ni superponerse, sus interiores deben quedar separados en al menos una dirección.

### Separación horizontal

Si una pintura se encuentra a la izquierda de la otra, el ancho de la pared debe ser al menos:

$$
A+X
$$

La altura debe ser al menos:

$$
\max(B,Y)
$$

porque la pared debe cubrir completamente a la pintura más alta.

Por lo tanto, cualquier disposición con separación horizontal tiene perímetro de al menos:

$$
2\left(A+X+\max(B,Y)\right)
$$

Este valor puede alcanzarse colocando ambas pinturas una junto a la otra y alineándolas verticalmente.

Por ello, $P_1$ es el menor perímetro posible para este tipo de disposición.

### Separación vertical

Si una pintura se encuentra encima de la otra, la altura de la pared debe ser al menos:

$$
B+Y
$$

El ancho debe ser al menos:

$$
\max(A,X)
$$

porque debe cubrir completamente a la pintura más ancha.

Por lo tanto, cualquier disposición con separación vertical tiene perímetro de al menos:

$$
2\left(B+Y+\max(A,X)\right)
$$

Este valor puede alcanzarse apilando las pinturas y alineándolas horizontalmente.

Por ello, $P_2$ es el menor perímetro posible para este tipo de disposición.

### Teorema

Toda colocación válida pertenece al caso de separación horizontal o al de separación vertical.

El algoritmo calcula el menor perímetro posible para ambos casos y selecciona el menor entre ellos:

$$
\min(P_1,P_2)
$$

Por lo tanto, el algoritmo siempre imprime el perímetro mínimo posible.

## Complejidad

El algoritmo realiza solamente una cantidad constante de operaciones.

- Tiempo: $O(1)$
- Memoria: $O(1)$
