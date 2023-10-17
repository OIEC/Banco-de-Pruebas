#include <iostream>

using namespace std;

int main()
{
   
  int n;
  cin >> n;
  int barras[n];
  for(int i = 0; i < n; i++)
  {
    cin >> barras[i];
  }

  int max_area=0;
  int area=0;
  int l=0;
  int r=n-1;
  while(l < r)
  {
    if(barras[l] > barras[r])
    {
      area=(r-l) * (barras[r]);
    } 
    else
    {
      area=(r-l) * (barras[l]);
    }

    if(area > max_area)
    {
      max_area = area;
    }

    if(barras[l] < barras[r])
    {
      l += 1;
    }
    else
    {
      r -= 1;
    }
  }

  cout << max_area;
}