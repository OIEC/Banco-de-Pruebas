#include<iostream>
using namespace std;

int sueldos[10000];

// Calcula la diferencia entre N (dolares disponibles) 
// y la suma de los bonos, dado un límite K en particular.
int DiferenciaLimite(int k, int n, int d)
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
  return n - total;
}

int main ()
{
  int n, d;
  cin >> n >> d;

  for (int i = 0; i < d; i++)
  {
    cin >> sueldos[i];
  }

  int minDif = n;
  int k = n;

  // Empezamos desde k = N hasta k = 1, buscando la mínima diferencia.
  for (int kActual = n; kActual >= 1; kActual--)
  {
    int dif = DiferenciaLimite(kActual, n, d);
    if (dif >= 0 && dif <= minDif)
    {
      minDif = dif;
      k = kActual;
    }
  }

  cout << k;
}