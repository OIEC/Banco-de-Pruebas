Podemos expresar cualquier número como el producto de las siguientes tres expresiones:
1. La máxima potencia de 2 que lo divide: $2^a$.
2. La máxima potencia de 5 que lo divide: $5^b$.
3. Un número coprimo $k$ con ambos factores 2 y 5, por lo cual es coprimo con 10 también.

Con esto, podemos expresar $n!$ de la siguiente forma:
$$n! = 2^a * 5^b * k$$
donde $k$ es coprimo con 2 y 5.

También notamos que existen menos factores 5 que factores 2 en $n!$, simplemente por el hecho de que $5 > 2$. Esto implica que $a > b$. Podemos multiplicar $2^b * 5^b = 10^b$ y obtener la expresión:

$$n! = 2^a * 5^b * k = 2^{a-b} * k * 10^b$$.

Ya que $2^{a-b} * k$ no tiene ningún factor de 10 por definición, el valor $2^{a-b} * k * 10^b$ necesariamente termina en $b$ ceros. Recordemos que $b$ era el exponente de la mayor potencia de 5 que divide a $n!$, por lo que el problema se reduce a encontrar $b$.

En general, podemos escribir un método que calcule el exponente de la mayor potencia de 5 para cualquier valor. Para hacerlo, dividimos el número en cuestión repitidamente entre 5, hasta que no sea múltiplo de 5 (utilizando el operador módulo por ejemplo). Mantenemos una variable que cuente cuántas iteraciones esto ocurrió y esta será nuestro exponente de la mayor potencia de 5 que divide al número.

Para la subtarea 1, podemos calcular $n!$ explícitamente multiplicando en un bucle todos los valores del 1 al $n$. Enviamos este valor a la función descrita previamente y por el análisis previo, el valor que regrese esta función es la cantidad de ceros en que $n!$ termina.

El proceso de cálculo directo descrito anteriormente no funciona para valores muy grandes de $n$, pues $n!$ no cabe en ningún tipo de entero en cualquier lenguaje que usamos. Por lo tanto, para la subtarea 2 debemos calcular la cantidad de ceros sin calcular $n!$ directamente. Para esto podemos hacer la siguiente observación:

- La mayor potencia de 5 que divide un producto, es el producto de las mayores potencias de 5 de cada operando. El exponente de la mayor potencia se puede obtener sumando los exponentes de las mayores potencias de cada operando (propiedad de suma de los exponentes en la multiplicación).

La observación anterior se cumple para cualquier primo. Entonces para resolver el problema, simplemente usamos la función que obtiene el exponente de la mayor potencia de 5 que divide a cada número entre 1 y $n$, y los acumulamos iterativamente. Debido a todas las observaciones anteriores, el resultado final será la cantidad de ceros de $n!$ y esta solución obtiene los 100 puntos.
