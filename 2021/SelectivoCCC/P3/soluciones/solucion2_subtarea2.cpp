#include<iostream>
#include<algorithm>
using namespace std;

int nums[2500];

int main ()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {	
		int num;
    cin >> num;
    nums[i] = num;
  }

  sort(nums, nums+n);

  int count = 0;

  for (int i = n - 1; i >= 1; i--) { 
		int l = 0, r = i - 1;
    while (l < r) { 
			//Chequeamos la desigualdad triangular
			if (nums[l] + nums[r] > nums[i]) { 
				//Si es posible para nums[i], nums[j] y nums[i]
				//también es posible para cualquier número entre
				//ellos, es decir: a[l+1]..a[r-1], a[r] y a[i]
				count += r - l; 
				
				//Decrementamos r para seguir buscando soluciones
				r--; 
			} 
			else
				//Si no se cumple la desigualdad, buscamos para
				//mayores valores de l
				l++; 
		} 
  }

  cout << count;
}
