# Descripción

En un planeta muy lejano, Danielle es una apasionada observadora de estrellas. Al acostarse y observar el cielo estrellado se ha dado cuenta de que si ubicase un plano cartesiano en el cielo, en todos los puntos de coordenadas enteras habría una estrella, y no habrían estrellas en ningún otro punto. En este cielo tan aburrido se propone crear constelaciones dibujando triángulos usando 3 estrellas como vértices. Entonces, para cada triángulo que ella dibuja en el cielo, se hace la siguiente pregunta:

*¿Cuántas estrellas están dentro del triángulo y cuántas están ubicadas en su perímetro?*

Abrumada por la cantidad de estrellas que debe contar y sabiendo que eres un excelente programador, te pide que la ayudes.

# Entrada

Tres líneas, una por cada estrella (vértice). En cada línea 2 enteros separados por un espacio con las coordenadas  $x_{i} $  $ y_{i} $ de cada estrella.

# Salida

Dos enteros separados por un espacio, el primero es la cantidad de estrellas dentro del triángulo y el segundo entero es la cantidad de estrellas en el perímetro del triángulo.

# Ejemplo

||input
0 4
0 0
5 0
||output
6 10


||input
0 3
2 7
4 0
||output
10 4
||end

#Límites
$ 0  \leq x_{i} , y_{i} < 200 $


#Subtarea 1 [40 puntos]
Triángulos rectángulos cuyo vértice del ángulo recto está en el origen $(0,0)$ y sus catetos son paralelos a los ejes.

#Subtarea 2 [60 puntos]
Todo tipo de triángulos sin restricciones.

#Notas
Puedes asumir que $x_{1} \leq x_{2} \leq x_{3}$.
