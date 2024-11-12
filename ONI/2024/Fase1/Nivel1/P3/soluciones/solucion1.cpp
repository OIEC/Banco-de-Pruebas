#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int persona1 = 0;
  int persona2 = 0;
  int persona3 = 0;
  int persona4 = 0;
  int persona5 = 0;

  for (int i = 1; i <= 5; ++i)
  {
    int k;
    cin >> k;
    int nk;
    cin >> nk;
    for (int j = 0; j < nk; ++j)
    {
      int conocido;
      cin >> conocido;
      if (conocido == 1)
      {
        persona1++;
      }

      if (conocido == 2)
      {
        persona2++;
      }

      if (conocido == 3)
      {
        persona3++;
      }

      if (conocido == 4)
      {
        persona4++;
      }

      if (conocido == 5)
      {
        persona5++;
      }
    }
  }

    if (persona1 > persona2 
    && persona1 > persona3 
    && persona1 > persona4
    && persona1 > persona5)
    {
      cout << 1 << endl;
    }

    if (persona2 > persona3 
    && persona2 > persona4
    && persona2 > persona5
    && persona2 > persona1)
    {
      cout << 2 << endl;
    }

    if (persona3 > persona4 
    && persona3 > persona5 
    && persona3 > persona1
    && persona3 > persona2)
    {
      cout << 3 << endl;
    }

    if (persona4 > persona5 
    && persona4 > persona1 
    && persona4 > persona2
    && persona4 > persona3)
    {
      cout << 4 << endl;
    }

    if (persona5 > persona1 
    && persona5 > persona2 
    && persona5 > persona3
    && persona5 > persona4)
    {
      cout << 5 << endl;
    }

  return 0;
}