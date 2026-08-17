# Editorial

## Planteamiento del problema

Cada día $i$ se conocen cuatro valores:
- $p_i$: kilogramos totales vendidos ese día (manzanas + naranjas)
- $m_i$: precio del kilo de manzana
- $n_i$: precio del kilo de naranja
- $t_i$: soles totales recaudados ese día

Como no sobra fruta, si $a_i$ y $o_i$ son los kg de manzanas y naranjas vendidos el día $i$, se cumple el sistema:

$$a_i + o_i = p_i$$
$$m_i \cdot a_i + n_i \cdot o_i = t_i$$

Despejando $o_i = p_i - a_i$ y sustituyendo en la segunda ecuación:

$$m_i \cdot a_i + n_i (p_i - a_i) = t_i$$
$$a_i (m_i - n_i) = t_i - n_i \cdot p_i$$
$$a_i = \frac{t_i - n_i \cdot p_i}{m_i - n_i}$$

El enunciado garantiza $m_i \neq n_i$ (evitando división por cero) y que el resultado siempre es un entero, así que basta con acumular $a_i$ y $o_i = p_i - a_i$ sobre los $d$ días.

Esta es la **única idea** del problema; lo que cambia entre subtareas son solo los límites, lo que afecta el tipo de dato y, en implementaciones ingenuas, la eficiencia de lectura/escritura.

---

## Grupo 1 (20 pts) — $d \le 100$, valores $\le 100$

Con límites tan pequeños, **cualquier solución correcta funciona**, incluso una $O(d^2)$ o con entrada/salida lenta. El único requisito es plantear correctamente el sistema de ecuaciones de arriba. Los productos y sumas involucrados son minúsculos (a lo más $100 \times 100 = 10^4$), por lo que un `int` de 32 bits es más que suficiente sin riesgo de overflow.

**Complejidad esperada:** $O(d)$, trivialmente eficiente para $d \le 100$.

---

## Grupo 2 (40 pts) — $d \le 10\,000$, valores $\le 10^5$

Aquí ya es necesario resolver cada día en $O(1)$ (evitar, por ejemplo, iterar buscando la combinación de $a_i, o_i$ que cumpla las ecuaciones, lo cual sería $O(p_i)$ por día y podría llegar a $O(d \cdot \max p_i) \approx 10^9$, demasiado lento).

Con la fórmula cerrada $a_i = (t_i - n_i p_i)/(m_i - n_i)$, cada día se resuelve en $O(1)$, dando un total de $O(d)$.

**Cuidado con el tamaño de los números:** el producto $n_i \cdot p_i$ puede llegar a $10^5 \times 10^5 = 10^{10}$, que **ya no cabe en un `int` de 32 bits** (límite ~$2.1 \times 10^9$). Aquí empiezan a aparecer errores de overflow si no se usa `long long` (o `long` en Java, etc.).

**Complejidad:** $O(d)$ tiempo, $O(1)$ memoria extra (aparte de la lectura).

---

## Grupo 3 (40 pts) — $d \le 10^5$, valores $\le 10^5$

Los límites suben a $d \le 10^5$, pero el algoritmo **no cambia**: sigue siendo $O(d)$ con la misma fórmula. Lo que se vuelve crítico es:

1. **Overflow:** los totales acumulados $\sum a_i$ y $\sum o_i$ pueden llegar hasta $d \times \max(p_i) = 10^5 \times 10^5 = 10^{10}$, muy por encima del rango de `int`. Es obligatorio usar `long long` (64 bits) tanto para los cálculos por día como para los acumuladores.
2. **I/O rápida:** con hasta $10^5$ líneas de 4 enteros ($4\times10^5$ enteros en total), usar `cin`/`cout` sin `sync_with_stdio(false)` o usar `scanf/printf` es recomendable para evitar TLE por entrada/salida lenta.

**Complejidad final:** $O(d)$ tiempo, $O(1)$ memoria extra — la misma solución que en el Grupo 1, solo que ahora es indispensable el cuidado con los tipos de datos y la velocidad de I/O.

---

## Solución en C++ (subtarea final)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    cin >> d;

    long long totalManzanas = 0;
    long long totalNaranjas = 0;

    for (int i = 0; i < d; i++) {
        long long p, m, n, t;
        cin >> p >> m >> n >> t;

        // Sistema:
        //   a + o = p
        //   m*a + n*o = t
        // => a = (t - n*p) / (m - n)
        long long a = (t - n * p) / (m - n);
        long long o = p - a;

        totalManzanas += a;
        totalNaranjas += o;
    }

    cout << totalManzanas << " " << totalNaranjas << "\n";

    return 0;
}
```

### Notas de implementación
- Todos los cálculos intermedios (`n*p`, `m-n`, etc.) se hacen en `long long` para evitar overflow, ya que productos como $n \cdot p$ pueden alcanzar $10^{10}$.
- `sync_with_stdio(false)` junto con `cin.tie(nullptr)` acelera la lectura para los $10^5$ días del Grupo 3.
- No se requiere ninguna estructura de datos adicional: basta con procesar cada día de forma independiente y acumular, ya que el problema tiene una fórmula cerrada por día.
