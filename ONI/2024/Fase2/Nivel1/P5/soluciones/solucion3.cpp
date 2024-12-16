#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>

using namespace std;

int bfs(int inicio, int objetivo) {
    queue<pair<int, int>> cola;
    unordered_set<int> visitados;
    cola.push({inicio, 0});
    visitados.insert(inicio);

    while (!cola.empty()) {
        auto [actual, movimientos] = cola.front();
        cola.pop();

        if (actual == objetivo) return movimientos;

        vector<int> siguientes_posiciones = {actual + 1, actual - 1, actual * 2};
        for (int siguiente : siguientes_posiciones) {
            if (visitados.find(siguiente) == visitados.end() && abs(siguiente) <= 1000) {
                visitados.insert(siguiente);
                cola.push({siguiente, movimientos + 1});
            }
        }
    }
    return -1;
}

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> recorrido(n);
    for (int i = 0; i < n; i++) cin >> recorrido[i];

    int movimientos_totales = bfs(x, recorrido[0]);
    for (int i = 1; i < n; i++) {
        movimientos_totales += bfs(recorrido[i - 1], recorrido[i]);
    }
    cout << movimientos_totales << endl;
    return 0;
}
