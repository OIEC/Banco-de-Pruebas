# Distancia mínima entre dos vértices (costos unitarios)

## Idea

Se nos proporciona una gráfica conexa no dirigida con \(N\) vértices y \(M\) aristas. Debemos calcular la distancia mínima entre los vértices \(E\) y \(S\).

Como todas las aristas tienen costo unitario, recorrer cualquier arista aumenta la longitud del camino exactamente en \(1\). Por esta razón, podemos utilizar una búsqueda en anchura o **BFS**.

BFS comienza desde el vértice \(E\) y visita los vértices por niveles:

- Primero visita los vértices que están a distancia \(1\).
- Después, los que están a distancia \(2\).
- Luego, los que están a distancia \(3\).
- Y así sucesivamente.

La primera vez que BFS visita un vértice, lo hace utilizando la menor cantidad posible de aristas desde el origen. Por lo tanto, la distancia asignada al vértice \(S\) será la longitud del camino más corto desde \(E\).

La gráfica debe almacenarse mediante una lista de adyacencia, pues una matriz de adyacencia requeriría \(O(N^2)\) memoria, lo cual no es viable para \(N \leq 10^5\).

## Algoritmo

1. Leer los enteros \(N\), \(M\), \(E\) y \(S\).
2. Construir la lista de adyacencia de la gráfica:
   - Por cada arista entre \(u\) y \(v\), agregar \(v\) como vecino de \(u\).
   - Agregar también \(u\) como vecino de \(v\), porque la gráfica es no dirigida.
3. Crear un arreglo `distancia` e inicializar todas sus posiciones con \(-1\).
4. Asignar:
   \[
   distancia[E] = 0
   \]
5. Insertar \(E\) en una cola.
6. Mientras la cola no esté vacía:
   - Extraer el primer vértice \(u\).
   - Recorrer todos sus vecinos \(v\).
   - Si \(v\) todavía no fue visitado:
     - Asignar:
       \[
       distancia[v] = distancia[u] + 1
       \]
     - Insertar \(v\) en la cola.
7. Imprimir `distancia[S]`.

## Correctitud

Demostraremos que el algoritmo imprime la distancia mínima entre \(E\) y \(S\).

BFS comienza en \(E\), al cual asigna distancia \(0\). Después procesa los vértices en el mismo orden en que fueron descubiertos.

Cuando BFS visita un vértice \(u\) cuya distancia es \(d\), todos sus vecinos no visitados reciben distancia \(d+1\). Por lo tanto, los vértices son descubiertos en orden no decreciente de distancia desde \(E\).

Consideremos cualquier vértice \(v\) descubierto con distancia \(d\). El algoritmo llegó a \(v\) desde un vértice ubicado a distancia \(d-1\), por lo que existe un camino de \(E\) a \(v\) formado por exactamente \(d\) aristas.

Además, \(v\) no pudo ser alcanzado por un camino de menos de \(d\) aristas. Si tal camino existiera, BFS habría procesado antes los niveles correspondientes y habría descubierto a \(v\) con una distancia menor.

Por lo tanto, la primera distancia asignada a cada vértice es su distancia mínima desde \(E\). En particular, `distancia[S]` es la menor cantidad de aristas necesarias para viajar desde \(E\) hasta \(S\).

Así, el algoritmo siempre imprime la respuesta correcta.

## Complejidad

Cada vértice se inserta en la cola como máximo una vez y cada arista se examina desde sus dos extremos.

- Tiempo: \(O(N+M)\)
- Memoria: \(O(N+M)\)
