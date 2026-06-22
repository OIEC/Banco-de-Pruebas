# Editorial - Salida de Emergencia

## Idea

Las secciones del submarino forman un grafo no dirigido:

- Cada sección es un vértice.
- Cada interconexión es una arista.
- La sección de salida de emergencia es la sección `N`.

Un marinero tarda una unidad de tiempo en recorrer una interconexión, por lo que el tiempo mínimo para llegar a la salida corresponde a la longitud del camino más corto hasta la sección `N`.

Debemos contar cuántos marineros pueden llegar a la salida en menos de `T` unidades de tiempo.

## Algoritmo

Como todas las aristas tienen costo 1, utilizamos BFS.

1. Construir el grafo.
2. Ejecutar BFS desde la sección `N`.
3. Obtener la distancia mínima desde cada sección hasta la salida.
4. Contar cuántas secciones distintas de `N` tienen distancia estrictamente menor que `T`.
5. Imprimir el resultado.

## Correctitud

BFS calcula la distancia mínima desde el vértice inicial a todos los demás vértices en un grafo no ponderado.

Al iniciar BFS desde la salida de emergencia (`N`), obtenemos para cada sección el tiempo mínimo necesario para llegar a la salida.

Un marinero puede escapar en menos de `T` unidades de tiempo si y solo si la distancia de su sección a `N` es menor que `T`.

El algoritmo cuenta exactamente esas secciones, por lo que la respuesta es correcta.

## Complejidad

El BFS visita cada vértice una vez y cada arista a lo sumo dos veces.

- Tiempo: **O(N + M)**
- Memoria: **O(N + M)**
