// D = 2, Generacion P^2, Búsqueda lineal.

#include<iostream>
using namespace std;

int primos[500000];
int cantidadPrimos;

bool EsPrimo(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void LlenarPrimos(int n)
{
    primos[0] = 2;
    int idxPrimo = 1;
    for (int i = 3; i < n; ++i)
    {
        if (EsPrimo(i))
        {
            primos[idxPrimo] = i;
            idxPrimo++;
        }
    }
    cantidadPrimos = idxPrimo;
}

void ImprimirPrimos()
{
    for (int i = 0; i < cantidadPrimos; ++i)
    {
        cout << primos[i] << endl;
    }
}

void HallarPrimosConDiferencia(int d)
{
    for (int i = 0; i < cantidadPrimos - 1; ++i)
    {
        if (primos[i+1] == primos[i] + d)
        {
            cout << primos[i] << " " << primos[i+1] << endl;
        }
    }
}

int main ()
{
    int n;
    int d;
    cin >> n;
    cin >> d;

    LlenarPrimos(n);
    HallarPrimosConDiferencia(d);
}