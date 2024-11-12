#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000000; // Definir MOD = 10^9

int main() {
    int n;
    cin >> n; // Leer la cantidad de números
    
    vector<int> numeros(n); // Lista de números
    for (int i = 0; i < n; i++) {
        cin >> numeros[i]; // Leer los números
    }
    
    vector<char> operaciones(n-1); // Lista de operaciones
    for (int i = 0; i < n-1; i++) {
        cin >> operaciones[i]; // Leer las operaciones (todas serán 's' en este caso)
    }

    long long resultado = 0; // Inicializar el resultado con 0

    // Empezar a sumar después de haber leído todos los números y operaciones
    for (int i = 0; i < n; i++) {
        resultado += numeros[i]; // Sabemos que todas las operaciones son sumas, simplemente sumamos todos los números en el arreglo.
        // Si el resultado supera el límite, se aplica el módulo MOD
        if (resultado >= MOD) {
            resultado %= MOD;
        }
    }

    // Imprimir el resultado final
    cout << resultado << endl;

    return 0;
}
