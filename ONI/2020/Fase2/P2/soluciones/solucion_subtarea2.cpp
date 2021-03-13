#include<iostream>
using namespace std;

int sueldos[10000];

// Calcula la suma total de bonos, dado un límite k particular.
int SumaDeBonos(int k, int n, int d)
{
  int total = 0;
  for (int i = 0; i < d; i++)
  {
    if (sueldos[i] > k)
    {
      total += k;
    }
    else
    {
      total += sueldos[i];
    }
  }
  return total;
}

// Hace una Búsqueda binaria modificada, buscando el valor de k en el rango ordenado [0, n] 
// que minimice la diferencia entre la cantidad de dinero dado y la suma de bonos.
int BusquedaBinaria(int min, int max, int n, int d)
{
  int minDif = n;
  int k = n;
  while (min <= max)
  {
    int actualK = (min+max)/2;
    int total = SumaDeBonos(actualK, n, d);

    if (total <= n)
    {
      int dif = n - total;
      if (dif <= minDif)
      {
        minDif = dif;
        k = actualK;
      }
      min = actualK + 1;
    }
    else
    {
      max = actualK - 1;
    }
  }

  return k;
}

int main ()
{
  int n, d;
  cin >> n >> d;
  int sum = 0;
  int maxSueldo = 0;
  for (int i = 0; i < d; i++)
  {
    cin >> sueldos[i];
    sum += sueldos[i];
    if (sueldos[i] > maxSueldo)
    {
      maxSueldo = sueldos[i];
    }
  }

  // Si la cantidad de dinero es mayor a la suma de sueldos,
  // el límite es el sueldo máximo.
  if (n >= sum)
  {
    cout << maxSueldo;
  }
  else
  {
    int k = BusquedaBinaria(0, n, n, d);
    cout << k;
  }
}