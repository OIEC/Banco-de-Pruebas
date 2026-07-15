#include <iostream>

using namespace std;

int main() {

    int x, y, z;
    cin >> x >> y >> z;

    if (x == y && y == z) {
        cout << "equilatero\n";
    } else if (x == y || x == z || y == z) {
        cout << "isosceles\n";
    } else {
        cout << "escaleno\n";
    }

    return 0;
}
