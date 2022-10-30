#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int coordenadaX = 0;
  int coordenadaY = 0;
  int largo = 1;
  int ancho = 1;

  for (int i = 0; i < 4; ++i)
  {
    int operacion;
    cin >> operacion;

    if (operacion == 1)
    {
      coordenadaY += 1;
    }

    if (operacion == 2)
    {
      coordenadaX+=1;
    }

    if (operacion == 3)
    {
      ancho*=2;
    }

    if (operacion == 4)
    {
      largo*=2;
    }
  }

  cout << largo * ancho << endl;
  cout << coordenadaX << endl;
  cout << coordenadaY << endl;

  return 0;
}