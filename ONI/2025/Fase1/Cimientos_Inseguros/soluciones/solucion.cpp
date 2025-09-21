#include <bits/stdc++.h>
using namespace std;

int main() {
    int AP, AT;
    cin >> AP >> AT;
    int N = AP / AT;
    cout << N << '\n';
    if (N >= 1 && N < 2) {
        cout << "Baja densidad";
    } else if (N >= 2 && N <= 3) {
        cout << "Eficiente";
    } else if (N >= 4 && N <= 5) {
        cout << "Alta densidad";
    } else if (N >= 6) {
        cout << "Crítico";
    }

    return 0;
}
