#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;

  if ((n1 > n2 && n1 < n3) || (n1 > n3 && n1 < n2))
  {
    cout << n1;
  }

  if ((n2 > n1 && n2 < n3) || (n2 > n3 && n2 < n1))
  {
    cout << n2;
  }

  if ((n3 > n1 && n3 < n2) || (n3 > n2 && n3 < n1))
  {
    cout << n3;
  }

  return 0;
}