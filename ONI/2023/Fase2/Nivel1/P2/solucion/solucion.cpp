#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  // Contamos la cantidad de veces que aparece cada número del dado.
  int cantidad_1 = 0;
  int cantidad_2 = 0;
  int cantidad_3 = 0;
  int cantidad_4 = 0;
  int cantidad_5 = 0;
  int cantidad_6 = 0;
  
  for (int i = 0; i < N; ++i)
  {
    int num;
    cin >> num;
    if (num == 1)
    {
      cantidad_1++;
    }
    if (num == 2)
    {
      cantidad_2++;
    }
    if (num == 3)
    {
      cantidad_3++;
    }
    if (num == 4)
    {
      cantidad_4++;
    }
    if (num == 5)
    {
      cantidad_5++;
    }
    if (num == 6)
    {
      cantidad_6++;
    }
  }

  // Hallar la mayor cantidad de veces que aparece un valor.
  int max = cantidad_1;
  if (cantidad_2 > max)
  {
    max = cantidad_2;
  }
  if (cantidad_3 > max)
  {
    max = cantidad_3;
  }
  if (cantidad_4 > max)
  {
    max = cantidad_4;
  }
  if (cantidad_5 > max)
  {
    max = cantidad_5;
  }
  if (cantidad_6 > max)
  {
    max = cantidad_6;
  }
 
  // Hallar la menor cantidad de veces que aparece un valor.
  int min = cantidad_1;
  if (cantidad_2 < min)
  {
    min = cantidad_2;
  }
  if (cantidad_3 < min)
  {
    min = cantidad_3;
  }
  if (cantidad_4 < min)
  {
    min = cantidad_4;
  }
  if (cantidad_5 < min)
  {
    min = cantidad_5;
  }
  if (cantidad_6 < min)
  {
    min = cantidad_6;
  }

  // El dado es K-normal donde K es la diferencia entre la mayor y menor cantidad de veces.
  int K = max - min;
  cout << K;

  return 0;
}