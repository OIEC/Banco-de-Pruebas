#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    if (a1 < 90 && a2 < 90 && a3 < 90)
    {
      cout << "ACUTANGULO" << endl;
    }

    if (a1 > 90 || a2 > 90 || a3 > 90)
    {
      cout << "OBTUSANGULO" << endl;
    }

    if (a1 == 90 || a2 == 90 || a3 == 90)
    {
      cout << "RECTANGULO" << endl;
    } 
  }

  return 0;
}