#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  std::vector<int> arr(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> arr[i];
  }

  std::sort(arr.begin(), arr.end());

  double minimo = 1000000000000.0;
  for(int i = 1; i < N - 1 ; i++)
  {
    double izquierda = (arr[i] - arr[i-1]) / 2.0;
    double derecha = (arr[i+1] - arr[i]) / 2.0;
    if(izquierda + derecha < minimo)
    {
        minimo = izquierda + derecha;
    }
  }
  printf("%.1f\n", minimo); 
 
  return 0;
}