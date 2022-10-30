#include <iostream>
using namespace std;

int arr[1000];

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> arreglo[i];
  }

  int cima = -1;
  bool cimaEncontrada = false;
  for (int i = 1; i < n-1; ++i)
  {
      if (arreglo[i-1] < arreglo[i] && arreglo[i] > arreglo[i+1])
      {
        if (!cimaEncontrada)
        {
          cimaEncontrada = true;
          cima = arreglo[i];
        }
        else
        {
          cima = -1;
          break;
        }
      }
  }

  cout << cima;

  return 0;
}