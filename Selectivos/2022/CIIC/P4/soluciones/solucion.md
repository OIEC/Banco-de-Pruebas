# Solución

La solución a este problema usa programación dinámica. 

Llamamos `sumandos` al arreglo de números dado en el problema. 

Empezamos contruyendo un arreglo de `n + 1` elementos, llamado `sumas`, donde el elemento en posición `i` representa la cantidad de sumas que se pueden generar usando el arreglo `sumandos` y que suman `i`, por lo cual la solución al problema va a estar ubicada en `sumas[n]`. Inicialmente asignamos 0 a todos los valores de `sumas`, excepto al elemento en posicion 0, al que inicializamos como 1 porque solo existe una manera de sumar 0 (no escogiendo ningun elemento de `sumandos`). Luego, procedemos a atravesar `sumas` y para cada número acualizamos el mismo arreglo según los números en `sumandos`; si podemos obtener `k` de `i + sumandos[j]`, entonces a la cantidad de maneras de obtener `k` le sumamos la cantidad de maneras de sumar `i`, es decir, `sumas[k] = sumas[k] + sumas[i]`.

En el ejemplo dado donde tenemos `n = 4` y el arreglo `[1 2 3]`:
- `[1 0 0 0 0]`
- `[1 1 1 1 0]`
- `[1 1 2 2 1]`
- `[1 1 2 4 3]`
- `[1 1 2 4 7]`

Por lo que la solución es 7.

Otra manera de ver el problema es, suponiendo que `f` es la función que determina el número de sumas que se pueden formar a partir de los números en el arreglo, `a_1`, `a_2`, ... , `a_k` los números en el arreglo y el total `n`. Entonces podemos decir que `f(n) = f(n - a_1) + ... + f(n - a_k)`.

Nuevamente usando el ejemplo dado:
- `f(4) = f(3) + f(2) + f(1)`
- `f(3) = f(2) + f(1) + f(0)`
- `f(2) = f(1) + f(0)`
- `f(1) = f(0)`
- `f(0) = 1`

Resolviendo las ecuaciones obtenemos que `f(4) = 7`.

Al primer acercamiento se lo conoce como bottom-up, mientras que al segundo como top-down.
