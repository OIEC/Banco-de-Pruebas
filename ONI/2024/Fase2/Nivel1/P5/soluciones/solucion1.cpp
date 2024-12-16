#include <iostream>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    int ultima_casa;

    for (int i = 0; i < n; i++) {
        int casa;
        cin >> casa;
        if (i == n - 1) {
            ultima_casa = casa;
        }
    }

    int resultado = ultima_casa - x;
    cout << resultado << endl;

    return 0;
}
