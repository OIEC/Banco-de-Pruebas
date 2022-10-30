Para resolver el problema empezamos definiendo el concepto de *cima local* como un valor en el arreglo tal que ese valor es mayor al valor previo y al siguiente inmediatamente.

Luego hacemos las siguientes observaciones:
1. La cima final es una *cima local*.
2. Un arreglo con dos *cimas locales* no es montañoso.
3. Un arreglo sin *cimas locales* no es montañoso. 
4. Si solamente existe una *cima local* en el arreglo, entonces esa cima es la cima final y el arreglo es montañoso.

No demostraremos cada una de estas observaciones, pero es fácil convencerse de ellas con ejemplos y debido a la definición de montañoso y de cima.

Con estas 4 observaciones, nuestra solución se basa en intentar encontrar la *única* cima local del arreglo. Iteramos sobre el arreglo determinando si el elemento en cuestión es una cima local. Si es que lo es tenemos dos casos:
1. Una cima local no ha sido encontrada aún: guardamos el valor de la cima y recordamos el hecho que ha sido encontrada en una variable booleana (verdadero o falso) y continuamos con la iteración.
2. Una cima local ya fue encontrada: el arreglo no puede ser montañoso debido a la observación 2. Nos retiramos de la iteración usando un `break`.

Al final de la iteración, si es que existió exactamente una cima local la imprimimos. Caso contrario, si no existen o hay más de una, imprimimos -1.