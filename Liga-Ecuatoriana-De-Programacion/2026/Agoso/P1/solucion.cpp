#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    cin >> d;

    long long totalManzanas = 0;
    long long totalNaranjas = 0;

    for (int i = 0; i < d; i++) {
        long long p, m, n, t;
        cin >> p >> m >> n >> t;

        // Sistema:
        //   a + o = p
        //   m*a + n*o = t
        // => a = (t - n*p) / (m - n)
        long long a = (t - n * p) / (m - n);
        long long o = p - a;

        totalManzanas += a;
        totalNaranjas += o;
    }

    cout << totalManzanas << " " << totalNaranjas << "\n";

    return 0;
}
