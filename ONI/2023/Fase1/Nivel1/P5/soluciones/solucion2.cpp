#include <iostream>

using namespace std;

int num[6][6];

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, K, M;
  cin >> N >> K >> M;

  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      int color;
      cin >> color;
      num[i][j] = color;
    }
  }

  for (int i = 0; i < K; ++i)
  {
    int cuadradoCentralSupIzq = num[2][2];
    int cuadradoCentralInfIzq = num[3][2];
    int cuadradoCentralInfDer = num[3][3];
    int cuadradoCentralSupDer = num[2][3];

    num[2][2] = num[0][0];
    num[3][2] = num[5][0];
    num[3][3] = num[5][5];
    num[2][3] = num[0][5];

    num[0][0] = num[1][1];
    num[5][0] = num[4][1];
    num[5][5] = num[4][4];
    num[0][5] = num[1][4];

    num[1][1] = cuadradoCentralSupIzq;
    num[4][1] = cuadradoCentralInfIzq;
    num[4][4] = cuadradoCentralInfDer;
    num[1][4] = cuadradoCentralSupDer;
  }

  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      cout << num[i][j] << " ";
    }
      cout << endl;
  }

  return 0;
}