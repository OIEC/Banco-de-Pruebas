#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<bool> presente (N+1);

  for (int i = 1; i < N+1; ++i)
  {
    presente[i] = false;
  }

  for (int i = 1; i < N+1; ++i)
  {
    int k;
    cin >> k;
    presente[k] = true;
  }

  int indice = 0;
  for (int i = 1; i < N+1; ++i)
  {
    if (!presente[i])
    {
      indice = i;
    }
  }
  cout << indice;

  return 0;
}