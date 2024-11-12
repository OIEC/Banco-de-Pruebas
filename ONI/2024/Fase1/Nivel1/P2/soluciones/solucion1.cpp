#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  char palabra[5];
  cin >> palabra;

  bool cumple = false;
  if ((palabra[0] == 'A' || palabra[0] == 'E' 
  || palabra[0] == 'I' || palabra[0] == 'O' ||
  palabra[0] == 'U') && 
  (palabra[1] == 'A' || palabra[1] == 'E' 
  || palabra[1] == 'I' || palabra[1] == 'O' ||
  palabra[1] == 'U') &&
  (palabra[2] == 'A' || palabra[2] == 'E' 
  || palabra[2] == 'I' || palabra[2] == 'O' ||
  palabra[2] == 'U'))
  {
    cumple = true;
  }

  if ((palabra[1] == 'A' || palabra[1] == 'E' 
  || palabra[1] == 'I' || palabra[1] == 'O' ||
  palabra[1] == 'U') && 
  (palabra[2] == 'A' || palabra[2] == 'E' 
  || palabra[2] == 'I' || palabra[2] == 'O' ||
  palabra[2] == 'U') &&
  (palabra[3] == 'A' || palabra[3] == 'E' 
  || palabra[3] == 'I' || palabra[3] == 'O' ||
  palabra[3] == 'U'))
  {
    cumple = true;
  }

  if ((palabra[2] == 'A' || palabra[2] == 'E' 
  || palabra[2] == 'I' || palabra[2] == 'O' ||
  palabra[2] == 'U') && 
  (palabra[3] == 'A' || palabra[3] == 'E' 
  || palabra[3] == 'I' || palabra[3] == 'O' ||
  palabra[3] == 'U') &&
  (palabra[4] == 'A' || palabra[4] == 'E' 
  || palabra[4] == 'I' || palabra[4] == 'O' ||
  palabra[4] == 'U'))
  {
    cumple = true;
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