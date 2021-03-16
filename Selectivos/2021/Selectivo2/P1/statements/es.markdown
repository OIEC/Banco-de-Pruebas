#Descripcion 
Tienes la suerte de vivir en una casa con un patio gigante. Es tan grande que usualmente te lo imaginas como un plano cartesiano infinito. Como es normal, hay partes del patio que te gustan más que otras, y de hecho tienes un círculo favorito, de centro $O$ y radio $R$, donde te gusta jugar. Una noche cayó una lluvia muy fuerte y particular, de tal manera que las gotas cayeron exactamente una sola vez y en todos los lugares cuyas coordenadas en el plano cartesiano son enteras. Intrigado por semejante aguacero, ahora te preguntas cuántas gotas cayeron estrictamente en el interior de tu círculo favorito.

#Entrada
 - En la primera línea, las coordenadas $X$, $Y$ del punto $O$, separadas por un espacio.
 - En la segunda línea, el valor de $R$.
 - Cabe destacar que $X$, $Y$ y $R$ no son necesariamente números enteros.

#Salida 
La cantidad de gotas que cayeron estrictamente en el interior de tu círculo favorito.

_Nota:_ Te recomendamos usar el teorema de Pitágoras para obtener la distancia entre un punto $P$, de coordenadas $x_p$, $y_p$, y el centro del círculo en $O$, de coordenadas $x$, $y$. De esta manera, la distancia entre $O$ y $P$ es $\sqrt{(x-x_p)^2+(y-y_p)^2}$.

#Ejemplo 
||input
3 4
5
||output
69
||description
Las 69 gotas corresponden a todos los puntos de coordenadas enteras dentro del círculo con centro en (3,4) y radio 5.
||end


#Limites 
 - Ambas coordenadas del punto $O$ tienen un valor absoluto menor a 1000.
 - El valor de $R$ también es menor a 1000.
