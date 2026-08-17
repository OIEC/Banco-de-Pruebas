# Editorial — Jerarquía Marciana

## Planteamiento del problema

Tenemos $N$ soldados ordenados inicialmente del más fuerte al más débil (posiciones $1$ a $N$). Se realizan $Q$ operaciones de dos tipos:

- **`P k`**: preguntar quién es el $k$-ésimo soldado más fuerte **entre los que siguen vivos**.
- **`M k`**: el $k$-ésimo soldado más fuerte **entre los que siguen vivos** muere (se elimina de la jerarquía).

En ambos casos, $k$ se refiere a la posición relativa dentro del conjunto de soldados **actualmente vivos**, no a su posición original. Esto es clave: tras cada muerte, el "ranking" de los soldados restantes se recalcula automáticamente (como si se cerrara el hueco dejado por el soldado caído).

---

## Idea de la solución: Fenwick Tree (Árbol de Índices Binarios) para $k$-ésimo elemento activo

### ¿Por qué no fuerza bruta?

Una simulación directa con una lista/arreglo (por ejemplo, un `vector` o `list` donde eliminamos al soldado y reindexamos) resolvería cada operación en $O(N)$ en el peor caso, dando $O(N \cdot Q)$ en total. Con $N, Q \le 100000$, esto puede llegar a $10^{10}$ operaciones — **demasiado lento**.

### La estructura correcta

Necesitamos una estructura que soporte, de forma eficiente:
1. **Eliminar** un elemento.
2. **Encontrar el $k$-ésimo elemento vivo** (en orden), es decir, una consulta de **estadística de orden** dinámica.

La herramienta clásica para esto es un **Fenwick Tree (Binary Indexed Tree)** usado no para sumas típicas, sino para representar un arreglo binario de "¿está vivo?" (1 = vivo, 0 = muerto), donde:

- La **suma prefija** hasta la posición $i$ nos dice cuántos soldados vivos hay entre las posiciones $1$ y $i$.
- Buscar el **$k$-ésimo elemento vivo** equivale a encontrar la **menor posición $i$ tal que la suma prefija hasta $i$ sea exactamente $k$**.

### Inicialización

- Se crea un Fenwick Tree de tamaño $N$, inicializado con un `update(i, +1)` para cada $i = 1, \dots, N$ (todos vivos al inicio).

### Operación `P k` / `M k`

Ambas operaciones requieren primero encontrar la posición **original** del $k$-ésimo soldado vivo. Esto se hace con la técnica de **búsqueda binaria sobre el Fenwick Tree** (a veces llamada *"Fenwick tree binary lifting"* o *"find kth"*), que permite encontrar dicha posición en $O(\log N)$ sin necesidad de una búsqueda binaria externa con $O(\log^2 N)$:

```
findKth(k):
    pos = 0
    for potencia de 2 (pw) descendente, desde la mayor potencia <= N hasta 1:
        si pos + pw <= N y bit[pos + pw] < k:
            pos += pw
            k -= bit[pos]
    return pos + 1
```

Una vez obtenida la posición `pos` (índice original del soldado en la jerarquía inicial):

- Si la operación es `P k`: se imprime `nombres[pos]`.
- Si la operación es `M k`: se marca esa posición como muerta, haciendo `update(pos, -1)` en el Fenwick Tree (restando 1 a la suma prefija a partir de esa posición en adelante).

### Verificación con el ejemplo

Soldados: `1=LORQUAS, 2=WOOLA, 3=MORS` (todos vivos).

- `P 1` → el 1er soldado vivo es la posición 1 → **LORQUAS**.
- `M 1` → muere la posición 1 (LORQUAS). Ahora solo quedan vivos WOOLA (pos 2) y MORS (pos 3).
- `P 1` → el 1er soldado vivo ahora es la posición 2 → **WOOLA**.

Coincide exactamente con la salida esperada.

---

## Complejidad

- **Inicialización del Fenwick Tree:** $O(N \log N)$ (o $O(N)$ si se construye directamente sin actualizaciones una por una, aunque con $N \le 10^5$ cualquiera de las dos es instantánea).
- **Cada operación (`P` o `M`):** $O(\log N)$, gracias a la búsqueda tipo *binary lifting* sobre el Fenwick Tree, tanto para encontrar el $k$-ésimo vivo como para actualizar tras una muerte.
- **Total:** $O((N + Q) \log N)$.

Con $N, Q \le 10^5$, esto da aproximadamente $2 \times 10^5 \times \log_2(10^5) \approx 2 \times 10^5 \times 17 \approx 3.4 \times 10^6$ operaciones elementales — muy rápido y bien dentro de cualquier límite de tiempo típico.

**Memoria:** $O(N)$ para el Fenwick Tree y el arreglo de nombres.


### Notas de implementación
- Los nombres se guardan en un arreglo indexado por su **posición original** (1 a $N$), la cual nunca cambia; lo único que cambia dinámicamente es qué posiciones siguen "vivas".
- `findKth(k)` funciona porque el Fenwick Tree, tras las actualizaciones, mantiene siempre la suma prefija correcta de soldados vivos hasta cada posición; la búsqueda tipo *binary lifting* explota la estructura de potencias de 2 del árbol para ubicar el punto exacto donde la suma prefija llega a $k$, sin necesidad de una búsqueda binaria externa con múltiples consultas de suma (lo cual sería $O(\log^2 N)$).
- Se usa un solo `string out` acumulador para minimizar las llamadas a `cout`, mejorando el rendimiento de la salida cuando hay muchas consultas tipo `P`.
- Esta solución fue verificada con pruebas de estrés (*stress testing*) contra una simulación de fuerza bruta con listas, confirmando que ambas coinciden en cientos de casos aleatorios pequeños.
