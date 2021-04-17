#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a[n];
  int sumas[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // Pre-computamos todas las sumas parciales.
  int sumaHastaK = 0;
  for (int i = 0; i < n; i++)
  {
    sumaHastaK += a[i];
    sumas[i] = sumaHastaK;
  }
  
  // Hacemos búsqueda binaria sobre las sumas precomputadas para encontrar el índice.
  int r = -1;
  if (sumaHastaK % 2 == 0)
  {
    int min = 0;
    int max = n - 1;
    int tgt = sumaHastaK / 2;

    while (min <= max)
    {
      int mid = (min + max) / 2;

      if (sumas[mid] == tgt)
      {
        r = mid;
        break;
      }
      else if (sumas[mid] > tgt)
        max = mid - 1;
      else
        min = mid + 1;
    }
  }

  if (r == -1)
    cout << "No existe";
  else 
    cout << r + 1;
}