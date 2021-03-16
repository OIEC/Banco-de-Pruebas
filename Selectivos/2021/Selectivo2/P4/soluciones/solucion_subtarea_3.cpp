#include <cmath>
#include <iostream>
using namespace std;

// Cuenta los dígitos de un entero n.
unsigned long long CuentaDigitos(unsigned long long n)
{
    unsigned long long cantidad = 0;
    while (n != 0) 
    {
        n = n / 10;
        ++cantidad;
    }
    return cantidad;
}
 
// Cuenta la cantidad de dígitos $d$ en un rango de dígitos dado.
unsigned long long CuentaDigitosEnUnRango(unsigned long long n, int d, int digito)
{
    unsigned long long potenciaDeDiez = (unsigned long long)pow(10, d);
    unsigned long long siguientePotenciaDeDiez = potenciaDeDiez * 10;
    unsigned long long digitoDerecha = n % potenciaDeDiez;
 
    unsigned long long abajo = n - n % siguientePotenciaDeDiez;
    unsigned long long arriba = abajo + siguientePotenciaDeDiez;
 
    unsigned long long curDigito = (n / potenciaDeDiez) % 10;
 
    // Si es la posición del dígito.
    if (curDigito < digito)
        return abajo / 10;
 
    if (curDigito == digito)
        return abajo / 10 + digitoDerecha + 1;
 
    return arriba / 10;
}
 
// Cuenta el número de dígitos d en el rango 0 a n. 
unsigned long long NumeroDeDigitosEnRango(unsigned long long n, int d)
{
    unsigned long long cantidadDeDigitos = CuentaDigitos(n);
 
    // Itera sobre los dígitos de cada número.
    unsigned long long cantidad = 0;
    for (unsigned long long digito = 0; digito < cantidadDeDigitos; digito++)
        cantidad += CuentaDigitosEnUnRango(n, digito, d);
 
    return cantidad;
}

int main()
{
    unsigned long long n;
    int d;
    cin >> n;
    cin >> d;
    cout << NumeroDeDigitosEnRango(n, d) << endl; 
}