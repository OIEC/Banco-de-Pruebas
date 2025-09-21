Los mineros producen diferente cantidad de carbón según los últimos tres envíos recibidos en su mina.

Tenemos dos minas, y cada nuevo envío hay que decidir a cuál mandarlo.

No podemos decidir localmente, porque lo que enviamos hoy cambia lo que producirá mañana (depende del historial de cada mina).

Entonces necesitamos un método que recuerde el estado de cada mina mientras vamos avanzando.

Para calcular la productividad cuando llega un nuevo envío, necesitamos conocer los dos últimos envíos de esa mina, porque con esos y el nuevo formamos el grupo de tres.

No hace falta recordar más atrás, porque lo que pasó hace 4 turnos ya no influye.

Eso significa que el "estado" de una mina se resume en los últimos dos envíos recibidos.
Ejemplos de estados: vacío (no recibió nada), "M", "F", "B", "MF", "BB", etc.

Procesamos los envíos uno por uno en orden.

Para cada envío, tenemos dos opciones: mandarlo a la mina $A$ o a la mina $B$.

Según a dónde lo mandemos:

Actualizamos el historial de esa mina (agregamos el envío y nos quedamos solo con los últimos dos).

Calculamos cuántas unidades de carbón produce (dependiendo de si ahora los últimos tres son todos iguales, hay dos tipos, o tres tipos).

Sumamos esa producción al total acumulado.

Imagina una tabla $dp[i][estadoA][estadoB]$ = la máxima cantidad de carbón que se puede obtener después de procesar los primeros $i$ envíos, con ciertos estados de las dos minas.

Al inicio, antes de procesar nada, ambos estados están vacíos.

Cuando llega un envío, probamos las dos opciones (mina $A$ o mina $B$).

Eso genera nuevos estados, y vamos guardando siempre la mejor producción alcanzada.

Al final, entre todos los estados posibles después de usar los $n$ envíos, buscamos el máximo.

Cada mina puede estar en unos 13 estados distintos (vacío, un envío, o dos envíos).

Entonces en total hay como mucho $13 \times 13 = 169$ combinaciones de estados.

Para cada envío recorremos esos estados y probamos dos opciones.

La complejidad es proporcional a $n \times 169 \times 2$, que es lineal en $n$ y muy rápido incluso si $n$ es grande.
