#include <iostream>
#include <vector>

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


    // Hallar la única persona famosa.
    int personaFamosa;
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
            personaFamosa = i;
        }
    }
    
    cout << personaFamosa << endl;
}