# Solución

La idea de resolución es darse cuenta de que el mínimo común multiplo (M.C.M.) del conjunto `A` y todos sus múltiplos cumplen por definición el primer enunciado, y que el máximo común divisor (M.C.D.) del conjunto `B` y todos sus factores cumplen el segundo enunciado. 

Entonces, para hallar los posibles valores de `k` tenemos que hallar todos los números que sean a la vez múltiplos del M.C.M. de `A` y divisores del M.C.D. de `B`. La diferencia entre las dos subtareas es el algoritmo que usamos para obtener el M.C.D. entre dos conjuntos, ya que para obtener el M.C.M. usamos el M.C.D. El resto del código es igual. 

Para obtener el M.C.D. de un conjunto `A = {a_1, a_2, ..., a_n}`, primero obtenemos el M.C.D. entre `a_1` y `a_2`. Luego obtenemos el M.C.D. entre ese valor obtenido y `a_3`, y así sucesivamente hasta llegar a `a_n`. Lo mismo hacemos con el M.C.M. de un conjunto `A = {a_1, a_2, ..., a_n}`, solo que para obtener el M.C.M. entre `a_1` y `a_2` usamos la fórmula:

`a * b = M.C.D.(a,b) * M.C.M.(a,b)`

# Sub-caso 1
Para resolver el primer caso, podemos obtener el M.C.D. entre dos números de una manera muy ineficiente. Básicamente, para obtener el M.C.D. entre `a` y `b`, probamos cada valor entre `min(a,b)` y 1 y devolvemos la primera incidencia. 

# Sub-caso 2
Para resolver el segundo caso, usamos una manera mucho más eficiente que es el algoritmo de Euclides. Básicamente resuelve el problema de hallar el M.C.D. de forma recursiva usando la formula `M.C.D.(a,b)=M.C.D.(a%b,b)` donde `a%b` es el residuo de que se tiene al dividir `a` para `b`. Se lo hace hasta llegar a que uno de los dos valores es 1.
