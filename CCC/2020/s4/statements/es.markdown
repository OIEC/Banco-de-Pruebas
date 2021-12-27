#Descripción
Hay $N$ empresarios sentados en una mesa circular para una larga sesión de negociaciones. Cada empresario pertenece a un grupo A, B o C. Un grupo es *feliz* si todos sus miembros están sentados en un bloque contiguo de asientos consecutivos. Como buen solucionador de problemas, los empresarios te piden que hagas *felices* a todos los grupos usando **cambios de asiento**. En cada **cambio de asiento**, dos empresarios intercambian sus asientos entre ellos. Para iniciar la reunión lo más pronto posible, te piden calcular el menor número de **cambios de asiento** requeridos para hacer *felices* a todos los grupos.

#Entrada
Una línea que contiene $N$ caracteres, donde cada caracter es A, B o C. El caracter en posición $i$ denota el grupo de la persona que está ubicado en la posición $i$. Los asientos están numerados en sentido horario.

#Salida
El menor número de cambios de asiento que se deben realizar.

#Límites
$1 \leq N \leq 1000000$ 

#Subtarea 1 [25 puntos]
No hay empresarios del grupo C y $N \leq 5000$.

#Subtarea 2 [25 puntos]
No hay empresarios del grupo C.

#Subtarea 3 [25 puntos]
$N \leq 5000$.

#Subtarea 4 [25 puntos]
Sin restricciones


#Ejemplo
||input
BABCBCACCA
||output
2
||description
En una posible secuencia, el primer **cambio de asiento** resulta en la configuración AABCBCBCCA. Al realizar el segundo **cambio de asiento** se obtiene AABBBCCCCA, que cumple las condiciones del problema.
||end 

