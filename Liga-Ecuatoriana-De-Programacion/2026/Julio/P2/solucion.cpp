#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> digitos(n);

    for (int i = 0; i < n; i++) {
        cin >> digitos[i];
    }

    bool capicua = true;

    for (int i = 0; i < n / 2; i++) {
        if (digitos[i] != digitos[n - 1 - i]) {
            capicua = false;
            break;
        }
    }

    if (capicua) {
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
