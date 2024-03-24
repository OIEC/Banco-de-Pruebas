# Descripción
Hay un género en los libros de ficción llamado *escoge tu propio camino*. Estos libros permiten al lector escoger por los personales lo que altera el final de la historia.
<br/><br/>
Por ejemplo, en la primera página del libro se le puede preguntar al lector: "¿Se debe recoger esta piedra?" Si la respuesta es "Sí", se los envía a continuar leyendo desde la página 47, y si la respuesta es "No", se los envía a leer desde la página 18. En cada una de esas dos páginas pueden tener más decisiones. Hay páginas que no tienen ninguna decisión y por lo tanto esas páginas son páginas "finales". Pueden haber muchas páginas finales posibles, algunos son buenos (el héroe encuentra el tesoro) y otros no tanto (el heroe encuentra un sandwich del 2001).
<br/><br/>
Siendo el editor de uno de estos libros, debes examinar las siguientes dos condiciones:
<br/><br/>

 1. Asegurarte que cada página pueda ser llegada desde el inicio. De lo contrario, no vale la pena pagar para imprimir esa página.
 2. Hallar el camino más corto, de tal forma que los lectores sepan cuál es la menor cantidad de tiempo que necesitan para terminar una versión de la historia.
<br/><br/>

Dada la descripción del libro, examina estas dos condiciones.

# Entrada
La primera línea contiene un entero $N$ $(2 \leq N \leq 10000)$, el número de páginas del libro. Cada una de las siguientes $N$ líneas contiene un entero $M_i$
$(1 \leq i \leq N; 0 \leq M_i \leq N)$, que corresponde a la cantidad de opciones para la página $i$, siguiéndole $M_i$ enteros separados por un espacio en el rango del $1$ al $N$, correspondiendo a cada una de las páginas que se puede ir desde la página $i$. También se cumple que $M_1 + M_2 + \cdots + M_n$ es a lo mucho 10000.
<br/><br/>
Si $M_i = 0$, entonces la página $i$ es una página final. Existe al menos una página final en el libro. Siempre se empieza desde la página 1.

# Salida
La salida consta de dos líneas. La primera línea contiene el caracter 'Y' si todas las páginas son alcanzables desde la página 1. De otra forma contiene el caracter 'N'.
<br/><br/>
La segunda línea contiene un entero no-negativo $K$, que corresponde a la longitud del camino más corto que un lector puede tomar al leer el libro. Se garantiza que siempre existe un camino más corto.

# Ejemplo
||input
3
2 2 3
0
0
||output
Y
2
||description
Ya que empezamos en la página 1 y podemos llegar a ambas páginas 2 y 3, entonces todas son alcanzables. Los únicos caminos en el libro son 1 -> 2 y 1 -> 3, ambos con longitud 2.
||input
3
2 2 3
0
1 1
||output
Y
2
||description
Ya que empezamos en la página 1 y podemos llegar a ambas páginas 2 y 3, entonces todas son alcanzables. El camino más corto del libro es 1 -> 2 el cual tiene longitud 2.
||end

# Subtarea 1 [26 puntos]
$N \leq 100$, $M_i \leq 10$ para $(1 \leq i \leq N)$.

# Subtarea 2 [20 puntos]
Se garantiza que el libro no tiene ciclos.

# Subtarea 3 [26 puntos]
$N \leq 1000$, $M_i \leq 25$ para $(1 \leq i \leq N)$.

# Subtarea 4 [28 puntos]
Sin restricciones.
