#include<iostream>
using namespace std;
int main ()
{
  int a;
  int b;
  char c;
  cin >> a;
  cin >> b;
  cin >> c;
  
  if (c == '+')
  {
    cout << a + b;
  }
  else if (c == '-')
  {
    cout << a - b;
  }
  else if (c == '*')
  {
    cout << a * b;
  }
  else if (c == '/')
  {
    cout << a / b;
  }
}