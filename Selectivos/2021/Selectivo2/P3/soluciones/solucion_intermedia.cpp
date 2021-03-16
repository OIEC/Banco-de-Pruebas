// D variable, Generacion P root P, Búsqueda lineal.

#include<iostream>
#include<cmath>
using namespace std;

int primos[500000];
int cantidadPrimos;

bool EsPrimo(int n)
{
    for (int i = 2; i <= sqrt(n)+1; ++i)
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
        for (int j = i+1; j < cantidadPrimos; ++j)
        {
            if (primos[j] > primos[i] + d)
            {
                break;
            }

            if (primos[j] == primos[i] + d)
            {
                cout << primos[i] << " " << primos[j] << endl;
                break;
            }
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