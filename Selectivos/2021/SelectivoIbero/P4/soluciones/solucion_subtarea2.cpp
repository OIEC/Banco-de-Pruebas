#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Clase que guarda la fila, columna y valor.
struct ValorIndices
{
    int fila;
    int columna; 
    int val;

    ValorIndices(int i, int j, int value)
    {
        fila = i;
        columna = j;
        val = value;
    }
};

// Función comparadora para la clase ValorIndices en base a val.
struct Comparacion 
{ 
    bool operator()(ValorIndices const& p1, ValorIndices const& p2) 
    { 
        return p1.val > p2.val; 
    } 
};

int main ()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    // Leemos en un vector de vectores.
    vector<vector<unsigned long long>> A;
    A.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        A[i].reserve(N);
    }

    vector<vector<bool>> EstaEnCola;
    EstaEnCola.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        EstaEnCola[i].reserve(N);
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
            EstaEnCola[i][j] = false;
        }
    }

    // Creamos una priority_queue ordenando con nuestra función comparadora.
    priority_queue<ValorIndices, std::vector<ValorIndices>, Comparacion> q;
    ValorIndices v = ValorIndices(0, 0, A[0][0]);
    q.push(v);
    EstaEnCola[0][0] = true;

    for (int i = 0; i < K-1; ++i)
    {
        ValorIndices val = q.top();
        q.pop();

        if (val.fila + 1 <= N-1 && !EstaEnCola[val.fila+1][val.columna])
        {
            v = ValorIndices(val.fila+1, val.columna, A[val.fila+1][val.columna]);
            q.push(v);
            EstaEnCola[val.fila+1][val.columna] = true;
        }
        
        if (val.columna + 1 <= N-1 && !EstaEnCola[val.fila][val.columna+1])
        {
            v = ValorIndices(val.fila, val.columna+1, A[val.fila][val.columna+1]);
            q.push(v);
            EstaEnCola[val.fila][val.columna+1] = true;
        }
    }

    cout << q.top().val << endl;
}