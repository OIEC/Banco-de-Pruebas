#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  bool encontrado = false;
  int a[n];

  for (int i = 0; i < n; i++)
  {
      cin >> a[i];
  }
  
  // Evaluamos las sumas izquierda y derecha en cada posición y comparamos.
  for (int r = 0; r < n; r++)
  {
    int suma1 = 0, suma2 = 0;

    for (int i = 0; i < r; i++)
    {
        suma1 += a[i];
    }

    for (int i = r; i < n; i++)
    {
        suma2 += a[i];
    }

    if (suma1 == suma2)
    {
      cout << r << endl;
      encontrado = true;
      break;
    }
  }
  
  if (!encontrado)
  {
      cout << "No existe";
  }
}