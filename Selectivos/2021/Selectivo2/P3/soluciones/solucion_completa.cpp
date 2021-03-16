// Generacion P log log P, Búsqueda binaria.

#include<iostream>
using namespace std;

int primos[10000000];
bool criba[10000001];
int cantidadPrimos;

int BusquedaBinaria(int min, int max, int tgt)
{
    while (min <= max)
    {
        int mid = min + (max - min) / 2;

        if (primos[mid] == tgt)
        {
            return mid;
        }
        else if (primos[mid] > tgt)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }

    return -1;
}

// Llena criba en base al algoritmo de la criba de Eratóstenes.
// criba[i] == true <=> i es primo.
// Genera todos los números primos <= n.
// Guarda la cantidad de primos en cantidadPrimos.
void GenerarPrimos(int n)
{
    for (int i=2; i<=n; i++) 
    { 
        criba[i] = true;
    }
    for (int p=2; p*p<=n; p++) 
    { 
        // Si criba[p] no cambia, entonces es primo.
        if (criba[p] == true) 
        { 
            // Marcar todos los múltiplos de p hasta p^2.
            for (int i=p*p; i<=n; i+=p)
            { 
                criba[i] = false;
            } 
        } 
    }

    // Llenar el arreglo primos en base a criba.
    int idxPrimo = 0;
    for (int i = 2; i <= n; i++)
    {
        if (criba[i])
        {
            primos[idxPrimo] = i;
            idxPrimo++;
        }
    }
    cantidadPrimos = idxPrimo; 
}


void HallarPrimosConDiferencia(int d)
{
    for (int i = 0; i < cantidadPrimos - 1; ++i)
    {
        int idxPrimo = BusquedaBinaria(0, cantidadPrimos - 1, primos[i] + d);

        if (idxPrimo != -1)
        {
            cout << primos[i] << " " << primos[idxPrimo] << endl;
        }
    }
}

int main ()
{
    int n;
    int d;
    cin >> n;
    cin >> d;

    GenerarPrimos(n-1);
    HallarPrimosConDiferencia(d);
}