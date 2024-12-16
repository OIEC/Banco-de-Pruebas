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
  int max = 0;
  for (int i = 0; i < N; ++i)
  {
    cin >> vec[i];
    if (vec[i] > max)
    {
      max = vec[i];
    }
  }

  int segMax = 0;
  for (int i = 0; i < N; ++i)
  {
    if (vec[i] != max && vec[i] > segMax)
    {
      segMax = vec[i];
    }
  }

  cout << segMax;
 
  return 0;
}