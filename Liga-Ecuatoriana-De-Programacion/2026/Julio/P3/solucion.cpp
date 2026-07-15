#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<long long> numeros(n);

    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    int posicion1 = 0;
    int posicion2 = 1;

    long long diferenciaMinima =
        llabs(numeros[0] - numeros[1]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diferencia =
                llabs(numeros[i] - numeros[j]);

            if (diferencia < diferenciaMinima) {
                diferenciaMinima = diferencia;
                posicion1 = i;
                posicion2 = j;
            }
        }
    }

    cout << diferenciaMinima << '\n';
    cout << numeros[posicion1] << ' '
         << numeros[posicion2] << '\n';
    cout << posicion1 << ' '
         << posicion2 << '\n';

    return 0;
}
