**Solución**: 

Hay muchísimas formas de resolver este problema. La solución que sigue a continuación es solamente una de las posibles variantes.

Ya que tenemos un número fijo de jugadores, podemos acumular las estadísticas a lo largo de la temporada en dos arreglos, uno para el número de minutos y otro para cantidad de goles. Para manejar el tema de las sustituciones, necesitamos dos arreglos para guardar los minutos entrantes y salientes de los jugadores en cada partido. La idea es mantener la invariante de que al final del partido, los jugadores que jugaron algún momento del partido tendrán minutos entrantes y salientes en el rango [0, 90]. Los jugadores que no entraron en ningún momento al partido tendrán minutos entrantes con el valor de -1 y los jugadores que entraron desde el inicio pero fueron sustituidos tendrán un valor de minuto saliente < 90. Es decir, solamente los jugadores que terminaron el partido en el campo tienen valor de minuto saliente de 90.

Si mantenemos esta invariante al encontrar sustituciones durante el partido, al final del partido podremos calcular la cantidad de minutos jugados por cada jugador y acumularlo al total de minutos a lo largo de la temporada. Para los goles, simplemente los acumulamos al jugador que los marca.

Al momento de tener una pregunta de promedio durante un partido, calculamos los minutos jugados hasta ese entonces sumando los minutos a lo largo de la temporada con los minutos jugados en ese partido. Para la segunda cantidad, debemos separar en casos por si el jugador está en el partido, o si salió del partido en algún momento por sustitución. Con esta expresión, calculamos el promedio goleador por partido de cada jugador en la pregunta del promedio y los sumamos para tener un valor combinado.
