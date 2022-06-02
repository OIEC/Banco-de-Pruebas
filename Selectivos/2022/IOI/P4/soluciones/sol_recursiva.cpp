#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int64_t opt_order_re(const vector<int>& dims, int i, int j) {
    if (i == j) return 0;
    int64_t res = LLONG_MAX;
    for (int k = i; k < j; k++) {
        int64_t cost = opt_order_re(dims, i, k) +
                       opt_order_re(dims, k + 1, j) +
                       dims[i]*dims[k+1]*dims[j+1];
        if (cost < res) {
            res = cost;
        }
    }
    return res;
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
    cout << opt_order_re(dims, 0, dims.size() - 2) << endl;
    return 0;
}
