#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int cantidadDeMultiplos = 0;
  for (int i = 0; i < 5; ++i)
  {
    int n;
    cin >> n;
    if (n % 5 == 0)
    {
      cantidadDeMultiplos++;
    }
  }
  cout << cantidadDeMultiplos;

  return 0;
}