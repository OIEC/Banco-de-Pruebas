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

  int max_area = 0;
  for(int i = 0; i < n-1; i++)
  {
    for(int j=i+1; j < n; j++)
    {
      int area = 0;
      if(barras[i]>barras[j])
      {
        area=(j-i) * (barras[j]);
      } 
      else
      {
        area=(j-i) * (barras[i]);
      }

      if(area > max_area)
      {
        max_area = area;
      }
    }
  }

  cout << max_area;
  return 0;
    
}