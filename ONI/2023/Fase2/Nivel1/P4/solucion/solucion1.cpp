#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  // Obtenemos la suma inicial.
  int s = 0;
  for (int i = 1; i <= N; ++i)
  { 
    s += (i % 10);
  }

  // Calculamos la suma de dígitos hasta que nos quede un dígito.
  while ((s / 10) > 0)
  {
    int suma = 0;
    while (s != 0) 
    {
       suma += ((s % 10));
       s /= 10;
    }
    s = suma;
  }
  
  cout << s;

  return 0;
}