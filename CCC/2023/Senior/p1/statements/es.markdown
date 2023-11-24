# Descripción
Bocchi el Constructor recientemente terminó de construir su último proyecto: una carretera que consiste en dos filas de losas de forma de triángulos equiláteros blancos. Sin embargo, al último momento hubo un accidente. Accidentalmente se le cayó pintura negra en alguna de las losas. Ahora alguna de las losas están mojadas y otras están secas. Bocchi debe poner cinta de advertencia en el perímetro de las losas mojadas. ¿Puedes ayudarle a determinar cuántos metros de cinta necesita?
La primera losa triangular apunta hacia arriba. Cada par de losas adyacentes (que comparten un lado) apunta en direcciones opuestas. Cada losa tiene un lado de un metro.

# Entrada
La primera línea especifica un entero positivo $C$, representando el número de columnas.
Cada una de las siguientes dos líneas consiste de $C$ enteros separados por espacios. Cada
entero representa el color de la losa a través de la carretera, con 1 indicando que su losa está
negra (mojada) y 0 indicando si la losa es blanca (seca).

# Salida
La salida es un único entero representando la longitud en metros de cinta que necesita Bocchi.

# Ejemplo
||input
5
1 0 1 0 1
0 0 0 0 0
||output
9
||input
7
0 0 1 1 0 1 0
0 0 1 0 1 0 0
||output
11
||description
Bocchi necesita 5 metros de cinta para una zona pintada y 3 metros para las otras dos zonas distintas pintadas.
||end

A continuación se muestran los dos ejemplos:

<br />
![Figura1](figura1.jpg)
<br />

<br />
![Figura2](figura2.jpg)
<br />

# Subtarea 1 [20 puntos]
$C \leq 2000$. La carretera no es muy larga, las losas negras no son adyacentes y la segunda fila es totalmente blanca.

# Subtarea 2 [20 puntos]
$C \leq 2000$. La carretera no es muy larga, las losas negras pueden ser adyacentes y la segunda fila es totalmente blanca.

# Subtarea 3 [34 puntos]
$C \leq 2000$. La carretera no es muy larga, las losas negras pueden ser adyacentes y pueden aparecer en la segunda fila.

# Subtarea 4 [26 puntos]
$C \leq 200000$. La carretera puede ser larga, las losas negras pueden ser adyacentes y pueden aparecer en la segunda fila.

