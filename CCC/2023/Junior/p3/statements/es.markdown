# Descripción

Estás tratando de agendar un evento en alguno de cinco posibles días. Tu trabajo es determinar en qué día agendar el evento, de tal forma que la mayor cantidad de gente interesada pueda ir al evento.

# Entrada
La primera línea de la entrada contiene un entero positivo $N$, representando el número de personas interesadas en ir al evento. Las siguientes $N$ líneas contienen la disponibilidad de cada persona usando un caracter para cada uno de los días (Día 1, Día 2, Día 3, Día 4 o Día 5). El caracter 'Y' significa que esa persona puede ir al evento ese día y el caracter '.' significa que esa persona no puede ir al evento ese día.

# Salida
Una única línea que consiste del día / los días en los cuales la mayor cantidad de personas interesadas pueden asistir. Si hay más de un día en el cual la mayor cantidad de personas pueden asistir, imprime todos esos días ordenados de manera ascendente separados por comas (sin espacios).

# Ejemplo
||input
3
YY.Y.
...Y.
.YYY.
||output
4
||description
Todas las 3 personas pueden asistir en el día 4, y este es el único día en que todos pueden asistir.
||input
5
YY..Y
.YY.Y
.Y.Y.
.YY.Y
Y...Y
||output
2,5
||description
No hay ningún día en el que pueden ir todas las personas. Cuatro personas pueden ir en los días 2 y 5.
||end

# Subtarea 1 [40 puntos]
Hay exactamente un día en el cual cada una de las personas puede asistir.

# Subtarea 2 [40 puntos]
Hay exactamente un día en el cual la mayor cantidad de personas puede asistir.

# Subtarea 3 [20 puntos]
Hay más de un día en el cual la mayor cantidad de personas puede asistir.
