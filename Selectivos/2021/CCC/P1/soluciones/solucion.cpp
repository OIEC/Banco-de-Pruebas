#include<iostream>
using namespace std;

int conteo[10];
int tablero[9][9];

void ResetearConteo()
{
	for (int i = 0; i < 10; i++)
	{
		conteo[i] = 0;
	}
}

bool ValidarConteo()
{
	for (int i = 1; i < 10; i++)
	{
		if (conteo[i] > 1)
		{
			return false;
		}
	}
	return true;
}

bool ValidarFilas()
{	
	ResetearConteo();
	for (int i = 0; i < 9; i++)
	{
		ResetearConteo();
		for (int j = 0; j < 9; j++)
		{
			conteo[tablero[i][j]]++;
		}
		if (!ValidarConteo())
		{
			return false;
		}
	} 
	return true;
}

bool ValidarColumnas()
{
	ResetearConteo();
	for (int i = 0; i < 9; i++)
	{
		ResetearConteo();
		for (int j = 0; j < 9; j++)
		{
			conteo[tablero[j][i]]++;
		}
		if (!ValidarConteo())
		{
			return false;
		}
	}
	return true;
}

bool ValidarSubtablero(int inicioX, int inicioY)
{
	ResetearConteo();
	for (int i = inicioX; i < inicioX + 3; i++)
	{
		for (int j = inicioY; j < inicioY + 3; j++)
		{
			conteo[tablero[i][j]]++;
		}
	}
	return ValidarConteo();
}

bool ValidarSubtableros()
{
	// 9 subtableros cuyas coordenadas empiezan en
	// [0,0] [0,3] [0,6]
	// [3,0] [3,3] [3,6]
	// [6,0] [6,3] [6,6]
	for (int i = 0; i < 9; i+=3)
	{
		for (int j = 0; j < 9; j+=3)
		{
			if (!ValidarSubtablero(i, j))
			{
				return false;
			}
		}
	}
	return true;
}

int main ()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> tablero[i][j];
		}
	}

	bool filas = ValidarFilas();
	bool columnas = ValidarColumnas();
	bool subtableros = ValidarSubtableros();

	if (filas && columnas && subtableros)
	{
		cout << "Posible";
	}
	else
	{
		cout << "Imposible";
	}
}