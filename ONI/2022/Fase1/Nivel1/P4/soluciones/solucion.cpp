#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int personas[7];
  cin>>personas[1];
  cin>>personas[2];
  cin>>personas[3];
  cin>>personas[4];
  cin>>personas[5];
  cin>>personas[6];

  int empezarReparticion;
  cin >> empezarReparticion;

  int conteoPanesPersona1 = 0;
  int siguientePersona = empezarReparticion;
  for (int i = 0; i < 15; ++i)
  {
    if (siguientePersona == 1) 
    {
      conteoPanesPersona1++;
    }
    siguientePersona = personas[siguientePersona];
  }
  cout << conteoPanesPersona1;

  return 0;
}