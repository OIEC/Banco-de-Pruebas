# Descripción
Tu profesor de matemáticas escribe 15 enteros positivos en la pizarra. Te pide que cuentes los múltiplos de un valor dado $N$. Sin embargo, hay dos números $P$ y $Q$ que son tus números de mala suerte, por lo que decides excluir del conteo a un número si es múltiplo de $P$ o de $Q$ por si las dudas.

# Entrada
La primera línea contiene los valores de $N$, $P$ y $Q$ separados por un espacio.
Las siguientes 15 líneas contienen los 15 enteros positivos de la pizarra.

# Salida
Un único entero no negativo que representa la cantidad de valores que son múltiplos de $N$, pero no de $P$ ni de $Q$

# Ejemplo
||input
2 3 5
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
||output
5
||description
Notemos que hay 8 múltiplos de 2. Sin embargo, los valores de 6, 10, 12 no cuentan ya que son múltiplos de 3 o de 5.
Ya que se excluyen 3 números, el conteo es 8-3=5.
||end

#Límites
$ 1 < N, P, Q < 99 $

Los 15 valores de la pizarra son todos menores a 10000.

#Notas
Se garantiza que $N$, $P$ y $Q$ son distintos.





