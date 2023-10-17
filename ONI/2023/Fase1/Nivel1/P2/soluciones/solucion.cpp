#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  char palabra[10];
  cin >> palabra;

  // Modificamos el condicional de un palíndromo intercambiando los índices 0 y 4 para 
  // realizar el intercambio implícitamente.
  if ((palabra[4] == palabra[9]) && (palabra[1] == palabra[8]) && (palabra[2] == palabra[7]) 
    && (palabra[3] == palabra[6]) && (palabra[0] == palabra[5]))
  {
    cout << "SI";
  }
  else
  {
    cout << "NO";
  }

  return 0;
}