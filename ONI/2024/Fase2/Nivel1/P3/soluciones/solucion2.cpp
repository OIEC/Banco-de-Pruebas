#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> vec(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  cout << vec[N-2];
  

  return 0;
}