#include<iostream>
using namespace std;

int arr[30000];

int main ()
{
    int n;
    cin >> n;

    // Acumulamos la suma total mientras leemos la entrada.
    int sumaTotal = 0;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        arr[i] = num;
        sumaTotal += num;
    }

    // Chequeamos si la suma acumulada hasta i = sumaTotal / 2 = suma desde i+1 hasta el final.
    int sumaAcumulada = 0;
    int indice = -1;
    for (int i = 0; i < n; ++i)
    {
        sumaAcumulada += arr[i];
        if (2 * sumaAcumulada == sumaTotal)
        {
            indice = i;
        }
    }

    if (indice != -1)
    {  
        cout << indice + 1 << endl; 
    }
    else
    {
        cout << "No existe" << endl;
    }
}