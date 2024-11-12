#include <iostream>

using namespace std;

int main() {
  int num;
  cin >> num;

  num = num * -1; // puede ser num = num - 2 * num;
  if (num > 0)
  {
    cout << '+';
  }
  cout << num;

  return 0;
}