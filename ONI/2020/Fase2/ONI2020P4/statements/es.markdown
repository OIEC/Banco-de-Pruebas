#Descripción
¿Recuerdas cómo empezaste tu aventura en esta Olimpiada Nacional? Tal vez no lo recuerdes, pero comenzaste calculando expresiones matemáticas con dos operandos. Luego determinaste si una expresión formada solamente por paréntesis era balanceada. Ambos problemas no resultaron tan complicados, así que ahora vamos a explorar más allá. No me digas que...¿vamos a combinar ambos problemas? ¡Efectivamente!
¿Cómo resolverías expresiones matemáticas con varios paréntesis y un número arbitrario de operandos?


#Entrada
Una única línea, formada de una expresión matemática con un número arbitrario de paréntesis, signos de suma, resta, multiplicación y división y un número arbitrario de operandos enteros. La expresión no contiene espacios.

#Salida
El valor numérico al resolver la expresión.

#Ejemplo
||input
1*3+2*4+8*2
||output
27

||input
3+((2-27)/5)
||output
-2
||end

#Límites
- La expresión de entrada no tendrá más de 200 caracteres.
- El resultado final y los resultados intermedios evaluados en la fórmula siempre serán menores a $2^{30}$.

#Subtarea 1 [20 puntos]
 - La expresión dada no contiene ningún paréntesis y consta solamente de signos de suma y multiplicación, con un número arbitrario de operandos.

#Subtarea 2 [80 puntos]
 - La expresión dada no tiene restricciones: puede contener un número arbitrario de paréntesis, signos de suma, resta, multiplicación y división y un número arbitrario de operandos.
 - La expresión dada cumple que siempre existen paréntesis alrededor de operandos compuestos (que contengan operaciones dentro de ellos). Por ejemplo: $(6/3)-2$ es una expresión válida para esta subtarea, ya que $(6/3)$ es un operando compuesto. Sin embargo, la expresión $1+2+6/2$ no es válida para esta subtarea, ya que el operando $6/2$ es un operando compuesto pero no contiene paréntesis.

#Notas
 - Los signos de suma, resta, multiplicación y división están representados por '$+$','$-$','$*$' y '$/$', respectivamente.
 - La expresión inicial siempre es válida.
 - El resultado final y resultados intermedios en el cálculo de la expresión siempre serán enteros.
 - Si decides utilizar Python, no tienes permitido usar funciones como "eval", pues es precisamente lo que el problema pide implementar.
 - Nótese que los casos de la Subtarea 1 no son válidos según la definición de la Subtarea 2. Por ejemplo: $1*3+2*4+8*2$ no es válido pues $1*3$, $2*4$ y $8*2$ son compuestos y deberían llevar paréntesis para ser válidos según la Subtarea 2. Para que tu solución obtenga 100 puntos, debes considerar tanto los casos de la Subtarea 1 como los de la Subtarea 2 en tu programa.

