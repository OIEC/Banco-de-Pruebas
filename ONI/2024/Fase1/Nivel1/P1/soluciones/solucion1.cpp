#include <iostream>

using namespace std;

int main() {
  char signo;
  char num;
  cin >> signo;
  cin >> num;

  if (signo == '+')
  {
    cout << '-';
  }
  else
  {
    cout << '+';
  }
  cout << num;

  return 0;
}