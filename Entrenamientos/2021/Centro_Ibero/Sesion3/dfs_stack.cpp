#include<vector>
#include<stack>
#include<iostream>
using namespace std;

// Representación de un grafo usando listas de adyacencia.
vector<int> adj[100];

void DFS(int N, int x)
{
    stack<int> pila;
    bool visitado[N];

    // Inicializamos visitados como falso.
    for (int i = 0; i < N; ++i)
    {
        visitado[i] = false;
    }

    visitado[x] = true;
    cout << "Recorrido en profundidad empieza en nodo " << x << endl;
    pila.push(x);
    while (!pila.empty()) 
    {
        int s = pila.top();
        pila.pop();
        if (!visitado[s])
        {
            visitado[s] = true;
            cout << "Nodo " << s <<  " visitado" << endl;
        }

        // Añadimos sus vecinos a la pila. 
        vector<int> vecinos = adj[s];
        for (int i = 0; i < vecinos.size(); ++i)
        {
            int u = vecinos[i];
            if (!visitado[u]) pila.push(u);
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
        DFS(N, primero);
    }
}