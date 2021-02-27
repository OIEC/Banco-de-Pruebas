#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  cin >> a >> b >> c;
  int res = 1;
  for (int i = 1; i <= b; i++)
  {
    res *= a;
    res = res % c;
  }
  cout << res;
}