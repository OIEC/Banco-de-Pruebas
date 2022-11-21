Para la primera subtarea, podemos iterar sobre todos los valores posibles de $(a,b,c,d)$ en 4 ciclos anidados distintos incrementando un contador si $a + 2b + 3c + 4d == n$.

Para la segunda subtarea, podemos notar que para valores de $b$, $c$ y $d$, el valor de $a$ es fijo e igual a $n - 4d - 3c - 2b$. Mientras este valor sea positivo, se incrementa el contador. Esto indica que solamente necesitamos 3 bucles. Además podemos acotar los rangos de $b$, $c$ y $d$ notando que 
$b \leq \frac{n}{2}$, $c \leq \frac{n}{3}$ y $d \leq \frac{n}{4}$.