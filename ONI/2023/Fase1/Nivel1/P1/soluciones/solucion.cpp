#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int B;
  int P;
  int H;
  cin >> B;
  cin >> P;
  cin >> H;
  cout << 2*B + P*H;

  return 0;
}