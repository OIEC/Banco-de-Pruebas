#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int len;
  cin >> len;

  int chocolate[len];
  for(int i = 0; i < len; i++)
    cin >> chocolate[i];

  int d;
  int m;
  cin >> d;
  cin >> m;

  if(m > len){
    cout << 0;
    return 0;
  }

  int r = 0;
  int suma = 0;

  for(int i = 0; i < m; i++)
    suma += chocolate[i];
  if(suma == d)
    r++;

  for(int i = m, a = 0; i < len; i++, a++){
    suma += chocolate[i] - chocolate[a];
    if(suma == d)
      r++;
  }
  
  cout << r;

  return 0;
}