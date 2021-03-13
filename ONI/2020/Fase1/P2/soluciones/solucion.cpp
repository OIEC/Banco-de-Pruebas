#include<iostream>
using namespace std;
int main ()
{
  string str;
  cin >> str;
  int apertura = 0;
  int cierre = 0;
  bool noBalanceada = false;
  
  for (int i = 0; i < str.length(); i++)
  {
    if (str.at(i) == '(')
    {
      apertura++;
    }
    else
    {
      cierre++;
    }

    if (cierre > apertura)
    {
      noBalanceada = true;
    }
  }
  
  cout << apertura << endl;
  
  if (noBalanceada == true)
  {
    cout << "No balanceada";
  }
  else if (apertura == cierre)
  {
    cout << "Balanceada";
  }
  else
  {
    cout << "No balanceada";
  }
}