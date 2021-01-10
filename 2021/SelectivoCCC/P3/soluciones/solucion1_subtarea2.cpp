#include<iostream>
#include<algorithm>
using namespace std;

int nums[2500];

int BusquedaBinaria(int lo, int hi, int tgt)
{
  int min = lo;
  int max = hi;

  while (min <= max)
  {
    int guess = (min + max) / 2;
    if (nums[guess] >= tgt)
    {
      max = guess - 1;
    }
    if (nums[guess] < tgt)
    { 
      min = guess + 1;
    }
  }
  return max;
}

int ContarTriangulos(int n)
{
  int numTriangulos = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      // para cada par distinto de lados (a,b), necesitamos encontrar
      // todos los lados menores a a+b distinto de a y b.
      // => El índice del MAYOR número estrictamente menor a a+b.
      // La cantidad de números en el rango (b, a+b).
      // Se hace desde b, porque el último valor debe ser mayor a a y b
      // para evitar permutaciones.
      int idx = BusquedaBinaria(j+1, n-1, nums[i]+nums[j]);
      numTriangulos += idx - j;
    }
  }
  return numTriangulos;
}

int main ()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    nums[i] = num;
  }

  sort(nums, nums+n);

  cout << ContarTriangulos(n);
}
