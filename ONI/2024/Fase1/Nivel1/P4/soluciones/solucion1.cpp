#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  std::string s;
  cin >> s;

  int num = 0;

  if (s[0] == 'I' && s[1] == 'I' && s[2] == 'A')
  {
    num = 2;
  }
  else if (s[0] == 'I' && s[1] == 'A' && s[2] == 'A')
  {
    num = 2;
  }
  else if (s[0] == 'I' && s[1] == 'A')
  {
    num = 1;
  }
  else if (s[0] == 'I' && s[2] == 'A')
  {
    num = 1;
  }
  else if (s[0] != 'I' && s[1] == 'I' && s[2] == 'A')
  {
    num = 1;
  }

  cout << num;

  return 0;
}