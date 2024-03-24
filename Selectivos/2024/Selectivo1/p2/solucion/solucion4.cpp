#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Nodo
{
public:
    std::vector<int> vecinos; // los vecinos representarán las páginas alcanzables a partir de este node.

    void nuevoVecino(int vecino)
    {
        vecinos.push_back(vecino);
    }
};

int main()
{
    int N;
    std::cin >> N;
    if (!N)
    { // check N == 0
        std::cout << 'Y' << std::endl;
        std::cout << 0;
        return 0;
    }
    Nodo nodos[N]; // para cada página, crearemos un Nodo que contendrá como vecinos los números de las páginas que pueden ser alcanzadas desde esta.
    // aquí se cumple: roots[index] contiene la root de la página (index+1). Por ejemplo root[0] contiene la información de la página 1.
    for (int k = 0; k < N; k++)
    {            // aquí se cumple: i = k + 1.
        int M_k; // para cada una de las páginas, lee cuántas páginas pueden ser alcanzadas desde esta.
        std::cin >> M_k;
        for (int j = 0; j < M_k; j++)
        {
            int vecino; // lee qué página es alcanzable a partir de la página i.
            std::cin >> vecino;
            nodos[k].nuevoVecino(vecino); // anota que podemos alcanzar a la página "vecino" directamente desde la página i.
        }
    }

    int menor_longitud; // usamos BFS para encontrar la longitud más corta.  Al mismo tiempo usaremos la búsqueda para anotar qué paginas son alcanzables.
    bool encontrado = false; // boolean para marcar si ya hemos encontrado el camino más corto.
    // Búsqueda
    std::queue<std::pair<int, int>> q; // cada uno de los elementos en la cola incluyen su número y la longitud del camino para llegar a ello
    q.push({1, 1});                    // Como indicado en el problema, empezamos desde la página 1. El camino tiene longitud al menos 1 segun la orden del problema.
    bool alcanzable[N];                   // anota que nodos ya han sido visitados. visited[k] = true implica que durante la busqueda hemos visitado la página (k+1), false es análogo.
    std::fill(alcanzable, alcanzable + N, false);
    while (!q.empty())
    {
        int pagina = q.front().first;
        int longitud = q.front().second;
        Nodo nodo = nodos[pagina - 1];
        q.pop();
        alcanzable[pagina - 1] = true;
        if (!encontrado && nodo.vecinos.size() == 0)
        { // si aún no hemos encontrado el camino mas corto, revisa si esta pagina es una página final (es decir, si no tiene vecinos).
            encontrado = true;
            menor_longitud = longitud;
        } // ya que el objetivo de la búsqueda también es anotar que páginas son alcanzables, no la rompemos después de encontrar el camino más corto.
        for (int vecino : nodo.vecinos)
        { // añade los vecinos no visitados a la cola
            if (!alcanzable[vecino - 1])
            {
                q.push({vecino, longitud + 1});
            }
        }
    }

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
    return 0;
}
