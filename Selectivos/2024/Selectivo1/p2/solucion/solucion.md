# Ideas usadas.
- Grafos
- Queues / Colas
- Breadth Fist Search (BFS) / Búsqueda en anchura

# Solución al problema "Elige tu propio camino" - Explicación

## Estructuras de datos

La clase `Nodo` se utiliza para representar cada página del libro. Cada nodo contiene un vector de números enteros llamados vecinos, que representan las páginas a las que se puede acceder directamente desde esa página.

```cpp
class Nodo
{
public:
    std::vector<int> vecinos; // los vecinos representarán las páginas alcanzables a partir de este node.

    void nuevoVecino(int child)
    {
        vecinos.push_back(child);
    }
};
```

### Input

Leemos el input del problema y usamos esta información para crear un grafo.

### Construcción del Grafo.

Se crea un array de Node `nodos`, donde cada nodo representa una página del libro. Para cada página, se lee el número de páginas alcanzables (`M_k`) y se agregan a la lista de vecinos del nodo correspondiente.

```cpp
int main()
{
    int N; // lee N
    std::cin >> N;
    if (!N)
    { // check N == 0
        std::cout << 'Y' << std::endl;
        std::cout << 0;
        return 0;
    }
    Nodo nodos[N]; // para cada página, crearemos un Nodo que contendrá como vecinos los números de las páginas que pueden ser alcanzados desde esta.
    // aquí se cumple: roots[index] contiene la root de la página (index+1). Por ejemplo root[0] contiene la información de la página 1.
    for (int k = 0; k < N; k++)
    {            // aquí se cumple: i = k + 1.
        int M_k; // para cada una de las páginas, lee cuántas páginas pueden ser alcanzadas desde esta.
        std::cin >> M_k;
        for (int j = 0; j < M_k; j++)
        {
            int child; // lee qué página es alcanzable a partir de la página i.
            std::cin >> child;
            nodos[k].nuevoVecino(child); // anota que podemos alcanzar a la página child directamenter desde la página i.
        }
    }
    ...
```


## Búsqueda del camino más corto y nodos ancanzables

Inicializamos las variables para BFS

```cpp
    int menor_longitud; // usamos BFS para encontrar la longitud más corta.  Al mismo tiempo usaremos la búsqueda para anotar cuales páginas son alcanzables.
    bool encontrado = false; // boolean para marcar si ya hemos encontrado el camino más corto.
    // Búsqueda
    std::queue<std::pair<int, int>> q; // cada uno de los elementos en el queue incluyen su número y la longitud del camino para llegar a ello
    q.push({1, 1});                    // Como indicado en el problema, empezamos desde la página 1. El camino tiene longitud al menos 1 según la orden del problema.
    bool alcanzable[N];                   // anota que nodos ya han sido visitados. visited[k] = true implica que durante la búsqueda hemos visitado la página (k+1), false es análogo.
    std::fill(alcanzable, alcanzable + N, false);
```

## Búsqueda del camino más corto y nodos ancanzables

Dada la naturaleza del problema (buscar el camino más corto en un grafo empezando desde un nodo específico) podemos usar el algoritmo de Breadth First Search (BFS). Esto implica explorar las páginas en un orden sistemático, comenzando desde la página 1 y traversando todas las páginas accesibles.
- Utiliza una cola (q) para realizar un recorrido BFS desde la página 1 hasta las páginas finales.
- Mientras se realiza la búsqueda, se marca cada página visitada en un arreglo alcanzable.
- Tan pronto como encontramos una página final guardamos la longitud del camino en la variable menor_longitud. Asimismo cambiamos el valor de "encontrado" a true para así evitar cambiar este valor en el futuro. Por la naturalza de BFS es seguro que el camino más corto es el primer camino hacia una página finaal que encontramos.

```cpp
    while (!q.empty())
    {
        int pagina = q.front().first;
        int longitud = q.front().second;
        Nodo nodo = nodos[pagina - 1];
        q.pop();
        alcanzable[pagina - 1] = true;
        if (!encontrado && nodo.vecinos.size() == 0)
        { // si aún no hemos encontrado el camino más corto, revisa si esta página es una página final (es decir, si no tiene children).
            encontrado = true;
            menor_longitud = longitud;
        } // ya que el objetivo de la búsqueda también es anotar cuales páginas son alcanzables, no la rompemos después de encontrar el camino más corto.
        for (int child : nodo.vecinos)
        { // añade los children no visitados a la queue
            q.push({child, longitud + 1});
        }
    }
```
Ahora, con este algoritmo podemos procesar Árboles, es decir Grafos sin ciclos. Esto ocurre ya que tan pronto empezamos a analizar nodos en un ciclo estos añadirán a otros nodos del mismo ciclo a la cola y esto de manera indefinida.
Esta versión de BFS no es suficiente para analizar Grafos con ciclos. Este código es suficiente para pasar la subtarea 2, pues esta asegura que el libro no tiene ciclos.

Para poder procesar grafos con ciclos, debemos añadir una condición adicional antes de añadir nodos a la cola. Debemos de asegurarnos de no añadir nodos ya previamente visitados.

```cpp
    while (!q.empty())
    {
        int pagina = q.front().first;
        int longitud = q.front().second;
        Nodo nodo = nodos[pagina - 1];
        q.pop();
        alcanzable[pagina - 1] = true;
        if (!encontrado && nodo.vecinos.size() == 0)
        { // si aún no hemos encontrado el camino más corto, revisa si esta página es una página final (es decir, si no tiene children).
            encontrado = true;
            menor_longitud = longitud;
        } // ya que el objetivo de la búsqueda también es anotar cuales páginas son alcanzables, no la rompemos después de encontrar el camino más corto.
        for (int child : nodo.vecinos)
        { // añade los children no visitados a la queue
            if (!alcanzable[child - 1])
            {
                q.push({child, longitud + 1});
            }
        }
    }
```
Con este código ya estamos en capacidad de analizar Grafos con ciclos y por tanto este algoritmo pasa la subtarea 4.

Dado que este algoritmo puede procesar cualquier tipo de grafo, la única preocupación que queda por analizar es cuanto tiempo necesita.
Dado que la complejidad del algoritmo es $O(N + E)$ (donde E es la cantidad total de aristas en el grafo). Dado que la subtarea 1 y 3 no tienen grafos densos este algoritmo puede procesarlos en un tiempo razonable. Así mismo, es suficiente para pasar la subtarea 4.

## Output
Solo queda dar los resultados.

```cpp
char todas_alcanzables = 'Y'; // ahora verificamos si todas las páginas son alcanzables. De momento asumimos que sí hasta demostrar lo contrario.
    for (int k = 0; k < N; k++)
    {
        if (!alcanzable[k])
        {
            todas_alcanzables = 'N'; // encontramos un contraejemplo
            break;                   // un contraejemplo basta
        }
    }

    // responde
    std::cout << todas_alcanzables << std::endl;
    std::cout << menor_longitud;
```
