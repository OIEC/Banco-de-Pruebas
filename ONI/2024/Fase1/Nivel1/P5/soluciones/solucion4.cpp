#include <iostream>
#include <map>

int main() {
    long long n, m;
    long long a;

    // Entrada del tamaño del array
    std::cin >> n;

    // Mapa de frecuencias para almacenar la cantidad de veces que aparece cada elemento en el array
    std::map<long long, long long> frecuencia;

    // Entrada del array y conteo de la frecuencia de cada elemento
    for (long long i = 0; i < n; ++i) {
        std::cin >> a;
        frecuencia[a] = frecuencia[a] + 1;  // Incrementa la frecuencia del elemento 'a'
    }

    // Entrada del número de consultas
    std::cin >> m;

    // Para cada consulta, muestra la frecuencia del número consultado
    for (long long i = 0; i < m; ++i) {
        long long consulta;
        std::cin >> consulta;
        // Imprime la frecuencia del número consultado, o 0 si no se encuentra
        std::cout << frecuencia[consulta] << std::endl;
    }

    return 0;
}
