#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ull N;
  cin >> N;

  std::vector<ull> A(N+1, 0);
  A[1] = 1;

  for (ull n = 2; n <= N; ++n)
  {
    ull numArboles = 0;
    for (ull k = 2; k <= n; ++k)
    {
      numArboles += A[n/k];
    }
    A[n] = numArboles;
  }

  cout << A[N];

  return 0;
}