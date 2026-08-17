#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> bit_;

void update(int pos, int delta) {
    for (; pos <= N; pos += pos & (-pos))
        bit_[pos] += delta;
}

// Encuentra la posicion del k-esimo elemento "vivo" (con suma prefija == k)
int findKth(int k) {
    int pos = 0;
    int logN = 0;
    while ((1 << (logN + 1)) <= N) logN++;
    for (int pw = 1 << logN; pw > 0; pw >>= 1) {
        if (pos + pw <= N && bit_[pos + pw] < k) {
            pos += pw;
            k -= bit_[pos];
        }
    }
    return pos + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<string> nombres(N + 1);
    for (int i = 1; i <= N; i++) cin >> nombres[i];

    bit_.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) update(i, 1);

    int Q;
    cin >> Q;
    string out;
    while (Q--) {
        char c;
        int k;
        cin >> c >> k;
        int pos = findKth(k);
        if (c == 'P') {
            out += nombres[pos];
            out += '\n';
        } else { // 'M'
            update(pos, -1);
        }
    }
    cout << out;

    return 0;
}
