#include <iostream>
using namespace std;

// Regresa el índice del número buscado num, o -1 si no existe en el array.
// Puede usarse unsigned long long si los números son muy grandes.
int BusquedaBinaria(int num, int min, int max, int arr[])
{
	while (min <= max)
	{
		int mid = min + (max - min)/2;

		if (arr[mid] == num)
		{ 
			return mid;
		}

		if (arr[mid] > num)
		{
			max = mid - 1;
		}
		else
		{
			// arr[mid] < num
			min = mid + 1;
		}
	}
	return -1;
}

int main ()
{
	int n;
	int arr[100];
	int num;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> num;

	cout << BusquedaBinaria(num, 0, n-1, arr) << endl;
}