#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n), y(n);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    long long total = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<long long, int> freq;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            long long d2 = dx * dx + dy * dy;

            freq[d2]++;
        }

        for (auto &p : freq) {
            long long f = p.second;
            total += f * (f - 1) / 2; // combinaciones de 2 puntos a igual distancia
        }
    }

    cout << total << "\n";
    return 0;
}
