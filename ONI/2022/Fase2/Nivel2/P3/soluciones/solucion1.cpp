#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int valorArabigo = 0;

  for (int i = 0; i < n; ++i)
  {
    char digito;
    cin >> digito;

    if (digito == 'I')
    {
      valorArabigo+=1;
    }
    
    if (digito == 'V')
    {
      valorArabigo+=5;
    }

    if (digito == 'X')
    {
      valorArabigo+=10;
    }

    if (digito == 'L')
    {
      valorArabigo+=50;
    }

    if (digito == 'C')
    {
      valorArabigo+=100;
    }

    if (digito == 'D')
    {
      valorArabigo+=500;
    }

    if (digito == 'M')
    {
      valorArabigo+=1000;
    }
  }

  cout << valorArabigo;

  return 0;
}