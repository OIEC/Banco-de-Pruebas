Del ejemplo podemos notar que el cálculo se vuelve más fácil si las villas están ordenadas de menor a mayor.

Además podemos notar que para calcular el tamaño del vecindario de una villa, podemos sumar los tamaños de los vecindarios con respecto a las villas de la izquierda y de la derecha. 
La longitud del vecindario entre dos villas está definida por la distancia al punto medio entre ambas. Es decir, si las villas son $a$ y $b$ con ($a < b$), el tamaño del vecindario entre ellas es $\frac{b - a}{2}$.

Por lo tanto, para cada villa $v_i$ ($1 \leq i \leq N - 1$), la longitud de su vecindario será $\frac{v_i - v_{i-1}}{2}$ + $\frac{v_{i+1} - v_{i}}{2}$. Simplemente debemos guardar el mínimo entre todas estas expresiones.

La subtarea 1 admite cualquier solución que corra en tiempo $O(N^2)$. Un ejemplo puede ser ordenando usando ordenamiento burbuja, o cualquier otro tipo de ordenamiento o algoritmo que no corra en $O(N \log N)$ sino en $O(N^2)$.

La segunda subtarea puede ser resuelta utilizando un ordenamiento eficiente que corra en $O(N \log N)$, siendo un ejemplo el ordenamiento por mezcla. Sin embargo lo más conveniente es usar algoritmos de la biblioteca estándar como std::sort, y no usar nuestra propia implementación.
