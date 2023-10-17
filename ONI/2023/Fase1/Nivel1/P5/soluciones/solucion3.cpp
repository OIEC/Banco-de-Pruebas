#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, m;
    vector<vector<int>> tablero;
    cin >> n >> k >> m;

    for(int i = 0; i < n; i++)
    {
        vector<int> r;
        for(int j = 0; j < n; j++)
        {
            int q;
            cin >> q;
            r.push_back(q);
        }
        tablero.push_back(r);
    }
    
    pair<int,int> cuadradoCentralSupIzq;
    pair<int,int> cuadradoCentralSupDer;
    pair<int,int> cuadradoCentralInfIzq;
    pair<int,int> cuadradoCentralInfDer;
    cuadradoCentralSupIzq.first=(n/2)-1; 
    cuadradoCentralSupIzq.second=(n/2)-1;
    cuadradoCentralSupDer.first=(n/2)-1;
    cuadradoCentralSupDer.second=(n/2);
    cuadradoCentralInfIzq.first=(n/2);
    cuadradoCentralInfIzq.second=(n/2)-1;
    cuadradoCentralInfDer.first=(n/2);
    cuadradoCentralInfDer.second=(n/2);
    
    int color_actual_superior_izquierda = tablero[cuadradoCentralSupIzq.first][cuadradoCentralSupIzq.second];
    int color_actual_superior_derecha = tablero[cuadradoCentralSupDer.first][cuadradoCentralSupDer.second];
    int color_actual_inferior_izquierda = tablero[cuadradoCentralInfIzq.first][cuadradoCentralInfIzq.second];
    int color_actual_inferior_derecha = tablero[cuadradoCentralInfDer.first][cuadradoCentralInfDer.second];
    
    int color_siguiente_superior_izquierda = 0;
    int color_siguiente_superior_derecha = 0;
    int color_siguiente_inferior_izquierda = 0;
    int color_siguiente_inferior_derecha = 0;

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < (n/2)-1; j++)
        {
            color_siguiente_superior_izquierda = tablero[cuadradoCentralSupIzq.first-j-1][cuadradoCentralSupIzq.second-j-1];
            color_siguiente_superior_derecha = tablero[cuadradoCentralSupDer.first-j-1][cuadradoCentralSupDer.second+j+1];
            color_siguiente_inferior_izquierda = tablero[cuadradoCentralInfIzq.first+j+1][cuadradoCentralInfIzq.second-j-1];
            color_siguiente_inferior_derecha = tablero[cuadradoCentralInfDer.first+j+1][cuadradoCentralInfDer.second+j+1];
            
            tablero[cuadradoCentralSupIzq.first-j-1][cuadradoCentralSupIzq.second-j-1] = color_actual_superior_izquierda;
            tablero[cuadradoCentralSupDer.first-j-1][cuadradoCentralSupDer.second+j+1] = color_actual_superior_derecha;
            tablero[cuadradoCentralInfIzq.first+j+1][cuadradoCentralInfIzq.second-j-1] = color_actual_inferior_izquierda;
            tablero[cuadradoCentralInfDer.first+j+1][cuadradoCentralInfDer.second+j+1] = color_actual_inferior_derecha;
            
            color_actual_superior_izquierda = color_siguiente_superior_izquierda;
            color_actual_superior_derecha = color_siguiente_superior_derecha;
            color_actual_inferior_izquierda = color_siguiente_inferior_izquierda;
            color_actual_inferior_derecha = color_siguiente_inferior_derecha;
        }
        
        tablero[(n/2)-1][(n/2)-1] = color_actual_superior_izquierda;
        tablero[(n/2)-1][(n/2)] = color_actual_superior_derecha;
        tablero[n/2][(n/2)-1] = color_actual_inferior_izquierda;
        tablero[n/2][n/2] = color_actual_inferior_derecha;
    }
    

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {    
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}