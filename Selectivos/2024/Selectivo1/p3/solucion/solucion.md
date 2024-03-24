Definamos $A[N]$ como la cantidad de árboles balanceados de peso $N$. Notemos que si un árbol perfectamente balanceado tiene $k$ subárboles de peso $w$, entonces por las condiciones del problema este peso debe ser 
$w = \lfloor{\frac{N}{k}}\rfloor$ ya que este es el mayor entero tal que $k \times w \leq N$. Hay $A[\lfloor{\frac{N}{k}}\rfloor]$ árboles de peso $\lfloor{\frac{N}{k}}\rfloor$. Si consideramos todas las posibles cantidad $k$ de subárboles $k = 2 \cdots N$, tenemos la siguiente fórmula:

$$A[N] = \sum_{k=2}^{N} A[\lfloor{\frac{N}{k}}\rfloor]$$

Podemos implementar una simple fórmula de programación dinámica donde calculamos $A[i]$ para $i = 1 \cdots N$ y las guardamos en un vector $A$ que usamos en nuestros cálculos. Esta solución lleva tiempo $O(N^2)$ y es suficiente para la primera subtarea.


La primera observación es que no necesitamos calcular todos los $A[i]$ para $i = 1 \cdots N-1$ para calcular $A[N]$, sino solamente los valores de $A[\lfloor\frac{N}{k}\rfloor]$ para $k = 2 \cdots N$ y sumarlos. Esto nos lleva a la idea de una solución recursiva. Esta solución nos da la segunda subtarea.

Para optimizar esta implementación podemos guardar las respuestas de $A[\lfloor\frac{N}{k}\rfloor]$ en una tabla tipo std::unordered_map y usarlas cuando las necesitemos. Esta solución nos da la subtarea 3.

La siguiente observación es que en la fórmula $$\sum_{k=2}^{N} A[\lfloor{\frac{N}{k}}\rfloor]$$ hay muchos $k$ para los que $\lfloor{\frac{N}{k}}\rfloor$ da el mismo entero, por lo que estamos haciendo varios cálculos repetitivamente. Por ejemplo, para $N = 20$ tenemos $$\sum_{k=2}^{20} A[\lfloor{\frac{20}{k}}\rfloor] = A[10] + A[6] + A[5] + A[4] + A[3] + 4 \times A[2] + 10 \times A[1]$$

Para un $k$ debemos contar cuántos valores de $k$ hay tal que $\lfloor{\frac{N}{k}}\rfloor$ es el mismo entero $j$. De esa forma calculamos directamente el multiplicador de $A[\lfloor{\frac{N}{k}}\rfloor]$. Experimentando con casos particulares como el de $N = 20$ encontramos un patrón que podemos generalizar. La cantidad de valores $k$ para los que $\lfloor{\frac{N}{k}}\rfloor = j$ es:

$$\lfloor{\frac{N}{j}}\rfloor - \lfloor{\frac{N}{j+1}}\rfloor$$

En principio esta fórmula la debemos calcular para $1 \leq j \leq N$ pero podemos notar que basta calcularla para $1 \leq j \leq \sqrt N$ ya que a partir de $j > \sqrt N $, los valores de $k$ y $w = \lfloor\frac{N}{k}\rfloor$ son simétricos. Se puede ver esto claramente en el caso particular de $N=20$ haciendo una tabla de dos columnas donde de un lado tenemos $k$ y del otro lado $\lfloor\frac{N}{k}\rfloor$. 
Los valores de $\lfloor\frac{N}{k}\rfloor > \sqrt N$, aparecen solamente una vez así que los acumulamos en un ciclo por separado.

Con esta última solución podemos calcular los multiplicadores de cada $A[\lfloor{\frac{N}{k}}\rfloor]$ eficientemente en $O(\sqrt N)$. Combinando esto y la solución recursiva se resuelve el problema.
