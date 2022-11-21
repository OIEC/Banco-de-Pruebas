#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int x[100];
  int y[100];
  int r[100];

  for (int i = 0; i < n; ++i)
  {
    cin >> x[i];
    cin >> y[i];
    cin >> r[i];
  }

  int cantidadNoIntersecante = 0;
  for (int i = 0; i < n; ++i)
  {
    int cantidadDeNoInterseccion = 0;
    for (int j = 0; j < n; ++j)
    {
        if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > (r[i] + r[j]) * (r[i] + r[j]))
        {
          ++cantidadDeNoInterseccion;
        }
    }
    if (cantidadDeNoInterseccion == n-1)
    {
      ++cantidadNoIntersecante;
    }
  }

  cout << cantidadNoIntersecante;
}