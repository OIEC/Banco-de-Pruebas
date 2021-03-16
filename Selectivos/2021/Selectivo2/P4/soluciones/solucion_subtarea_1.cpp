#include <iostream>
using namespace std;
 
// Cuenta el número de dígitos d en el número n.
int CantidadDeDigito(int n, int d)
{
    int cantidad = 0;
    while (n > 0)
    {
        if (n % 10 == d)
            cantidad++;
 
        n = n / 10;
    }
    return cantidad;
}
 
// Cuenta el número de dígitos d en el rango 0 a n.
int CantidadDeDigitoEnRango(int n, int d)
{
    int cantidad = 0; 
    if (d == 0) cantidad++;
 
    for (int i = 1; i <= n; i++)
        cantidad += CantidadDeDigito(i, d);
 
    return cantidad;
}

int main()
{
    int n;
    int d;
    cin >> n;
    cin >> d;
    cout << CantidadDeDigitoEnRango(n, d) << endl; 
}