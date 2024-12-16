#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> casas(n);

    for (int i = 0; i < n; i++) {
        cin >> casas[i];
    }

    int resultado = abs(casas[0] - x);
    for (int i = 1; i < n; i++) {
        resultado += abs(casas[i] - casas[i - 1]);
    }

    cout << resultado << endl;

    return 0;
}
