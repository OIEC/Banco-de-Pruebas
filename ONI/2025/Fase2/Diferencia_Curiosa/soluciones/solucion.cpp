#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int imparMasGrande = -1;
  int parMasPequeno = 2026;

  for (int i = 0; i < N; ++i)
  {
    int k; 
    cin >> k;
    if ((k % 2 == 0) && (k < parMasPequeno))
    {
      parMasPequeno = k;
    }
    if ((k%2==1) && (k > imparMasGrande))
    {
      imparMasGrande = k;
    }
  }
  cout << imparMasGrande - parMasPequeno;

  return 0;
}