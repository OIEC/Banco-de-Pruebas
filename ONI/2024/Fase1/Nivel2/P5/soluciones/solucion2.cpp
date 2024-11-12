#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1000000000; // Definir MOD = 10^9

// Función que une dos números
long long unir_numeros(long long a, long long b)
{
    long long potencia = 10;
    while (b >= potencia)
    {
        potencia *= 10; // Encuentra cuántos dígitos tiene b
    }
    long long resultado = (a * potencia + b) % MOD; // Concatenar y aplicar módulo
    return resultado;
}

int main()
{
    int n;
    cin >> n; // Leer la cantidad de números

    vector<int> numeros(n); // Lista de números
    for (int i = 0; i < n; i++)
    {
        cin >> numeros[i]; // Leer los números
    }

    vector<char> operaciones(n - 1); // Lista de operaciones (todas serán 'u')
    for (int i = 0; i < n - 1; i++)
    {
        cin >> operaciones[i]; // Leer las operaciones (todas serán 'u')
    }

    long long resultado = numeros[0]; // Inicializar el resultado con el primer número

    // Empezar a unir los números
    for (int i = 0; i < n - 1; i++)
    {
        resultado = unir_numeros(resultado, numeros[i + 1]); // Unir el número actual con el siguiente. Sabemos que siempre será una unión.
    }

    // Imprimir el resultado final
    cout << resultado << endl;

    return 0;
}
