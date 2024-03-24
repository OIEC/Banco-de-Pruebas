#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
#define ull unsigned long long

ull ResolverRecursivamente(ull N, unordered_map<ull, ull>& A)
{
    if (A.find(N) != A.end())
    {
        return A[N];
    }

    ull numArboles = 0;
     for (ull k = 1; k <= floor(sqrt(N)); ++k)
    {
        ull count = (N/k) - (N/(k+1));
        numArboles += count * ResolverRecursivamente(k, A);
    }

    for (ull k = 2;  N/k > floor(sqrt(N)); ++k)
    {
        numArboles += ResolverRecursivamente(N/k, A);
    }
    A[N] = numArboles;
    
    return numArboles;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ull N;
  cin >> N;

  unordered_map<ull, ull> A;
  A[1] = 1;   

  cout << ResolverRecursivamente(N, A);

  return 0;
}