Para cada hormiga, creamos variables representando las coordenadas en el plano cartesiano $(x_1, y_1)$ y 
$(x_2, y_2)$. Luego, procedemos a leer los movimientos desde la entrada e incrementamos en 1 las coordenadas $x_i$ y $y_i$ de cada hormiga dependiendo del movimiento en cuestión. Una vez procesados todos los movimientos, calculamos e imprimimos la distancia entre ambas hormigas usando la fórmula $$d = \sqrt{(x_1-x_2)^2 + (y_1-y_2)}$$

En C++, se puede usar la función `sqrt` de la biblioteca  `cmath`.

