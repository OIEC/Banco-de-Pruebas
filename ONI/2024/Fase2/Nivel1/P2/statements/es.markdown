# Descripción

La maestra Laura se aburrió un poco de enseñar la materia de lenguaje. Ahora está enfocada al 100% en la geometría euclidiana y está fascinada con los triángulos y sus ángulos. La maestra Laura te explica el siguiente concepto:

- Un ángulo es **agudo** si mide menos de 90 grados. 
- Un ángulo es **recto** si mide exactamante 90 grados.
- Un ángulo es **obtuso** si mide más de 90 grados.

El día de hoy llegó entusiasmada con la clasificación de los triángulos en base a sus ángulos:

- Un triángulo es **acutángulo** si sus 3 ángulos son agudos. 
- Un triángulo es **rectángulo** si tiene un ángulo recto.
- Un triángulo es **obtusángulo** si tiene un ángulo obtuso.

La tarea de la maestra Laura consiste en una lista inmensa de triángulos, donde debes reconocer qué tipo de triángulo es cada uno. Como buen programador, decides automatizar este proceso escribiendo un pequeño programa que te haga la tarea. 

# Entrada
En la primera línea, un entero positivo $n$ que representa el número de triángulos.
Las siguientes $n$ líneas constan de tres enteros, entre 1 y 179, separados por espacio. Estos tres valores representan el valor en grados de cada ángulo del triángulo en cuestión.

# Salida
$n$ líneas con una palabra en cada línea: "ACUTANGULO", "RECTANGULO" u "OBTUSANGULO" dependiendo del tipo de triángulo.

# Ejemplo
||input
3
5 5 170
75 75 30
30 90 60
||output
OBTUSANGULO
ACUTANGULO
RECTANGULO
||end

# Límites
$n \leq 100$.

# Subtarea 1 [25 puntos]
$n = 1$.

# Subtarea 2 [75 puntos]
Sin restricciones.

