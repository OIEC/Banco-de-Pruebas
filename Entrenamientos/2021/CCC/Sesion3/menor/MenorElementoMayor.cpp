#include <iostream>
using namespace std;

// Regresa el índice del menor elemento mayor al número num.
// En caso de no existir (el número es mayor que todos), regresa -1.
// El elemento num no debe existir en el arreglo. Si esto no se cumple,
// podemos correr búsqueda binaria normal para verificarlo.
int MenorElementoMayor(int num, int min, int max, int arr[])
{
	if (num > arr[max]) return -1;

	while (min <= max)
	{
		int mid = min + (max - min)/2;

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

	return min;
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

	cout << MenorElementoMayor(num, 0, n-1, arr) << endl;
}