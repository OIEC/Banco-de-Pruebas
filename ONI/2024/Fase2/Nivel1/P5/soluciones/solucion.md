### **Subtarea 1: Movimiento Ascendente y Uso Exclusivo de +1**

En esta subtarea, no es necesario usar la operación $\times 2$, y el recorrido está en orden ascendente. Esto implica que solo tiene sentido usar la operación $+1$, ya que usar $-1$ nos alejaría de nuestro objetivo. El número de pasos necesarios para ir de $x$ a la última casa del recorrido es simplemente $\text{última casa} - x$, porque cada incremento $+1$ nos acerca al destino.

### **Subtarea 2: Diferencia Absoluta Entre Casas Consecutivas**

En esta subtarea, tampoco necesitamos usar $\times 2$, pero el recorrido ya no está en orden ascendente. Para movernos entre dos casas consecutivas, podemos usar $+1$ o $-1$ según sea necesario. La cantidad mínima de pasos entre dos casas consecutivas es igual a la diferencia absoluta $|y_2 - y_1|$.

Para todo el recorrido, basta con sumar las diferencias absolutas entre cada par consecutivo:
$\text{Total pasos} = |y_1 - x| + |y_2 - y_1| + |y_3 - y_2| + \dots + |y_n - y_{n-1}|$

### **Subtarea 3: Uso Completo de las Tres Operaciones**

En esta subtarea, podemos usar todas las operaciones: $+1$, $-1$ y $\times 2$. Para encontrar el número mínimo de pasos entre dos casas consecutivas, usamos el recorrido de grafos en profundidad BFS, ya que este garantiza la ruta más corta en un grafo donde cada posición es un nodo y las operaciones son aristas.

El total de pasos para el recorrido se calcula como:
$\text{Total pasos} = \text{BFS}(x, y_1) + \text{BFS}(y_1, y_2) + \dots + \text{BFS}(y_{n-1}, y_n)$
