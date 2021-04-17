#Descripcion
Estás trabajando en una agencia de espionaje, y tu trabajo es descifrar los mensajes interceptados a las agencias rivales. Tu estrategia consiste en buscar las palabras más repetidas en los mensajes interceptados, e intentar descifrarlas por su cuenta ya que asumes que son términos reconocibles. Para esta tarea, tu primer objetivo es diseñar un programa que revise el mensaje interceptado y devuelva la palabra que aparezca más veces.

#Entrada
 - En la primera línea, recibes un entero $n$, que representa la cantidad de palabras que contiene el mensaje (incluyendo repeticiones).
 - A partir de la segunda línea, cada línea contiene una palabra del mensaje interceptado.

#Salida
 - La palabra que más veces se repite en la entrada. Puedes asumir que esta palabra es única.



#Ejemplo
||input
4
aaa
bab
aab
bab
||output
bab
||description
En este mensaje, la palabra $bab$ es la palabra que se repite en más ocasiones (2).
||end


#Subtarea 1 [60 puntos]
$n < 100$


#Subtarea 2 [40 puntos]
$n < 100000$
