Podemos armar el grafo dirigido de conocimiento mientras se lee la entrada. La primera opción es usando una lista de adyacencia, la otra opción es usando una matriz de adyacencia. 
Luego se itera sobre cada persona y se cuenta cuántas personas lo conocen. Este proceso de iteración va a depender de qué estructura hayamos usado para guardar el grafo. Si usamos una lista de adyacencia, tendremos que iterar sobre todas las listas de adyacencia, lo cual tomará tiempo `O(N(N+M))` donde `M` es el número de aristas. Si se usa una matriz, este proceso toma `O(N^2)` ya que podemos contar los conocidos iterando sobre las columnas de cada matriz. Para grafos densos donde `M=O(N^2)`, se puede ver que guardar el grafo en una matriz es más eficiente.

Para la primera subtarea, en caso de encontrar a una persona conocida por más de la mitad, entonces regresamos ese valor y termina el problema. 

Para el caso general, creamos un std::pair de la forma `(c_i, i)` y se lo añade a un vector de tipo pair<int, int> de personas famosas. Al final de este
proceso, ordenamos el vector usando std::sort. El vector de pair se ordena primero con respecto a su primera componente y luego lexicográficamente con respecto a su segunda componente normalmente, por lo tanto esto
es suficiente para dar la salida que queremos. Iteramos sobre el vector e imprimimos la segunda componente. Este segundo paso toma `O(N log N)` ya que solamente consta en ordenar un vector con a lo mucho `N` elementos.

Por lo tanto, la eficiencia de nuestra solución dependerá de la estructura usada para guardar el grafo. Para la segunda subtarea, una lista de adyacencia es suficiente. Para la tercera subtarea, una matriz es necesaria.

Si no se desea armar el grafo completo, podemos darnos cuenta que lo único que necesitamos saber para una persona en particular, es la cantidad de personas que la conocen. Esta información puede ser guardada en un arreglo `C` de enteros donde `C[i]` representa la cantidad de personas que conocen a `i`. Dicha estructura puede ser llenada de forma eficiente mientras se lee la entrada. Para hallar las personas famosas, se puede seguir el mismo proceso con el vector de pares, o también se puede usar un std::priority_queue y obtener una eficiencia similar.

