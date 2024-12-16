Para $N=3$ se puede dividir en los casos en que el primer elemento está en el medio de los otros dos, y así con el segundo y tercer elemento.

Para la segunda subtarea se puede ordenar el arreglo usando std::sort y obtener el segundo máximo directamente. Esto toma $O(N \log N)$.

Para la tercera subtarea, primero iteramos el arreglo encontrando el elemento más grande. 
Luego lo iteramos por segunda vez encontrando el elemento máximo, pero saltándonos al elemento más grande. 
Es decir, en la comparación con el siguiente elemento, ignoramos al elemento más grande previamente calculado. 
El elemento del final será el segundo elemento más grande. Esto lleva $O(N)$ y pasa la tercera subtarea.
