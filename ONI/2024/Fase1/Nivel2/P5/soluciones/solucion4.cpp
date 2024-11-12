#include <iostream>
#include <vector>
using namespace std;

// Constante para el módulo
const long long MOD = 1000000000;

// Función que realiza la operación de unión
long long unir_numeros(long long a, long long b)
{
    long long potencia = 10;
    while (b >= potencia)
    {
        potencia *= 10; // Encuentra cuántos dígitos tiene b
    }
    return (a * potencia + b) % MOD; // Concatenar y aplicar módulo
}

// Función para calcular el resultado basado en las operaciones y su precedencia
long long calcular_resultado(vector<long long> &numeros, vector<char> &operaciones)
{

    int i;
    i = 0;
    // Primero aplicamos las uniones ('u')
    while (i < operaciones.size())
    {
        if (operaciones[i] == 'u')
        {
            numeros[i] = unir_numeros(numeros[i], numeros[i + 1]);
            numeros.erase(numeros.begin() + i + 1);     // Eliminar el número fusionado
            operaciones.erase(operaciones.begin() + i); // Eliminar la operación
        }
        else
        {
            i++;
        }
    }
    // Luego aplicamos las multiplicaciones ('m')
    i = 0;
    while (i < operaciones.size())
    {
        if (operaciones[i] == 'm')
        {
            numeros[i] = (numeros[i] * numeros[i + 1]) % MOD;
            numeros.erase(numeros.begin() + i + 1);     // Eliminar el número después de la multiplicación
            operaciones.erase(operaciones.begin() + i); // Eliminar la operación
        }
        else
        {
            i++;
        }
    }

    // Finalmente aplicamos las sumas ('s')
    i = 0;
    while (i < operaciones.size())
    {
        if (operaciones[i] == 's')
        {
            numeros[i] = (numeros[i] + numeros[i + 1]) % MOD;
            numeros.erase(numeros.begin() + i + 1);     // Eliminar el número después de la suma
            operaciones.erase(operaciones.begin() + i); // Eliminar la operación
        }
        else
        {
            i++;
        }
    }

    return numeros[0] % MOD; // Devolver el resultado final
}

int main()
{
    int n;
    cin >> n;

    vector<long long> numeros(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numeros[i]; // Leer los números
    }

    vector<char> operaciones(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> operaciones[i]; // Leer las operaciones
    }

    // Calcular el resultado final respetando la precedencia de operaciones
    long long resultado = calcular_resultado(numeros, operaciones);
    cout << resultado << endl;

    return 0;
}
