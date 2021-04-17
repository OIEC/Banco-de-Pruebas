#include<iostream>
#include<algorithm>
using namespace std;

string mensajes[100000];

int main ()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> mensajes[i];
    }

    // Strings idénticos aparecen en posiciones contiguas en un arreglo ordenado.
    sort(mensajes, mensajes+N);

    // Contamos cuántas veces aparece cada string y comparamos con el máximo en una sola iteración.
    string maxStr = mensajes[0];
    int maxRep = 0;

    string curStr = mensajes[0];
    int curRep = 0;

    for (int i = 0; i < N; ++i)
    {
        if (mensajes[i] == curStr)
        {
            curRep++;
        }
        else
        {
            if (curRep > maxRep)
            {
                maxStr = mensajes[i-1];
                maxRep = curRep;
            }
            curStr = mensajes[i];
            curRep = 1;
        }
    }
    if (curRep > maxRep)
    {
        maxStr = mensajes[N-1];
        maxRep = curRep;
    }

    cout << maxStr << endl;
}