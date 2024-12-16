Para este problema utilizamos programación dinámica usando una matriz $S$. En esta matriz, la posición $S[i, j]$ representa la mayor cantidad de goles en partidos clásicos que se podrían haber hecho si consideramos solamente los $i$ primeros partidos de los cóndores y los $j$ primeros partidos de las iguanas. Para llenar la matriz usamos las siguientes observaciones:

Si para alguno de los equipos no consideramos ninguno de sus partidos entonces no podrían haber habido partidos clásicos, entonces el valor en esa posición debería ser 0. Por tanto $S[0][n]$ y $S[n][0]$ siempre van a ser 0 para todo $n$, no necesitamos actualizar estos.

Para calcular $S[i][j]$ tenemos 3 opciones. De estas 3, escogemos el mayor valor:
  - Considerar los $i$ primeros partidos de los cóndores y los $j$ primeros partidos de las iguanas. En este caso, podemos ver la posibilidad de que $i, j$ sea un pártido clásico.
  - Solamente considerar los $i-1$ primeros partidos de los cóndores y los $j$ primeros partidos de las iguanas. (Ignoramos el $i$-ésimo partido de los cóndores).
  - Solamente considerar los $i$ primeros partidos de los cóndores y los $j-1$ primeros partidos de las iguanas. (Ignoramos el $j$-ésimo partido de las iguanas).

Por definición $S[n][n]$ es la respuesta al problema.
