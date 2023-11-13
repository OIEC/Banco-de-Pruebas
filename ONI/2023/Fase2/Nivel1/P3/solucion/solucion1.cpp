#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int f1, f2;
  int a1, a2;
  int b1, b2;
  int c1, c2;
  cin >> f1 >> f2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  cin >> c1 >> c2;
  
  cout << (c2 - f2) * 100;

  return 0;
}