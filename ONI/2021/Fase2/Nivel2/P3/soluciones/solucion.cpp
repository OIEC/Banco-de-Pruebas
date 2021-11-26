#include <iostream>
using namespace std;


char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v', 'w','x','y','z'};


char Rotacion(char c, int n)
{
    int indice = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (alfabeto[i] == c)
        {
            indice = i;
        }
    }

    indice = (indice + n) % 26;

    return alfabeto[indice];
}


int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    char mensaje[m];

    for (int i = 0; i < m; ++i)
    {
        char c;
        cin >> c;
        mensaje[i] = c;
    }

    for (int i = 0; i < m; ++i)
    {
        char rotacion = Rotacion(mensaje[i], n);
        cout << rotacion;
    }
}
