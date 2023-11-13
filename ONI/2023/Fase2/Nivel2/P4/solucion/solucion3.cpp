#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  int n;
  cin >> n;

  std::vector<int> vec;

  for (int i = 0; i < n; ++i)
  {
    int a;
    cin >> a;
    if (a <= 4997)
    {
      vec.push_back(a);
    }
  }

  std::sort(vec.begin(), vec.end());

  // Fijamos el primer elemento y encontramos los otros dos.
  int conteo = 0;
  for (int i = 0; i < vec.size() - 2; i++) 
  {

    // Avanzamos los extremos desde fuera hacia dentro.
    int l = i + 1;
    int r = vec.size() - 1;
    while (l < r) 
    {
      int suma = vec[i] + vec[l] + vec[r];
      if (suma == 5000) 
      {
          ++conteo;
          l++;
          r--;
      }
      else if (suma < 5000)
      {
        l++;
      }
      else
      {
        r--;
      }
    }
  }

  cout << conteo;
}