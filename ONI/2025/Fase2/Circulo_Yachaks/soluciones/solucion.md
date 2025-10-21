Para la primera subtarea podemos iterar sobre todos los valores $k$ entre $3$ y $N$, verificando si el valor $k$ es divisor de $N$. Si es así imprimimos $k$ y $\frac{N}{k}$. Esta solución funciona en $O(N)$ y obtiene 50 puntos.

Para optimizar la solución, notamos que solamente necesitamos iterar para los valores de $k$ entre $3$ y $\sqrt{N}$, ya que los divisores vienen en pares por lo tanto el menor divisor en una pareja de 2 divisores que multiplicados den $N$, siempre será a lo mucho $\sqrt{N}$. Caso contrario el resultado sería mayor a $N$. Con esto en mente podemos desarrollar una solución que tome tiempo $O(\sqrt{N})$ y obtiene 100 puntos.

