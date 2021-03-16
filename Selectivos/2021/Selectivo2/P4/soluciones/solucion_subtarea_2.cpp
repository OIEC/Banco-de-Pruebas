#include <cmath>
#include <iostream>
using namespace std;

// Cuenta los dígitos de un entero n.
int CuentaDigitos(int n)
{
    int cantidad = 0;
    while (n != 0) 
    {
        n = n / 10;
        ++cantidad;
    }
    return cantidad;
}
 
// Cuenta la cantidad de dígitos $d$ en un rango de dígitos dado.
int CuentaDigitosEnUnRango(int n, int d, int digito)
{
    int potenciaDeDiez = (int)pow(10, d);
    int siguientePotenciaDeDiez = potenciaDeDiez * 10;
    int digitoDerecha = n % potenciaDeDiez;
 
    int abajo = n - n % siguientePotenciaDeDiez;
    int arriba = abajo + siguientePotenciaDeDiez;
 
    int curDigito = (n / potenciaDeDiez) % 10;
 
    // Si es la posición del dígito.
    if (curDigito < digito)
        return abajo / 10;
 
    if (curDigito == digito)
        return abajo / 10 + digitoDerecha + 1;
 
    return arriba / 10;
}
 
// Cuenta el número de dígitos d en el rango 0 a n. 
int NumeroDeDigitosEnRango(int n, int d)
{
    int cantidadDeDigitos = CuentaDigitos(n);
 
    // Itera sobre los dígitos de cada número.
    int cantidad = 0;
    for (int digito = 0; digito < cantidadDeDigitos; digito++)
        cantidad += CuentaDigitosEnUnRango(n, digito, d);
 
    return cantidad;
}

int main()
{
    int n;
    int d;
    cin >> n;
    cin >> d;
    cout << NumeroDeDigitosEnRango(n, d) << endl; 
}