# Descripción
Ron está haciendo un chili usando una combinación de pimentones.

El picante de un pimentón se mide en las Unidades de Picante de Scolvile (SHU). El chili de Ron inicialmente no es picante, pero cada vez que le añade un pimentón, el nivel total de picante aumenta por el valor SHU del pimentón. Los valores SHU de cada pimentón se muestran a continuación:

 - Poblano: 1500
 - Mirasol: 6000
 - Serrano: 15500
 - Cayenne: 40000
 - Thai: 75000
 - Habanero: 125000

Tu tarea es determinar el nivel total de picante del chili de Ron luego que termine de añadir sus pimentones.

# Entrada
La primera línea de la entrada contiene un entero positivo $N$, que representa el número de pimentones que Ron añadirá a su chili.
Las siguientes $N$ líneas contienen el nombre del pimentón que Ron ha añadido. Note que un mismo tipo de pimentón puede añadirse varias veces al chili.

# Salida
Un único entero positivo que representa el nivel picante de chili.

# Ejemplo
||input
4
Poblano
Cayenne
Thai
Poblano
||output
118000
||description
Un pimentón Poblano tiene un valor de SHU de 1500. Un Cayenne tiene un valor SHU de 40000.
Un Thai tiene un valor SHU de 75000. El nivel total de picante del chili es $1500 + 40000 + 75000 + 1500 = 118000.$
||end
