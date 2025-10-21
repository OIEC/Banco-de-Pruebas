#include <bits/stdc++.h>
using namespace std;

int main() {
    long long P;
    cin >> P;

    std::vector<long long> divisoresMayoresQueTres;
    long long lim = sqrt(P);
    for (long long k = 3; k <= lim; ++k) {
        if (P % k == 0) {
            divisoresMayoresQueTres.push_back(k);
        }
    }

    // Imprimir divisores pequeños (orden ascendente por k)
    for (auto k : divisoresMayoresQueTres) 
    {
        cout << k << " " << P / k << endl;
    }

    // Imprimir divisores grandes
    for (int i = divisoresMayoresQueTres.size() - 1; i >= 0; --i)
    {
        if (divisoresMayoresQueTres[i] * divisoresMayoresQueTres[i] == P)
        {
            continue;
        }
        cout << P / divisoresMayoresQueTres[i] << " " << divisoresMayoresQueTres[i] << endl;
    }

    // Casos especiales para P/2 y P.
    if (P % 2 == 0)
    {
        cout << P/2 << " " << 2 << endl;
    }
    cout << P << " " << 1 << endl;

    return 0;
}