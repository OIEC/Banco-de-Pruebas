#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  std::string s;
  cin >> s;

  int num = 0;
  
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] == 'I')
    {
      for (int j = i; j < s.length(); ++j)
      {
        if (s[j] == 'A')
        {
          ++num;
        }
      }
    }
  }
  
  cout << num;
  return 0;
}