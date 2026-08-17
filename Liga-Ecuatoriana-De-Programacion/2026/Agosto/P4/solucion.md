# Editorial — Cuerdas y Pelotas

## Planteamiento del problema

Se tienen $N$ cuerdas, cada una definida por dos posiciones $a_i, b_i$ en una recta (no necesariamente $a_i \le b_i$). Se realizan $Q$ lanzamientos, cada uno en una posición $q_j$. Para cada lanzamiento hay que responder: **¿por debajo de cuántas cuerdas pasa la pelota?**

Analizando el ejemplo se deduce la condición exacta: una pelota lanzada en la posición $q$ pasa por debajo de la cuerda $i$ si y solo si

$$\min(a_i, b_i) \le q \le \max(a_i, b_i)$$

es decir, si $q$ cae **dentro del intervalo cerrado** definido por los extremos de la cuerda (incluyendo ambos extremos — se verifica, por ejemplo, con $q=3$ y $q=7$ en la tercera cuerda del ejemplo, ambos cuentan).

El problema se reduce entonces a, para cada consulta $q_j$, **contar cuántos de los $N$ intervalos $[\min(a_i,b_i), \max(a_i,b_i)]$ contienen a $q_j$**.

---

## Idea de la solución

### Observación clave

Contar cuántos intervalos contienen un punto $q$ es equivalente a:

$$\#\{i : l_i \le q\} \;-\; \#\{i : r_i < q\}$$

donde $l_i = \min(a_i, b_i)$ y $r_i = \max(a_i, b_i)$.

**Intuición:** un intervalo $[l_i, r_i]$ "ya empezó" en $q$ si $l_i \le q$, y "ya terminó antes de $q$" si $r_i < q$. Los intervalos que contienen a $q$ son justamente los que empezaron pero no han terminado.

### Algoritmo eficiente (offline)

Como las $N$ cuerdas **no cambian** durante todas las consultas (no hay actualizaciones), podemos preprocesarlas una sola vez y responder cada consulta con **búsqueda binaria**:

1. Construir dos arreglos: `ls` con todos los $l_i$, y `rs` con todos los $r_i$.
2. **Ordenar** ambos arreglos ($O(N \log N)$).
3. Para cada consulta $q$:
   - `cntL` = cantidad de elementos en `ls` que son $\le q$ → se obtiene con `upper_bound(ls, q)`.
   - `cntR` = cantidad de elementos en `rs` que son $< q$ → se obtiene con `lower_bound(rs, q)`.
   - La respuesta es `cntL - cntR`.

Cada consulta se responde en $O(\log N)$ gracias a la búsqueda binaria sobre arreglos ya ordenados.

### Verificación con el ejemplo

Cuerdas: $[0,3], [2,4], [3,7]$ → `ls = [0,2,3]` (ordenado), `rs = [3,4,7]` (ordenado).

- $q=4$: `cntL` = cuántos $l_i \le 4$ → los 3 → `cntL=3`. `cntR` = cuántos $r_i < 4$ → solo el 3 → `cntR=1`. Respuesta = $3-1=2$. ✓ (coincide con el ejemplo del enunciado: pasa por debajo de la 2ª y 3ª cuerda).
- $q=0$: `cntL`=1 (solo el 0), `cntR`=0 (ningún $r_i<0$). Respuesta=1. ✓
- $q=3$: `cntL`=3 (0,2,3 ≤3), `cntR`=0 (ningún $r_i<3$, ya que el menor $r_i$ es 3). Respuesta=3. ✓

Todo coincide con la salida esperada.

---

## Análisis por subtareas

### Subtarea 1 (20 pts) — $1 \le N, Q \le 1000$

Con $N, Q \le 1000$, incluso una solución de **fuerza bruta** $O(N \cdot Q)$ (por cada consulta, recorrer las $N$ cuerdas y verificar si $q$ cae en el intervalo) es suficiente: en el peor caso son $1000 \times 1000 = 10^6$ operaciones, perfectamente rápido.

### Subtarea 2 (30 pts) — $N \le 10\,000$, $Q \le 100\,000$, coordenadas en $[-2000, 2000]$

Aquí la fuerza bruta $O(N \cdot Q)$ ya no alcanza ($10^4 \times 10^5 = 10^9$, demasiado lento). Sin embargo, como las coordenadas están acotadas en un rango pequeño ($[-2000,2000]$, es decir, a lo más $4001$ valores posibles), se puede usar un **arreglo de diferencias**:

- Por cada cuerda $[l_i, r_i]$, hacer `diff[l_i] += 1` y `diff[r_i + 1] -= 1`.
- Calcular la suma prefija de `diff` sobre todo el rango de coordenadas, obteniendo directamente cuántas cuerdas cubren cada posición.
- Cada consulta se responde en $O(1)$ tras el preprocesamiento $O(N + \text{rango})$.

Esta solución es válida solo mientras el rango de coordenadas sea pequeño, ya que su complejidad depende del tamaño del rango, no de $N$.

También funciona, sin cambios, la solución general por **ordenamiento + búsqueda binaria** descrita arriba, con complejidad $O((N+Q)\log N)$, independiente del rango de coordenadas.

### Subtarea 3 (50 pts) — $N, Q \le 100\,000$, coordenadas hasta $\pm 2^{30}$

Con coordenadas de hasta $2^{30}$ (aprox. $10^9$), el enfoque de arreglo de diferencias por rango **ya no es viable** (el rango es demasiado grande para un arreglo). Se necesita el enfoque de **ordenamiento + búsqueda binaria** descrito en la sección anterior:

- Preprocesamiento: $O(N \log N)$ para ordenar `ls` y `rs`.
- Cada consulta: $O(\log N)$ con dos búsquedas binarias.
- **Total:** $O((N + Q) \log N)$.

Con $N = Q = 10^5$, esto da aproximadamente $2 \times 10^5 \times \log_2(10^5) \approx 3.4 \times 10^6$ operaciones — muy rápido y con margen amplio de tiempo. Se debe usar un tipo de dato de al menos 32 bits con signo para las coordenadas (`int` de 32 bits alcanza para $\pm 2^{30}$, pero se recomienda `long long` para evitar cualquier problema de límites).

**Esta misma solución (ordenamiento + búsqueda binaria) resuelve las tres subtareas sin modificaciones**, por lo que es la solución recomendada de implementar directamente.
