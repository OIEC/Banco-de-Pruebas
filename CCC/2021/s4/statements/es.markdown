#Descripción
Toronto tiene $N$ estaciones de metro, numeradas del 1 al $N$. Empiezas en la estación 1, y cada día, necesitar llegar a la estación $N$ para llegar a tu escuela.

Hay $W$ pasillos (para caminar) de una vía entre las estaciones, el pasillo $i$ te permite caminar desde la estación $A_i$ a una estación distinta $B_i$ $(1 \leq A_i , B_i \leq N, A_i \neq B_i)$ en un minuto. Pueden haber múltiples pasillos conectando cualquier par de estaciones.

La línea del metro sigue una ruta compuesta por $N$ estaciones, empezando por la estación 1 y visitando cada estación una sola vez. Inicialmente, esta ruta consiste de estaciones $S_1, S_2, ..., S_N$, en ese orden. $S_1 = 1$, y $S_2, ..., S_N$ es una permutación de los enteros $2, … , N$. Solamente un metro corre por esta ruta cada día, saliendo de la estación 1 a las 6am y toma 1 minuto para llegar a la siguiente estación. Esto significa que, $m$ minutos luego de las 6am, el metro estará en la estación $S_{m+1}$ (o en la estación $S_N$ si $m \geq N − 1$).

En un período de $D$ días, sin embargo, la línea del metro va a cambiar continuamente. Al incio del día $i$, la estación $X_i$ y la estación $Y_i$ ($2 \leq X_i$ , $Y_i \leq N$, $X_i \neq Y_i$) en la ruta van a cambiarse. Nota que luego del cambio la ruta aún continúa empezando en la estación 1 y visita a cada una de las $N$ estaciones exactamente una vez. Los cambios se aplican a los siguientes días – la ruta no se resetea automáticamente a $S_1, S_2, ..., S_N$.

Cada uno de estos $D$ días, te gustaría determinar qué tan rápido puedes llegar a la escuela para empezar a aprender cosas. En el día $i$, empezando a las 6am (luego del cambio $i$ a la ruta del metro), empiezas tu viaje diario a la estación $N$. Cada minuto, puedes subirte a la línea de metro a la siguiente parada (si estas en la misma estación que el metro y aún no ha completado su ruta), o tomar un pasillo desde tu estación a otra estación, o esperar en la estación donde te encuentras. Nota que tu viaje empieza al mismo tiempo que la ruta del metro, lo que significa que puedes elegir si subirte inmediatamente si deseas, y que puedes escoger bajarte del metro y subirte nuevamente durante tu viaje.


#Entrada
La primera línea contiene tres enteros separados por un espacio $N$, $W$ y $D$.

Las siguientes $W$ líneas contienen cada una dos enteros separados por un espacio $A_i$ and $B_i$ ($1 \leq i \leq W$).
La siguiente línea contiene $N$ enteros separados por un espacio $S_1, . . . , S_N$ , que forman la permutación inicial de las estaciones.
Las siguientes $D$ líneas contienen dos enteros separados por un espacio $X_i$ y $Y_i$ ($1 \leq i \leq D$).


#Salida
La salida consta de $D$ líneas, con un entero por línea. La línea $i$ es el menor número de minutos necesarios para llegar a la estación $N$ en el día $i$ $(1 \leq i \leq D)$.

# Ejemplo
||input
4 3 3
1 2
3 4
4 1
1 4 3 2
3 4
4 2
3 2
||output
1
2
3
||description
Al inicio del primer día, la ruta del metro va a ser cambiada para visitar las estaciones $[1, 4, 2, 3]$, en ese orden. En ese día, simplemente deberías tomar el metro a la estación 4, tomándote 1 minuto.

En el segundo día, la ruta se convierte en $[1, 3, 2, 4]$, y debes tomar el metro a la estación 3 (tomando 1 minuto) y luego caminar a la estación 4 (tomando 1 minuto más).

El tercer día, la ruta se convierte en $[1, 2, 3, 4]$. Una opción óptima consiste en caminar a la estación 2 (tomando 1 minuto), luego subiéndote al metro ahí y tomándolo a la estación 3 y finalmente a la estación 4 (tomando 2 minutos más).
||end


#Límites
 - $3 \leq N \leq 200000$ 
 - $0 \leq W \leq 200000$
 - $1 \leq D \leq 200000$

#Subtarea 1 [13 puntos]
$N \leq 10$, $W \leq 10$, $D \leq 10$

#Subtarea 2 [13 puntos]
$N \leq 200$, $W \leq 200$, $D \leq 200$

#Subtarea 3 [20 puntos]
$N \leq 2000$, $W \leq 2000$, $D \leq 2000$

#Subtarea 4 [54 puntos]
Sin restricciones.

