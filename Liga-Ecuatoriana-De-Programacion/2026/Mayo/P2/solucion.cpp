#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    long long a, b, x, y;
    cin >> a >> b >> x >> y;

    long long ladoALado =
        2 * (a + x + max(b, y));

    long long unaEncimaDeOtra =
        2 * (b + y + max(a, x));

    cout << min(ladoALado, unaEncimaDeOtra) << '\n';

    return 0;
}
