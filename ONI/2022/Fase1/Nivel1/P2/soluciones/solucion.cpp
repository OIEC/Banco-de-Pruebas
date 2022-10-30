#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int alturas[10];

  int min_altura = 1000;
  int max_altura = 0;
  int suma_altura = 0;
  for (int i = 0; i < 10; ++i)
  {
    cin >> alturas[i];
    if (alturas[i] > max_altura)
    {
      max_altura = alturas[i];
    }

    if (alturas[i] < min_altura)
    {
      min_altura = alturas[i];
    }

    suma_altura+=alturas[i];
  }

  cout << min_altura << endl;
  cout << max_altura << endl;
  cout << suma_altura/10 << endl;

  return 0;
}