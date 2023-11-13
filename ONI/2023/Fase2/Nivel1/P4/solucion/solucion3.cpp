#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  unsigned long long N;
  cin >> N;
  
  // Usamos que el proceso mantiene invariante el residuo mod 9.
  // De esta forma, solamente el último grupo contribuye al residuo mod 9, 
  // ya que los demás dígitos pueden ser agrupados en grupos de 10 números que suman un múltiplo de 9.
  int r = N % 10;
  int m = ((r*(r+1))/2)%9;
  if (m == 0)
  {
    m = 9;
  }
  cout << m;
  
  return 0;
}