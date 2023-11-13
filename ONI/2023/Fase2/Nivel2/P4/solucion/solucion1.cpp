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
    vec.push_back(a);
  }

  // Iteramos convenientemente para contar tripletas distintas solamente.
  int conteo = 0;
  for (int i = 0; i < n-2; ++i)
  {
    for (int j = i+1; j < n-1; ++j)
    {
      for (int k = j+1; k < n; ++k)
      {
        if (vec[i] + vec[j] + vec[k] == 5000)
        {
          ++conteo;
        }
      }
    }
  }

  cout << conteo;
}