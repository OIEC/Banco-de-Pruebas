#include <iostream>

using namespace std;

bool EsDigito(char c)
{
  return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9');
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  char cadena[100];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> cadena[i];
  }

  int cantidadNum = 0;
  bool esNum = false;

  for (int i = 0; i < n; ++i)
  {
    if (EsDigito(cadena[i]))
    {
      if (!esNum)
      {
        esNum = true;
      }

      if (i == n-1)
      {
        cantidadNum++;
      }
      
    }
    else
    {
      if (esNum)
      {
        esNum = false;
        cantidadNum++;
      }
    }
  }

  cout << cantidadNum;

  return 0;
}