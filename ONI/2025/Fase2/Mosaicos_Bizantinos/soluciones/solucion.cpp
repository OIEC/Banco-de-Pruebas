#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n_colores;
    cin >> n_colores;

    vector<string> colores(n_colores);
    for (int i = 0; i < n_colores; i++) cin >> colores[i];

    int n_inicial;
    cin >> n_inicial;
    vector<string> inicial(n_inicial);
    for (int i = 0; i < n_inicial; i++) cin >> inicial[i];

    int n_final;
    cin >> n_final;
    vector<string> final(n_final);
    for (int i = 0; i < n_final; i++) cin >> final[i];

    // Contadores de ocurrencias
    unordered_map<string, int> count_inicial, count_final;

    for (auto &c : inicial) count_inicial[c]++;
    for (auto &c : final) count_final[c]++;

    // Asegurar que todos los colores estén en el mapa aunque tengan 0
    for (auto &c : colores) {
        if (!count_inicial.count(c)) count_inicial[c] = 0;
        if (!count_final.count(c)) count_final[c] = 0;
    }

    int extra = 0;
    int faltan = 0;

    for (auto &c : colores) {
        int a = count_inicial[c];
        int b = count_final[c];
        if (a > b) extra += a - b;
        else if (a < b) faltan += b - a;
    }

    cout << max(extra, faltan) << "\n";
    return 0;
}