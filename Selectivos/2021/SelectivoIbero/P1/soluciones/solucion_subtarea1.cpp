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

    // Contamos cuántas veces cada string aparece y comparamos con el máximo.
    string maxStr = mensajes[0];
    int maxRep = 0;
    for (int i = 0; i < N; ++ i)
    {
        string curStr = mensajes[i];
        int curRep = 0;
        for (int j = 0; j < N; ++j)
        {
            if (mensajes[j] == curStr)
            {
                curRep++;
            }
        }
        if (curRep > maxRep)
        {
            maxStr = mensajes[i];
            maxRep = curRep;
        }
    }

    cout << maxStr << endl;
}