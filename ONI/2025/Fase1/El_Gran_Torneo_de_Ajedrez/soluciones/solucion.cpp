#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> victorias(N + 1, 0); /* inicializamos un vector con todos los valores en 0 y con N + 1
    para poder dejar el espacio 0 vacío y no complicarse haciendo operaciones innecesarias*/

    int total = N * (N - 1) / 2; // formula que ayuda a determinar el número de partidas jugadas
    
    for (int i = 0; i < total; i++) {
        int a, b;
        cin >> a >> b;
        victorias[a]++;   // se suma solo las victorias
    }

    // Se imprimen las victorias en orden
    for (int i = 1; i <= N; i++) {
        cout << victorias[i] << "\n";
    }

    // Busqueda simple para encontrar al campeón.
    int campeon = 1;
    for (int i = 2; i <= N; i++) {
        if (victorias[i] > victorias[campeon]) {
            campeon = i;
        }
    }
    cout << campeon << "\n";

    return 0;
}
