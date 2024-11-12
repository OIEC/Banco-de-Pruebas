#include <iostream>
#include <vector>

using namespace std;

// Función para contar las ocurrencias de un número en el array
int contarOcurrencias(const vector<int> &arr, int consulta)
{
    int contador = 0;
    // Recorre cada número en el array
    for (int num : arr)
    {
        // Si el número coincide con la consulta, incrementa el contador
        if (num == consulta)
        {
            contador++;
        }
    }
    return contador; // Devuelve el número total de ocurrencias
}

int main()
{
    // Entrada del tamaño del array
    int n;
    cin >> n;

    // Entrada de los elementos del array
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Lee cada número y lo guarda en el array
    }

    // Entrada del número de consultas
    int m;
    cin >> m;

    // Responde a cada consulta
    for (int i = 0; i < m; i++)
    {
        int consulta;
        cin >> consulta; // Lee la consulta
        // Imprime el número de veces que la consulta aparece en el array
        cout << contarOcurrencias(arr, consulta) << endl;
    }

    return 0;
}
