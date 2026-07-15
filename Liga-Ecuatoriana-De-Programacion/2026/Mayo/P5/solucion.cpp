#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <limits>

using namespace std;

using ll = long long;

struct Incidencia {
    int habitacion;
    int temperatura;
    int arista;
};

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<Incidencia> incidencias;
    incidencias.reserve(2 * m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        incidencias.push_back({a, c, i});
        incidencias.push_back({b, c, i});
    }

    sort(
        incidencias.begin(),
        incidencias.end(),
        [](const Incidencia& a, const Incidencia& b) {
            if (a.habitacion != b.habitacion) {
                return a.habitacion < b.habitacion;
            }

            if (a.temperatura != b.temperatura) {
                return a.temperatura < b.temperatura;
            }

            return a.arista < b.arista;
        }
    );

    int estados = static_cast<int>(incidencias.size());

    vector<int> primerExtremo(m, -1);
    vector<int> opuesto(estados);

    for (int i = 0; i < estados; i++) {
        int arista = incidencias[i].arista;

        if (primerExtremo[arista] == -1) {
            primerExtremo[arista] = i;
        } else {
            int j = primerExtremo[arista];
            opuesto[i] = j;
            opuesto[j] = i;
        }
    }

    vector<int>().swap(primerExtremo);

    const ll INF = numeric_limits<ll>::max() / 4;

    vector<ll> distancia(estados, INF);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > cola;

    for (int i = 0; i < estados; i++) {
        if (incidencias[i].habitacion == 1) {
            distancia[i] = incidencias[i].temperatura;
            cola.push({distancia[i], i});
        }
    }

    auto relajar = [&](int desde, int hasta, ll costo) {
        ll nuevaDistancia = distancia[desde] + costo;

        if (nuevaDistancia < distancia[hasta]) {
            distancia[hasta] = nuevaDistancia;
            cola.push({nuevaDistancia, hasta});
        }
    };

    while (!cola.empty()) {
        auto [distanciaActual, estado] = cola.top();
        cola.pop();

        if (distanciaActual != distancia[estado]) {
            continue;
        }

        if (incidencias[estado].habitacion == n) {
            cout << distanciaActual << '\n';
            return 0;
        }

        relajar(estado, opuesto[estado], 0);

        if (
            estado > 0 &&
            incidencias[estado - 1].habitacion ==
                incidencias[estado].habitacion
        ) {
            ll costo = static_cast<ll>(
                incidencias[estado].temperatura
            ) - incidencias[estado - 1].temperatura;

            relajar(estado, estado - 1, costo);
        }

        if (
            estado + 1 < estados &&
            incidencias[estado + 1].habitacion ==
                incidencias[estado].habitacion
        ) {
            ll costo = static_cast<ll>(
                incidencias[estado + 1].temperatura
            ) - incidencias[estado].temperatura;

            relajar(estado, estado + 1, costo);
        }
    }

    return 0;
}
