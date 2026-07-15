# Editorial - Tipos de Triángulos

## Idea

Se nos proporcionan las longitudes $x$, $y$ y $z$ de los tres lados de un triángulo válido.

Debemos clasificarlo según la cantidad de lados iguales:

- **Equilátero:** los tres lados son iguales.
- **Isósceles:** exactamente dos lados son iguales.
- **Escaleno:** los tres lados son diferentes.

Primero comprobamos si los tres valores son iguales. Esta condición debe revisarse antes que la del triángulo isósceles, ya que un triángulo equilátero también cumple que existen dos lados iguales.

Si no es equilátero, verificamos si alguna de las tres parejas de lados tiene la misma longitud:

$$
x=y,\qquad x=z,\qquad y=z
$$

Si alguna igualdad se cumple, el triángulo es isósceles. En caso contrario, los tres lados son diferentes y el triángulo es escaleno.

El enunciado garantiza que las longitudes proporcionadas forman un triángulo válido, por lo que no es necesario verificar la desigualdad triangular.

## Algoritmo

1. Leer los enteros $x$, $y$ y $z$.
2. Si $x=y$ y $y=z$, imprimir `equilatero`.
3. En caso contrario, verificar si se cumple al menos una de las siguientes condiciones:
   - $x=y$
   - $x=z$
   - $y=z$
4. Si alguna de las condiciones anteriores se cumple, imprimir `isosceles`.
5. Si ninguna igualdad se cumple, imprimir `escaleno`.

## Correctitud

Demostraremos que el algoritmo imprime correctamente el tipo del triángulo.

Analizaremos todos los casos posibles.

### Caso 1: los tres lados son iguales

Si:

$$
x=y
$$

y:

$$
y=z
$$

entonces se cumple que:

$$
x=y=z
$$

Por lo tanto, los tres lados tienen la misma longitud. Por definición, el triángulo es equilátero y el algoritmo imprime `equilatero`.

### Caso 2: exactamente dos lados son iguales

Si los tres lados no son iguales, pero se cumple al menos una de las siguientes igualdades:

$$
x=y,\qquad x=z,\qquad y=z
$$

entonces existe una pareja de lados con la misma longitud.

Como el caso en el que los tres lados son iguales ya fue descartado, exactamente dos lados son iguales.

Por definición, el triángulo es isósceles y el algoritmo imprime `isosceles`.

### Caso 3: los tres lados son diferentes

Si no se cumple ninguna igualdad entre $x$, $y$ y $z$, entonces:

$$
x\neq y,\qquad x\neq z,\qquad y\neq z
$$

Por lo tanto, los tres lados tienen longitudes diferentes.

Por definición, el triángulo es escaleno y el algoritmo imprime `escaleno`.

### Teorema

Los tres casos anteriores cubren todas las posibles relaciones de igualdad entre las longitudes de los lados.

En cada caso, el algoritmo imprime exactamente la clasificación correspondiente.

Por lo tanto, el algoritmo siempre determina correctamente el tipo del triángulo.

## Complejidad

El algoritmo realiza una cantidad constante de comparaciones.

- Tiempo: $O(1)$
- Memoria: $O(1)$
