#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> grafo[1001];

    // Llenar el grafo.
    for (int i = 1; i <= N; ++i)
    {
        int persona;
        int numConocidos;
        cin >> persona;
        cin >> numConocidos;

        for (int j = 0; j < numConocidos; ++j)
        {
            int conocido;
            cin >> conocido;
            grafo[persona].push_back(conocido);
        }
    }


    // Hallar cantidad de conocidos para cada persona llenando un vector de personas famosas.
    vector<pair<int,int>> personasFamosas;
    for (int i = 1; i <= N; ++i)
    {
        int numQueLoConocen = 0;
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 0; k < grafo[j].size(); ++k)
            {
                if (grafo[j][k] == i)
                {
                    ++numQueLoConocen;
                }
            }
        }

        if (numQueLoConocen > N/2)
        {
            pair<int,int> par;
            par.first = numQueLoConocen;
            par.second = i;
            personasFamosas.push_back(par);
        }
    }

    if (personasFamosas.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        // Ordenar y leer de forma descendente.
        std::sort(personasFamosas.begin(), personasFamosas.end());
        for (int i = personasFamosas.size() - 1; i >= 0; i--)
        {
            cout << personasFamosas[i].second << endl;
        }
    }
}