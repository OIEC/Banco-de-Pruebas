Primeramente tenemos varias opciones de como leer la entrada. Podemos leerlo en un arreglo bidimensional de $3 \times 3$, en 3 arreglos de filas, o en 9 variables separadas. 

Para la primera subtarea, debemos identificar las variables que corresponden a cada diagonal. Luego verificamos con un condicional para detectar que esas casillas tengan el mismo valor. En total tenemos 4 casos, 2 diagonales y 2 ganadores posibles.

Para la segunda subtarea, tenemos que identificar las variables que correspondan a cada fila y cada columna. Hay 3 filas y 3 columnas por lo que hay 6 condicionales. Ya que hay dos posibles ganadores, tenemos un total de 12 casos a verificar.

Podemos combinar ambas soluciones (16 casos) para obtener una solución parcial de 50 puntos. Esta solución detecta correctamente el ganador si es que hay uno.

Para resolver la última subtarea, podemos crear una variable adicional que detecte si existe un ganador. Empieza como falsa y si alguno de los 16 condicionales previos se ejecuta, la cambiamos a verdadera. Al final de los 16 condicionales podemos verificar la variable, y en caso de ser falsa no habrán ganadores e imprimimos "N".