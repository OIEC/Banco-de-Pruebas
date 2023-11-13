#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int coordenada1;
  int coordenada2;
  cin >> coordenada1;
  cin >> coordenada2;

  if ((coordenada1 == 0 && coordenada2 == 0) || (coordenada1 == 1 && coordenada2 == 1))
  {
    cout << -1;
  }
  else if (coordenada1 == 0 && coordenada2 == 1)
  {
    cout << 0 << " " << 0 << endl;
    cout << 1 << " " << 0 << endl;
    cout << 1 << " " << 1;
  }
  else
  {
    cout << 0 << " " << 0 << endl;
    cout << 0 << " " << 1 << endl;
    cout << 1 << " " << 1;
  }
  
  return 0;
}