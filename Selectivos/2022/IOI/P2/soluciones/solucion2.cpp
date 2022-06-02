#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int fila[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      fila[i][j] = 0;
  }
  fila[0][0] = 1;

  for(int i = 1; i < n; i++){
    fila[i][0] = 1;
    for(int j = 1; j < n; j++){
      fila[i][j] = fila[i - 1][j - 1] + fila[i - 1][j];
    }
  }

  for(int i = 0; i < n; i++)
    cout << fila[n - 1][i] << " ";

  return 0;
}