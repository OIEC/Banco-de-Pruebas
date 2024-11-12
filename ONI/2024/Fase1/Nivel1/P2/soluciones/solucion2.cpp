#include <iostream>
#include <string>

using namespace std;

bool EsVocal(char c)
{
  return  (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  string palabra;
  cin >> palabra;

  bool cumple = false;
  for (int i = 0; i < N-2; ++i)
  {
    if (EsVocal(palabra[i]) && EsVocal(palabra[i+1]) && EsVocal(palabra[i+2]))
    {
      cumple = true;
    }
  }
 
  if (cumple == true)
  {
    cout << "SI";
  }
  else
  {
    cout << "NO";
  }

  return 0;
}