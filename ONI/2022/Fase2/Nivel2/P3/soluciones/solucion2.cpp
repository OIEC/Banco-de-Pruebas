#include <iostream>
using namespace std;

int ValorArabigo(char digito)
{
  if (digito == 'I')
    {
      return 1;
    }
    
    if (digito == 'V')
    {
      return 5;
    }

    if (digito == 'X')
    {
      return 10;
    }

    if (digito == 'L')
    {
      return 50;
    }

    if (digito == 'C')
    {
      return 100;
    }

    if (digito == 'D')
    {
      return 500;
    }

    if (digito == 'M')
    {
      return 1000;
    }
  return -1;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  char romano[2022];
  int valorArabigo = 0;

  for (int i = 0; i < n; ++i)
  {
    cin >> romano[i];
  }

  for (int i = 0; i < n; ++i)
  {

    if (i < n-1 && (ValorArabigo(romano[i]) < ValorArabigo(romano[i+1])))
    {
      valorArabigo -= ValorArabigo(romano[i]);
    }
    else
    {
      valorArabigo += ValorArabigo(romano[i]);
    }
  }

  cout << valorArabigo;

  return 0;
}