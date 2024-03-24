#include <iostream>

using namespace std;
#define ull unsigned long long

ull ResolverRecursivamente(ull N)
{
    if (N == 1) return 1;

    ull numArboles = 0;
    for (ull k = 2; k <= N; ++k)
    {
       numArboles += ResolverRecursivamente(N/k);
    }
    return numArboles;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ull N;
  cin >> N;
  cout << ResolverRecursivamente(N);

  return 0;
}