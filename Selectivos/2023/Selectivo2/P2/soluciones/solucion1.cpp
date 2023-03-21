#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int power = pow(a,b);
  int res = power % c;
  cout << res;
}