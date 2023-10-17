#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, K, M;
  cin >> N >> K >> M;

  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      int color;
      cin >> color;
      cout << color << " ";
    }
    cout << endl;
  }

  return 0;
}