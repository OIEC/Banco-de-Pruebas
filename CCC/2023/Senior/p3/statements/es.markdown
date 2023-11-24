# Descripción
Ryo y Kita están diseñando un nuevo póster para la banda Kessoku. Luego de pensarlo,
llegaron a la conclusión que el póster debe ser en forma de cuadrícula 2-D de letras minúsculas
en Inglés (i.e. a a la z), con $N$ filas y $M$ columnas.
Más aún, sabemos que a Ryo y Kita les gustan los palíndromos. Ryo solamente estará
contenta si el póster tiene exactamente $R$ de sus filas siendo palíndromos, y Kita solamente
estará contenta con el póster si exactamente $C$ de sus columnas son palíndromos. ¿Puedes
diseñar un póster que tenga contenta a las dos, o determinar si es imposible?

**Nota**: Una palabra es un palíndromo si se lee igual en ambas direcciones. Por ejemplo,
kayak y cc son palíndromos, pero guitarra y vivo no lo son.

# Entrada
La primera y única línea consiste en 4 enteros $N$, $M$, $R$, y $C$ separados por un espacio.

# Salida
Si es imposible diseñar un póster que satisfaga a ambas, imprimir IMPOSSIBLE en una única línea.
De otra forma, tu salida debe contener $N$ filas, cada una que consiste en $M$ letras, representando tu póster.
Si hay múltiples posibles pósters, tu salida puede tener cualquiera.

# Ejemplo
||input
4 5 1 2
||output
union
radar
badge
anime
||description
En este póster, solo la segunda fila (radar) y la segunda y tercera columna (naan y iddi)
son palíndromos. Ya que $R = 1$ y $C = 2$, este es un diseño aceptable.
||input
2 2 2 1
||output
IMPOSSIBLE
||description
Se puede demostrar que no es posible crear un póster que satisfaga las condiciones.
||end

# Subtarea 1 [14 puntos]
$2 \leq N \leq 2000$

$2 \leq M \leq 2000$

$R = 1$

$C = 1$

# Subtarea 2 [14 puntos]
$N = 2$

$M = 2$

$0 \leq R \leq N$

$0 \leq C \leq M$

# Subtarea 3 [26 puntos]
$N = 2$

$2 \leq M \leq 2000$

$0 \leq R \leq N$

$0 \leq C \leq M$

# Subtarea 4 [46 puntos]
$2 \leq N \leq 2000$

$2 \leq M \leq 2000$

$0 \leq R \leq N$

$0 \leq C \leq M$


