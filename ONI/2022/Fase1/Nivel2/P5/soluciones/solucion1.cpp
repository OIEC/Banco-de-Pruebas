#include <iostream>

using namespace std;

int MayorPotenciaDeCinco(int n)
{
  int p = 0;
  while (n % 5 == 0)
  {
    n /= 5;
    ++p;
  }
  return p;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int nFactorial = 1;
  for (int i = 1; i <= n; ++i)
  {
    nFactorial *= i;
  }

  int p = MayorPotenciaDeCinco(nFactorial);
  cout << p;

  return 0;
}