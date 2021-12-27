#Descripción
Hugo el Dingo, como de costumbre, trata de atrapar a su archienemigo el Correcaminos. Habiendo ya fracasado al intentar usar imanes, trampas y explosivos, ahora decide ser un poco más observador y aprender qué tan rápido es el Correcaminos.

Hugo el Dingo y el Correcaminos viven en un carretera que va de oeste hacia este, que posee particularmente una famosa roca llamada *El Origen*. Las posiciones en esta carretera se miden numéricamente acorde a la distancia desde *El Origen*, usando números negativos para las posiciones al oeste de *El Origen* y números positivos para posiciones al este de *El Origen*.

Las observaciones de Hugo el Dingo contienen dos números: el tiempo y el valor de la posición del Correcaminos en dicho tiempo. Sabiendo estos datos ¿Cuál es la velocidad que el Correcaminos es capaz de alcanzar?


#Entrada
La primera línea contiene un número $N$, el número de observaciones de Hugo el Dingo. 

En las siguientes $N$ líneas, cada una contiene un entero $T$ indicando el tiempo en segundos de cuando una medida se realizó, y un entero $X$ indicando la posición, en metros, del Correcaminos en dicho tiempo. 

No existen dos líneas que contengan el mismo valor de $T$.


#Salida
La salida es un solo número $X$, que concluye que la velocidad del correcaminos fue al menos $X$ metros/segundos en algún punto en el tiempo, y dicho $X$ es el mayor posible. Si la respuesta correcta es $C$, se considerará correcta una solución $X$, siempre y cuando $|X-C|/C < 10 ^{-5}$.


# Ejemplo
||input
3
0 100
20 50
10 120
||output
7.0
||description
Como el Correcaminos corrió desde la posición 100 a la posición 120 entre el tiempo 0 y el tiempo 10, podemos concluir que su velocidad fue al menos 2 en algún momento: ya que si fue siempre menor a 2, entonces una distancia de 20 no pudo haber sido cubierta en 10 segundos. De la misma manera, la velocidad debió haber sido al menos 7 para viajar desde la posición 120 a 50 en 10 segundos.


||input
5
20 -5
0 -17
10 31
5 -3
30 11
||output
6.8
||description
||end

#Límites
 - $2 \leq N \leq 100000$
 - $0 \leq T \leq 1000000$
 - $-1000000000 \leq X \leq 1000000000$


#Subtarea 1 [46.67 puntos]
$N \leq 1000$.


#Subtarea 2 [53.33 puntos]
Sin restricciones

