Para la primera subtarea podemos dividir en dos casos, si el primer caracter empieza con I o no.

Si el primer caracter empieza con 'I', podemos notar que solamente los siguientes patrones contribuyen abreviaciones IA:

"I I A", "I A A", "I A X", "I X A".

Donde el caracter 'X' es cualquier caracter.

Si el segundo caracter no es 'I', la única forma que haya una abreviación es que los siguientes dos sean "IA".

Se puede generalizar la idea anterior iterando sobre la palabra encontrando cada ocurrencia de la letra 'I'. Iteramos desde cada caracter 'I' contando las ocurrencias de los caracteres 'A' desde ese punto. Cada una de estas forma una abreviación "IA" así que incrementamos un contador. Esta solución corre en tiempo $O(n^2)$ y es suficiente para resolver la segunda subtarea.
