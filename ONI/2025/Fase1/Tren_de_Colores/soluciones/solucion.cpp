#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N=20, r=0,a=0,z=0;
  string tren_de_colores;
  cin >> tren_de_colores;
  
  for (int i =0; i<tren_de_colores.size(); i++){
    if (tren_de_colores[i] == 'R'){
      r++;
    }
    else if (tren_de_colores[i]=='A'){
      a++;
    }
    else{
      z++;
    }
    
  }
  cout << N-max(r,max(a,z));

}