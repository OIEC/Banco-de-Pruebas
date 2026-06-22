#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k;
    cin >> n;

    vector<int> postes(n);

    for (int i = 0; i < n; i++) {
        cin >> postes[i];
    }

    sort(postes.begin(), postes.end());

    int respuesta = postes[k - 1] - postes[0];

    for (int i = k; i < n; i++) {
        respuesta = min(respuesta, postes[i] - postes[i - k + 1]);
    }

    cout << respuesta << endl;

    return 0;
}
