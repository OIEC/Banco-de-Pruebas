#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> ls(N), rs(N);
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        ls[i] = min(a, b);
        rs[i] = max(a, b);
    }

    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());

    string out;
    out.reserve(Q * 3);
    for (int j = 0; j < Q; j++) {
        long long q;
        cin >> q;

        // cantidad de cuerdas cuyo extremo izquierdo <= q
        long long cntL = upper_bound(ls.begin(), ls.end(), q) - ls.begin();
        // cantidad de cuerdas cuyo extremo derecho < q
        long long cntR = lower_bound(rs.begin(), rs.end(), q) - rs.begin();

        out += to_string(cntL - cntR);
        out += '\n';
    }
    cout << out;

    return 0;
}
