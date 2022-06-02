# Solución
Con el uso de una función, es sencillo implementar una solución recursiva, de forma que podamos encontrar los primeros casos del problema. Sin embargo, esto no es suficiente para resolver todos los casos de forma óptima ya que la complejidad de tiempo se vuelve exponencial. Para resolver el problema de forma óptima necesitamos resolver el problema de forma iterativa. La manera de hacer esto es llenando el elemento de cada fila basada en los elementos de la fila anterior, uno por uno. Es decir, para calcular los elementos de la fila $N$, calculamos todas las filas, de la 1 a la $N$ de forma iterativa.

Existe otra forma de resolver el problema de forma eficiente: usando matemáticas podemos relacionar los elementos del triángulo de Pascal con los coeficientes binomiales `C(n,k) = n!/(n-k)!k!` 
ya que `C(n,k) = C(n-1,k) + C(n-1,k-1)`.

Existe una solución errónea calculando los factoriales del numerados y denominador y dividiéndolos (el numerador podría desbordarse). Hay una solución correcta en `O(k)` tiempo simplificando los factoriales en el numerador y denominador usando la fórmula:
`C(n,k) = (n*...*(n-k+1))/(k*(k-1)*...*1)`
