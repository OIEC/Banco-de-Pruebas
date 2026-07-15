#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> secuencia(n);

    for (int i = 0; i < n; i++) {
        cin >> secuencia[i];
    }

    int b;
    cin >> b;

    int contador = 0;

    for (int numero : secuencia) {
        if (numero == b) {
            contador++;
        }
    }

    cout << contador << '\n';

    return 0;
}
