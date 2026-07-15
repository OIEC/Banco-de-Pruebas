#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct PorColor {
    int color;
    int belleza;
    int id;
};

struct CompararPorColor {
    bool operator()(const PorColor& a, const PorColor& b) const {
        if (a.color != b.color) {
            return a.color < b.color;
        }

        if (a.belleza != b.belleza) {
            return a.belleza < b.belleza;
        }

        return a.id < b.id;
    }
};

struct Clasificado {
    int tipo;
    int belleza;
    int id;
};

struct CompararClasificado {
    bool operator()(const Clasificado& a, const Clasificado& b) const {
        if (a.tipo != b.tipo) {
            return a.tipo < b.tipo;
        }

        if (a.belleza != b.belleza) {
            return a.belleza < b.belleza;
        }

        return a.id < b.id;
    }
};

void agregarSinRepetir(vector<int>& elementos, int id) {
    for (int elemento : elementos) {
        if (elemento == id) {
            return;
        }
    }

    elementos.push_back(id);
}

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> color(n + 1);
    vector<int> belleza(n + 1);
    vector<unsigned char> esMaximo(n + 1, false);

    set<PorColor, CompararPorColor> lapicesPorColor;
    set<Clasificado, CompararClasificado> clasificados;

    for (int i = 1; i <= n; i++) {
        cin >> color[i] >> belleza[i];

        lapicesPorColor.insert({
            color[i],
            belleza[i],
            i
        });
    }

    auto obtenerMaximo = [&](int c) {
        auto it = lapicesPorColor.upper_bound({
            c,
            INT_MAX,
            INT_MAX
        });

        --it;
        return it->id;
    };

    long long sumaMaximos = 0;

    for (int c = 1; c <= m; c++) {
        int id = obtenerMaximo(c);

        esMaximo[id] = true;
        sumaMaximos += belleza[id];
    }

    for (int i = 1; i <= n; i++) {
        clasificados.insert({
            esMaximo[i] ? 1 : 0,
            belleza[i],
            i
        });
    }

    auto imprimirRespuesta = [&]() {
        long long respuesta = sumaMaximos;

        auto primerMaximo = clasificados.lower_bound({
            1,
            INT_MIN,
            INT_MIN
        });

        int menorMaximo = primerMaximo->belleza;

        if (primerMaximo != clasificados.begin()) {
            auto mejorNoMaximo = primerMaximo;
            --mejorNoMaximo;

            int mayorNoMaximo = mejorNoMaximo->belleza;

            respuesta = max(
                respuesta,
                sumaMaximos - menorMaximo + mayorNoMaximo
            );
        }

        cout << respuesta << '\n';
    };

    imprimirRespuesta();

    while (q--) {
        int tipo, i, valor;
        cin >> tipo >> i >> valor;

        int colorAnterior = color[i];
        int nuevoColor = colorAnterior;
        int nuevaBelleza = belleza[i];

        if (tipo == 1) {
            nuevoColor = valor;
        } else {
            nuevaBelleza = valor;
        }

        vector<int> coloresAfectados;
        coloresAfectados.push_back(colorAnterior);

        if (nuevoColor != colorAnterior) {
            coloresAfectados.push_back(nuevoColor);
        }

        vector<int> lapicesAfectados;

        for (int c : coloresAfectados) {
            int idMaximo = obtenerMaximo(c);

            sumaMaximos -= belleza[idMaximo];
            agregarSinRepetir(lapicesAfectados, idMaximo);
        }

        agregarSinRepetir(lapicesAfectados, i);

        for (int id : lapicesAfectados) {
            clasificados.erase({
                esMaximo[id] ? 1 : 0,
                belleza[id],
                id
            });
        }

        lapicesPorColor.erase({
            color[i],
            belleza[i],
            i
        });

        color[i] = nuevoColor;
        belleza[i] = nuevaBelleza;

        lapicesPorColor.insert({
            color[i],
            belleza[i],
            i
        });

        for (int c : coloresAfectados) {
            int idMaximo = obtenerMaximo(c);

            sumaMaximos += belleza[idMaximo];

            bool yaFueRetirado = false;

            for (int id : lapicesAfectados) {
                if (id == idMaximo) {
                    yaFueRetirado = true;
                    break;
                }
            }

            if (!yaFueRetirado) {
                clasificados.erase({
                    esMaximo[idMaximo] ? 1 : 0,
                    belleza[idMaximo],
                    idMaximo
                });

                lapicesAfectados.push_back(idMaximo);
            }
        }

        for (int id : lapicesAfectados) {
            int maximoDeSuColor = obtenerMaximo(color[id]);

            esMaximo[id] = (id == maximoDeSuColor);

            clasificados.insert({
                esMaximo[id] ? 1 : 0,
                belleza[id],
                id
            });
        }

        imprimirRespuesta();
    }

    return 0;
}
