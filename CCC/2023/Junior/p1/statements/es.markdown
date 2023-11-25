# Descripción

En un juego, Deliv-e-droid, un robot tiene que entregar paquetes mientras sortea obstáculos. Al final del juego su puntaje final se calcula en base al siguiente sistema:

 - Gana 50 puntos por cada paquete entregado.
 - Pierde 10 puntos por cada choque con un obstáculo.
 - Gana un bonus de 500 puntos si el número de paquetes entregado es mayor al número de choques con obstáculo.

Tu tarea es determinar el puntaje final del robot.

# Entrada
La primera línea contiene un entero no-negativo $P$, representando un número de paquetes entregados.
La segunda línea contiene un entero no-negativo $C$, representando el número de choques con obstáculos.

# Salida
Un único entero que representa el puntaje final.

# Ejemplo
||input
5
2
||output
730
||description
El robot entrega 5 paquetes, por lo el robot gana $5 \times 50 = 250$ puntos. Hay 2 choques, por lo que se pierden $2 \times 10 = 20$ puntos. Ya que $5>2$, se gana un bonus de 500 puntos. Dado esto el puntaje final es $250 − 20 + 500 = 730$.
||input
0
10
||output
-100
||description
Se entregan 0 paquetes, por lo que el robot gana 0 puntos. Ya que hay 10 choques se pierden 100 puntos. Ya que $0 \leq 10$, no hay un bonus. Al final el puntaje es
$0 − 100 + 0 = −100$.
||end

