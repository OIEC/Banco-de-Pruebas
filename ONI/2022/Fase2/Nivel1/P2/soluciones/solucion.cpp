#include <iostream>
using namespace std;

int main() {
  int p0;
  int p1;
  int p2;
  int p3;
  int p4;
  cin >> p0;
  cin >> p1;
  cin >> p2;
  cin >> p3;
  cin >> p4;

  int conteo = 0;

  if (p0 == 0)
  {
    conteo = conteo + 1;
  }

  if (p1 == 1)
  {
    conteo = conteo + 1;
  }

  if (p2 == 2)
  {
    conteo = conteo + 1;
  }

  if (p3 == 3)
  {
    conteo = conteo + 1;
  }

  if (p4 == 4)
  {
    conteo = conteo + 1;
  }

  cout << conteo;

}