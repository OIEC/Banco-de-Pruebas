#include <iostream>
using namespace std;
int main() 
{
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, P, Q;
  cin >> N >> P >> Q;
  int res = 0;
  for (int i = 0; i < 15; i++) 
  {
    int p;
    cin >> p;
    if (p % N == 0 && p % P != 0 && p % Q != 0) 
    {
        res++;
    }
  }
  cout << res << endl;

  return 0;
}