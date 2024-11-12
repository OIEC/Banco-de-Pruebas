Dado que los datos en la **Subtarea 1** son muy pequeños, podemos emplear una solución simple. En este caso, sabemos que el arreglo de profundidades no tendrá más de 10 elementos y que solo contendrá un máximo de 2 números distintos.

Por lo tanto, no necesitamos un enfoque general para manejar una gran variedad de números, sino que nos basta con identificar los dos números que se repiten y contar cuántas veces aparecen.

1. **Almacenamiento de los dos números distintos**: El código mantiene dos variables (`primer_numero` y `segundo_numero`) para guardar los dos valores distintos encontrados en el arreglo de profundidades.
2. **Contadores**: Además, se mantienen dos contadores (`cuenta_primer_numero` y `cuenta_segundo_numero`) que cuentan cuántas veces aparecen estos dos números.
3. **Consultas**: Para cada consulta, el programa simplemente compara si el número preguntado corresponde a `primer_numero` o `segundo_numero` y responde con el respectivo contador, o imprime 0 si no corresponde a ninguno.

Para la segunda y tercera subtarea, el número de elementos del arreglo y el número de consultas aumenta, pero la mayor diferencia es que ahora debemos manejar casos en los que puede haber cualquier cantidad de números diferentes en el arreglo, a diferencia de la primera subtarea donde solo eran dos.

Para cada consulta, recorremos todo el arreglo para contar cuántas veces aparece el número consultado. Por cada número en el arreglo, compara si coincide con la consulta actual y cuenta las ocurrencias.
Este enfoque tiene una complejidad temporal de $O(n * m)$. Como $n \leq 100$ y $n \leq 1000000$ (lo cual sigue siendo relativamente pequeño), esta solución es aceptable para estas subtareas.

En la **Subtarea 4**, tanto el tamaño del arreglo como el número de consultas pueden ser muy grandes, llegando hasta $10^6$. Debido a esto, recorrer el arreglo completo para cada consulta ya no es viable, ya que tomaría demasiado tiempo procesar tantos elementos y consultas. En su lugar, necesitamos un enfoque que permita responder las consultas en tiempo constante después de un preprocesamiento eficiente.

Podemos utilizar un **mapa de frecuencias** para contar cuántas veces aparece cada número en el arreglo. Esto se logra durante un solo recorrido del arreglo, lo que asegura que este proceso tenga una complejidad de $O(n)$. Mientras se recorre el arreglo, cada número se guarda como clave en el mapa, y el valor asociado a esa clave es el conteo de cuántas veces aparece ese número.

Después de haber construido el mapa de frecuencias, se puede responder a cada consulta en **tiempo constante** $O(1)$. 
Para cada consulta, simplemente se accede al mapa y se imprime la frecuencia del número consultado. Si el número no está presente en el mapa, se devuelve 0.
   
El preprocesamiento del arreglo toma $O(n)$. Cada consulta toma $O(1)$, por lo que procesar todas las consultas toma $O(m)$. La complejidad total del algoritmo es $O(n + m)$, considerablemente mejor que en la subtarea anterior.

Enlace recomendado (concepto utilizado en solucion3.cpp para la subtarea 4): [https://es.wikipedia.org/wiki/Tabla_hash](https://es.wikipedia.org/wiki/Tabla_hash)
