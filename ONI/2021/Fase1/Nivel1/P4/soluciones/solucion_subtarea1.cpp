#include<iostream>
#include<string>
using namespace std;

string cambioDeBase(int n, int base)
{
    string s = "";

    //Bucle hasta que n sea cero
    while(n != 0)
    {
        //Un digito se obtiene al obtener el residuo cuando n se divide para la base
        int digito = n % base;
        //Como se están almacenando caracteres hay que sumar el dígito al caracter '0'
      	s += '0' + digito;
        //Acualizar el número
        n /= base;
    }

    return s;
}

int main()
{
    int n;
    int base;
    cin >> n;
    cin >> base;

    string res = cambioDeBase(n, base);

    //Como se almacenan los residuos de derecha a izquierda, hay que imprimir en orden inverso
    for(int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}
