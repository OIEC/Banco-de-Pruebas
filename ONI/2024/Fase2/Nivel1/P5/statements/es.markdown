# Descripción

Ismaning es un pequeño pueblo en el sur de Alemania. El pueblo tiene una sola calle, donde todas las casas están alineadas a lo largo de una numeración consecutiva, desde $-10^3$ hasta $10^3$. Curiosamente, en este pueblo también existen casas con números negativos. La estación postal del pueblo se encuentra en la casa con el número $x$.
<br/><br/>
Durante tus vacaciones, decides trabajar como mensajero en Ismaning. Tu primera tarea es entregar colchones a diferentes casas siguiendo rutas asignadas por la jefa de la estación postal, Cristina. Cada ruta incluye una lista de casas que debes visitar en orden. Para desplazarte entre casas, puedes usar las siguientes reglas:

1. Siempre comienzas el recorrido desde la estación postal (casa con el número $x$).
2. Las casas en la ruta deben visitarse en el orden dado, sin regresar a la estación postal entre entregas.
3. Los movimientos permitidos son:
   - Visitar la casa de alguno de los vecinos inmediatos sumando o restando uno ($+1$ o $-1$).
   - Ir directamente a la casa cuyo número sea el doble del número actual. ($\times 2$)

Tu objetivo es calcular el número mínimo de casas que debes visitar para completar toda la ruta asignada.


# Entrada

La entrada consta de dos partes:

1. Dos enteros separados por un espacio, $x$ y $n$:
   - $x$: la posición de la estación postal.
   - $n$: el número de casas en la ruta asignada.
2. Una segunda línea con $n$ enteros separados por espacio, representando los números de las casas en la ruta. Estas deben visitarse en el orden dado.


# Salida

Un entero positivo que representa el mínimo número de casas que debes visitar para completar el recorrido asignado.


# Ejemplo

||input
2 3
5 4 7
||output
5
||description
Partes desde la estación postal en la casa número $2$ y sigues este recorrido:

1. Desde la casa $2$, decides ir a la casa $5$. Puedes usar el movimiento permitido de $\times 2$ para ir a la casa $4$ y luego avanzar hasta la casa $5$.

2. Desde la casa $5$, retrocedes hasta la casa $4$.

3. Desde la casa $4$, puedes usar el movimiento permitido de $\times 2$ para ir a la casa $8$ y luego retroceder hasta la casa $7$.

Recorrido mínimo: $2 → 4 → 5 → 4 → 8 → 7$

Total de casas visitadas: 5.
||input
10 2
20 5
||output
16
||description
Recorrido:

1. Desde la casa $10$, usas el movimiento $\times 2$ para ir directamente a la casa $20$.

2. Desde la casa $20$, retrocedes paso a paso hasta la casa $5$.

Recorrido mínimo: $10 → 20 → 19 → 18 → 17 → 16 ... → 5$

Total de casas visitadas: 16.
||input
7 4
8 10 12 15
||output
8
||description
Recorrido:

1. Desde la casa $7$, avanzas a la casa $8$.

2. Desde la casa $8$, avanzas paso a paso hasta la casa $10$.

3. Desde la casa $10$, avanzas paso a paso hasta la casa $12$.

4. Desde la casa $12$, avanzas paso a paso hasta la casa $15$.

Recorrido mínimo: $7 → 8 → 9 → 10 → 11 → 12 → 13 → 14 → 15$

Total de casas visitadas: 8.
||end

# Límites
- $1 \leq n \leq 100$

# Subtarea 1 [10 puntos]
- Las casas en el recorrido están en orden ascendente.
- Los recorridos óptimos no requieren la operación de duplicar el número de casa.

# Subtarea 2 [20 puntos]
- No se requiere que las casas estén en orden ascendente.
- Los recorridos óptimos no requieren la operación de duplicar el número de casa.

# Subtarea 3 [70 puntos]
- Sin restricciones.
