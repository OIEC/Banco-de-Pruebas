## Solución
Sea `m` la cantidad de dígitos que debemos de borrar de un cierto número `N`, digamos que `N` tiene `w` dígitos. Sea `R` el número deseado (para nuestros fines, asumamos que `R` puede tener ceros a la izquierda). `R` tendrá `w-m` dígitos.
Para obtener `R`, basta con repetir el siguiente proceso `w-m` veces, cada vez obteniendo un dígito de `R` nuevo:
Sea `i` la cantidad de dígitos que quedan por borrar y `k` el número del que queremos borrar dichos dígitos.
- Con la ayuda de un bucle leemos los primeros `i+1` dígitos a la izquierda de `k` y guardamos en la variable `menor_ahora` el valor del menor de dichos dígitos. Sea `a` dicho dígito. (Si dentro de los `i+1` dígitos leidos hay más de uno con el valor `menor_ahora`, entonces `a` será el que esté más a la izquierda). Digamos que a la izquierda de `a` hay otros `j` dígitos.
- `a` será el siguiente dígito de `R`.
- De `k` borramos a  `a` y a todos los dígitos a la izquierda de `a`, tomamos al número resultante como el nuevo valor de `k` y a `i-j` como nuestro nuevo valor de `i` y repetimos el proceso de ser necesario.

Ejemplo: si se dan los valores `N=16259` y `m=2` se necesitarán `(5-2)=3` repeticiones, lo siguiente ocurre en las mismas: <br />

1. Se leen los dígitos `1`, `6` y `2`. De entre ellos `1` es el menor.
Hay 0 dígitos a la derecha del `1`.
Ahora sabemos que el primer dígito de nuestra respuesta es `1`.
Para la siguiente repetición se tomarán los valores `N=6259` y `m=(2-0)=2`.

2. Se leen los dígitos `6`, `2` y `5`. De entre ellos `2` es el menor.
Hay 1 dígito a la derecha del `2`.
Ahora sabemos que el segundo dígito de nuestra respuesta es `2`.
Para la siguiente repetición se tomarán los valores `N=59` y `m=(2-1)=1`.

3. Se leen los dígitos `5` y `9`. De entre ellos `5` es el menor.
Ahora sabemos que el tercer dígito de nuestra respuesta es `5`.
No se necesitan más repeticiones.

Nuestra respuesta es entonces `125`.
