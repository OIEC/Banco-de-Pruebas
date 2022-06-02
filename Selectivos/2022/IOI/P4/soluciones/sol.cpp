#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int64_t opt_order(const vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int64_t>> m(n);
    vector<vector<int64_t>> s(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i].push_back(0);
            s[i].push_back(0);
        }
    }

    for (int len_minus_one = 1; len_minus_one < n; len_minus_one++) {
        for (int i = 0; i < n - len_minus_one; i++) {
            int j = i + len_minus_one;
            m[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++) {
                int64_t cost = m[i][k] + m[k + 1][j] + dims[i]*dims[k+1]*dims[j+1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[0][n-1];
}


int main() {
    int n;
    cin >> n;
    vector<int> dims;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (i == 0) {
            dims.push_back(x);
        }
        dims.push_back(y);
    }
    cout << opt_order(dims) << endl;
    return 0;
}
