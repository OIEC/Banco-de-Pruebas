Sea $d$ la cantidad de números consecutivos. Sabemos que la secuencia $x$, $x+1$, $x+2$ , ... , $x+d-1$ tiene como suma $dx + \frac{d(d-1)}{2}$. Usamos dos bucles, uno para $d$ y uno para $x$, que atraviesen todos los números entre 1 y $n$ para hallar todas las soluciones que cumplan la condición. Esto lleva $O(n^2)$.

Podemos concluir que $x=\frac{2n - d^2 + d}{2d}$. Hacemos un bucle para todos los valores de $d$ tal que $2n - d^2 + d$ sea divisible para $2d$, ya que $x$ es entero. Esta solución toma $O(N^2)$
