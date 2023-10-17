#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  char tablero[3][3];

  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      cin >> tablero[i][j];
    }
  }

  // X gana en la diagonal de la esquina superior izquierda.
  if ((tablero[0][0] == tablero[1][1]) && (tablero[1][1] == tablero[2][2]) && (tablero[2][2] == 'X'))
  {
    cout << "X";
  }

  // X gana en la diagonal de la esquina superior derecha.
  if ((tablero[0][2] == tablero[1][1]) && (tablero[1][1] == tablero[2][0]) && (tablero[2][0] == 'X'))
  {
    cout << "X";
  }

  // O gana en la diagonal de la esquina superior izquierda.
  if ((tablero[0][0] == tablero[1][1]) && (tablero[1][1] == tablero[2][2]) && (tablero[2][2] == 'O'))
  {
    cout << "O";
  }

  // O gana en la diagonal de la esquina superior derecha.
  if ((tablero[0][2] == tablero[1][1]) && (tablero[1][1] == tablero[2][0]) && (tablero[2][0] == 'O'))
  {
    cout << "O";
  }

  return 0;
}