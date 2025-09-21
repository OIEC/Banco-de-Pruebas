#include <iostream>
#include <string>

int main() {
    string s;
    std::cin >> s;  // leer la cadena de 3 caracteres

    std::cout << s[2] << s[1] << s[0];
    return 0;
}
