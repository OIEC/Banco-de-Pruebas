#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  char c[10];
  for (int i = 0; i < 10; ++i)
  {
    cin >> c[i];
  }

  if (c[9] == '5' || c[9] == '9' || c[9] == '3')
  {
    cout << "Si";
  }
  else
  {
    cout << "No";
  }

  return 0;
}