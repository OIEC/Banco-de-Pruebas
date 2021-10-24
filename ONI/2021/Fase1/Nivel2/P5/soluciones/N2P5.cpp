#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int residuos[k];
  for(int i = 0; i < k; i++)
    residuos[i] = 0;

  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    residuos[num % k]++;
  }
  
  int M = 0;
  
  if(residuos[0] > 0){
      M++;
  }

  for(int i = 1; i <= k / 2; i++){
      if(k % 2 == 0 && i == k / 2){
        if(residuos[i] > 0)
          M++;
      }
      else
        M += max(residuos[i], residuos[k - i]);
  }
  
  cout << M;

  return 0;
}