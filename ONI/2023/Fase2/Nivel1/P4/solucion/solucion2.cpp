#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  unsigned long long N;
  cin >> N;

  // Obtenemos la suma inicial agrupando en grupos de 10 dígitos que suman 45.
  unsigned long long q = N / 10;
  unsigned long long r = N % 10;
  unsigned long long s = (45*q) + ((r*(r+1))/2);  
  
  // Calculamos la suma de dígitos hasta que nos quede un dígito.
  while ((s / 10) > 0)
  {
    unsigned long long suma = 0;
    while (s != 0) 
    {
       suma += ((s % 10));
       s /= 10;
    }
    s = suma;
  }
  
  cout << s;

  return 0;
}