Podemos guardar el estado de las secciones en un arreglo $S$ de $N$ enteros con todos los valores en 0 inicialmente.

Para la primera subtarea podemos realizar un único doble ciclo en el cual levantamos la sección $S[i]$, imprimimos el estado de todas las secciones en una misma línea y luego sentamos a la sección $S[i]$.
Hacemos esto para todas las secciones $0 \leq i \leq N-1$.

Para la segunda subtarea podemos hacer lo mismo, pero lo hacemos en dos partes. El primer doble ciclo lo hace desde $k \leq i \leq N-1$, y el segundo doble ciclo lo hace desde $0 \leq i \leq k-1$.