#include<iostream>
using namespace std;

int main ()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    int A[N][N];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    }

    // rows
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N-1; ++j)
        {
            if (A[i][j] > A[i][j+1])
            {
                cout << "no valido en fila y columna: " << i << "," << j << endl;
                return 1; 
            }
        }
    }

    // cols
    for (int j = 0; j < N; ++j)
    {
        for (int i = 0; i < N-1; ++i)
        {
            if (A[i][j] > A[i+1][j])
            {
                cout << "no valido en fila y columna: " << i << "," << j << endl;
                return 1;
            }
        }
    }


    cout << "valido" << endl;
}
    