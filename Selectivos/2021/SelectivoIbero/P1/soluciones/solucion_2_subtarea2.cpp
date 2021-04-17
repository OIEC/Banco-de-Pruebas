#include<iostream>
#include<map>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    // Usamos un mapa donde la clave es cada string distinta y su valor es el número de veces que aparece.
    map<string,int> mapaStr;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        // Si str no existe en el mapa, el operador [] lo crea automáticamente.
        mapaStr[str]++;
    }

    // Iteramos sobre el mapa buscando el string que más se repita usando los valores del mapa.
    string maxStr;
    int maxRep = 0;
    for (auto str : mapaStr)
    {
        if (str.second > maxRep)
        {
            maxStr = str.first;
            maxRep = str.second;
        }
    }
    cout << maxStr << endl;
}