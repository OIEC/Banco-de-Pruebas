#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  for(int d = 1; d < n; d++){
    for(int x = 1; x <= n; x++){
      int sum = d * x + d * (d - 1) / 2;

      if(sum == n){
        for(int i = 0; i < d; i++)
          cout << x + i << " ";
        
          cout << "\n";
      }
    }
  }
}
