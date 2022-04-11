# Descripción
En tu pueblo se denomina a una persona como "famosa" si esa persona es conocida por más de la mitad del pueblo. Como nuevo escritor de la revista del pueblo, tu tarea consiste en primero identificar a todas las personas famosas, para luego hacerles una entrevista.

# Entrada
En la primera línea el valor de $N$ representando al número de habitantes del pueblo. Por conveniencia, las personas del pueblo están numeradas del $1$ al $N$.

Luego seguirán $N$ líneas conformadas por varios números de la siguiente manera:
El primer número $i$ de cada línea corresponde al número que identifica a esa persona.
El segúndo número $0 \leq c_i < N$ corresponde a la cantidad de personas que la persona $i$ conoce.
Luego siguen $c_i$ números separados por un espacio, representando a las personas que $i$ conoce.

Si una persona $i$ conoce a una persona $j$, no necesariamente implica que la persona $j$ conoce a $i$.

# Salida
Todas las personas famosas del pueblo, una en cada línea, ordenadas descendentemente por la cantidad de personas que las conocen. En caso de empates, la persona cuyo número de identificación sea mayor aparece antes.
En caso de no existir ninguna persona famosa, imprimir $-1$.

# Ejemplo
||input
5
1 3 3 4 5
2 3 3 4 5
3 2 4 5
4 2 3 5
5 0
||output
5
4
3
||description
Las personas famosas son $(3, 4, 5)$ ya que son conocidas por más de 2 personas.
La persona $5$ es conocida por 4 personas: $(1, 2, 3, 4)$ por lo que aparece primero en la salida.
Las personas $3$ y $4$ ambas son conocidas por 3 personas cada una, pero ya que $4$ es mayor a $3$, entonces esa persona aparece primero en la salida.
||end

#Límites
$1 \leq N \leq 1000.$

#Subtarea 1 [30 puntos]
- $N \leq 100.$
- Se asegura que existe exactamente una persona famosa.

#Subtarea 2 [40 puntos]
- $N \leq 100.$
- Sin restricciones con respecto a la cantidad de personas famosas.

#Subtarea 3 [30 puntos]
- Sin restricciones.

# Notas
 1. Una persona no se puede conocer a sí mísmo.
 2. Si $n$ es impar de la forma $2k+1$, entonces se considera famosa si más de $k$ personas la conocen.

