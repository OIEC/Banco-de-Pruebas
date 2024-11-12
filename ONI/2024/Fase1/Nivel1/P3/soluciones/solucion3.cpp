#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int conteo[N+1];

  for (int i = 1; i <= N; ++i)
  {
    conteo[i] = 0;
  }

  for (int i = 1; i <= N; ++i)
  {
    int k;
    cin >> k;
    int nk;
    cin >> nk;
    for (int j = 0; j < nk; ++j)
    {
      int conocido;
      cin >> conocido;
      conteo[conocido]++;
    }
  }

  int maxCelebridad = 0;
  int maxIndice = 0;
  for (int i = 1; i <= N; ++i)
  {
    if (conteo[i] > maxCelebridad)
    {
      maxCelebridad = conteo[i];
      maxIndice = i;
    }
  }

  for (int i = 1; i <= N; ++i)
  {
    if (conteo[i] == maxCelebridad)
    {
      cout << i << endl;
    }
  }

  return 0;
}