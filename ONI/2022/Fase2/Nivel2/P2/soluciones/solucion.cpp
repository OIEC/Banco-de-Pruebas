#include <iostream>
#include <cmath>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int L1;
  cin >> L1;
  int x1 = 0;
  int y1 = 0;
  for (int i = 0; i < L1; ++i)
  {
    char movimiento;
    cin >> movimiento;
    if (movimiento == 'N')
    {
      y1 = y1 + 1;
    }
    if (movimiento == 'S')
    {
      y1 = y1 - 1;
    }
    if (movimiento == 'E')
    {
      x1 = x1 + 1;
    }
    if (movimiento == 'O')
    {
      x1 = x1 - 1;
    }
  }

  int L2;
  cin >> L2;
  int x2 = 0;
  int y2 = 0;
  for (int i = 0; i < L2; ++i)
  {
    char movimiento;
    cin >> movimiento;
    if (movimiento == 'N')
    {
      y2 = y2 + 1;
    }
    if (movimiento == 'S')
    {
      y2 = y2 - 1;
    }
    if (movimiento == 'E')
    {
      x2 = x2 + 1;
    }
    if (movimiento == 'O')
    {
      x2 = x2 - 1;
    }
  }

  int d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

  cout << d;

  return 0;
}