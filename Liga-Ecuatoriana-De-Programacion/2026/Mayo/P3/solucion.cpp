#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cctype>

using namespace std;

int main() {
  
    string s;
    long long c;

    cin >> s >> c;

    vector<pair<char, long long>> bloques;
    long long longitudTotal = 0;

    int i = 0;

    while (i < static_cast<int>(s.size())) {
        char letra = s[i];
        i++;

        long long cantidad = 0;

        while (i < static_cast<int>(s.size()) &&
               isdigit(static_cast<unsigned char>(s[i]))) {
            cantidad = cantidad * 10 + (s[i] - '0');
            i++;
        }

        bloques.push_back({letra, cantidad});
        longitudTotal += cantidad;
    }

    long long posicion = c % longitudTotal;

    for (const auto& bloque : bloques) {
        char letra = bloque.first;
        long long cantidad = bloque.second;

        if (posicion < cantidad) {
            cout << letra << '\n';
            return 0;
        }

        posicion -= cantidad;
    }

    return 0;
}
