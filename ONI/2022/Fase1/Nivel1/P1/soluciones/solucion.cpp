#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int cantidadDeVocales = 0;
  for (int i = 0; i < 10; ++i)
  {
    char c;
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
      cantidadDeVocales = cantidadDeVocales + 1;
    }
  }
  cout << cantidadDeVocales;

  return 0;
}