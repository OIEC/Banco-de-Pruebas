#include<vector>
#include<iostream>
using namespace std;

// Representación de un grafo usando listas de adyacencia.
vector<int> adj[100];
bool visitado[100];

void DFS(int x)
{
    if (visitado[x]) return;

    visitado[x] = true;
    cout << "Nodo " << x <<  " visitado" << endl;

    // Visitamos sus vecinos recursivamente.
    vector<int> vecinos = adj[x];
    for (int i = 0; i < vecinos.size(); ++i)
    {
        int u = vecinos[i];
        DFS(u);
    }
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
        // Inicializamos visitado con false cada recorrido.
        for (int i = 0; i < N; ++i)
        {
            visitado[i] = false;
        
        }

        int primero;
        cin >> primero;
        DFS(primero);
        cout << endl;
    }
}