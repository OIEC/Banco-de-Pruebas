#include<vector>
#include<queue>
#include<iostream>
using namespace std;

// Representación de un grafo usando listas de adyacencia.
vector<int> adj[100];

void BFS(int N, int x)
{
    queue<int> q;
    bool visitado[N];
    int distancia[N];

    // Inicializamos visitados como falso y distancia como un valor grande.
    // Si inicializamos con 0, puede traer problemas cuando el grafo no es conexo.
    for (int i = 0; i < N; ++i)
    {
        visitado[i] = false;
        distancia[i] = N+1;
    }

    cout << "Recorrido en amplitud empieza en nodo " << x << endl;
    visitado[x] = true;
    distancia[x] = 0;
    q.push(x);
    while (!q.empty()) 
    {
        int s = q.front(); 
        q.pop();

        // Visitamos el nodo s y añadimos sus vecinos a la cola. 
        vector<int> vecinos = adj[s];
        for (int i = 0; i < vecinos.size(); ++i)
        {
            int u = vecinos[i];
            if (visitado[u]) continue;
            visitado[u] = true;
            distancia[u] = distancia[s]+1;
            cout << "Nodo " << u <<  " visitado viniendo desde nodo " << s << " a distancia " << distancia[u] << " desde el inicio" <<  endl;
            q.push(u);
        }
    }
    cout << endl;
}

int main()
{
    int N; 
    int E;
    cin >> N;
    cin >> E;
    for (int i = 0; i < E; ++i)
    {
        int u;
        int v;
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int primero;
        cin >> primero;
        BFS(N, primero);
    }
}