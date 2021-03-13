#include<algorithm>
#include<iostream>
using namespace std;
int main () {
  std::string s1;
  std::string s2;
  cin >> s1;
  cin >> s2;	
  int ans = 0;
  if (s1.size() != s2.size())
  {
    cout << ans;
  }
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  if(s1 == s2)
  {
    ans = 1;
  }
  cout << ans;
}