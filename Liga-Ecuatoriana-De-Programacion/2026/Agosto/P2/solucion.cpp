#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int N = (int)A.size();
    int M = (int)B.size();

    int col = -1, row = -1;

    // Buscamos la primera letra de A (en orden) que tambien aparezca en B
    for (int i = 0; i < N && col == -1; i++) {
        size_t pos = B.find(A[i]);
        if (pos != string::npos) {
            col = i;                 // posicion (columna) de la letra en A
            row = (int)pos;          // primera aparicion de esa letra en B
        }
    }

    vector<string> grid(M, string(N, '.'));

    // Escribimos A horizontalmente en la fila "row"
    for (int j = 0; j < N; j++) {
        grid[row][j] = A[j];
    }
    // Escribimos B verticalmente en la columna "col"
    for (int i = 0; i < M; i++) {
        grid[i][col] = B[i];
    }

    for (int i = 0; i < M; i++) {
        cout << grid[i] << "\n";
    }

    return 0;
}
