#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m, origen, destino;
    cin >> n >> m >> origen >> destino;

    vector<int> cabeza(n, -1);
    vector<int> destinoArista(2 * m);
    vector<int> siguienteArista(2 * m);

    int cantidadAristas = 0;

    auto agregarArista = [&](int u, int v) {
        destinoArista[cantidadAristas] = v;
        siguienteArista[cantidadAristas] = cabeza[u];
        cabeza[u] = cantidadAristas;
        cantidadAristas++;
    };

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        agregarArista(u, v);
        agregarArista(v, u);
    }

    vector<int> distancia(n, -1);
    vector<int> cola(n);

    int inicioCola = 0;
    int finalCola = 0;

    distancia[origen] = 0;
    cola[finalCola++] = origen;

    while (inicioCola < finalCola) {
        int u = cola[inicioCola++];

        if (u == destino) {
            break;
        }

        for (int arista = cabeza[u];
             arista != -1;
             arista = siguienteArista[arista]) {

            int v = destinoArista[arista];

            if (distancia[v] == -1) {
                distancia[v] = distancia[u] + 1;
                cola[finalCola++] = v;
            }
        }
    }

    cout << distancia[destino] << '\n';

    return 0;
}
