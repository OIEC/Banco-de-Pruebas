#include<iostream>
using namespace std;

void ImprimirSecuencias (int x, int d)
{
  for (int i = 0; i < d; i++)
  {
    cout << x + i << " ";
  }
}

int main ()
{
  int n;
  cin >> n;

  for (int d = 1; d*d - d <= 2*n; d++)
  {
    int numerador = 2*n - d*d + d;
    int denominador = 2*d;

    if (numerador < 0) break;
    if (numerador % denominador != 0)
    {
      continue;
    }

    int x = numerador / denominador;
    ImprimirSecuencias(x, d);
    cout << endl;
  }
}
