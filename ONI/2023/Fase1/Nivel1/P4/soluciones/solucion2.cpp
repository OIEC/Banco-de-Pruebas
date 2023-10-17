#include <iostream>

using namespace std;

int S[10];

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  int k;
  cin >> N;
  cin >> k;

  for (int i = 0; i < N; ++i)
  {
    S[i] = 0;
  }

  // primera línea
  for (int i = 0; i < N; ++i)
  {
    cout << S[i] << " ";
  }
  cout << endl;

  // desde k hasta N-1
  for (int i = k; i < N; ++i)
  {
    S[i] = 1;
    for (int j = 0; j < N; ++j)
    {
      cout << S[j] << " ";
    }
    cout << endl;
    S[i] = 0;
  }

  // desde 0 hasta k-1
  for (int i = 0; i < k; ++i)
  {
    S[i] = 1;
    for (int j = 0; j < N; ++j)
    {
      cout << S[j] << " ";
    }
    cout << endl;
    S[i] = 0;
  }

  // última línea
  for (int i = 0; i < N; ++i)
  {
    cout << 0 << " ";
  }
  cout << endl;

  return 0;
}