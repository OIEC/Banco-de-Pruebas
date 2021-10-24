**Solución:**

Para cambiar un número `n` en base decimal `a` a una base `b`, es necesario dividir el número continuamente y obtener los respectivos residuos, que es lo que representa al número en la nueva base. Por ejemplo, para convertir `17` a base `3`, se realizan las siguientes operaciones: `17%3=2` y `17/3=5`, `5%3=2` y `5/3=1`, `1%3=1`y `1/3=0`; por lo cual `17` en base 3 es `122`.  

Esto se puede realizar con un bucle e ir almacenando los residuos en una cadena de caracteres. Hay que tomar en cuenta que los residuos pueden ser mayores a 10 para bases mayores a 10, por lo que hay que usar las letras `a-f` cuando sea necesario.
