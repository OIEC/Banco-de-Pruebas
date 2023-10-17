Primero notar que la cantidad de agua en el contenedor formada por las barras $l < r$ es $A(l,r) = (r-l) \times min(h[l], h[r])$ donde $h[k]$ es la altura de la barra $k$.

La solución por fuerza bruta consiste en probar todas las parejas de barras y hallar el área más grande. Esta solución lleva tiempo $O(n^2)$ y no es lo suficientemente eficiente como para resolver la segunda subtarea. 

Intentaremos estructurar una solución que solo requiera una iteración por sobre las barras, de afuera hacia adentro. La idea para optimizar el tiempo es darnos cuenta que podemos descartar muchos contenedores haciendo un solo movimiento en cada paso. Por ejemplo, si tenemos un contenedor con barras $l < r$, podemos fijar la barra de altura mayor e intentar avanzar con la barra menor. Esto se hace ya que mantener la barra mayor nos da la posibilidad de encontrar una área más grande más adelante, ya que la altura menor limita cualquier área que encontremos. Seguimos haciendo estos movimientos, recordando el mayor área que hayamos visto.

Para demostrar que este algoritmo funciona basta con demostrar que cada movimiento descarta correctamente a los contenedores en cuestión.
Formalmente y sin pérdida de generalidad, si $h[l] < h[r]$ entonces para todo $l < k < r$ tenemos que:

$A(l, k) = (k-l) \times min (h[k], h[l]) \leq (k-l) \times h[l] < (r-l) \times h[l] = A(l, r)$.

lo que concluye que $A(l, k) < A(l, r)$.

De forma similar si $h[l] > h[r]$ entocnes $A(k, r) < A(l, r)$ para todo $l < k < r$.

Esta demostración establece que el algoritmo es correcto. Por ser una iteración lineal sobre las barras de afuera hacia adentro, corre en tiempo asintótico $O(n)$ y pasa todas las subtareas.
