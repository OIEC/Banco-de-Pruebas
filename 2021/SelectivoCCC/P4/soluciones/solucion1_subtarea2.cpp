#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double xi, yi;

// Funcion para poder ordenar tomando en cuenta solo la primera columna.
bool sortcol(const vector<double>& v1,
  const vector<double>& v2) {
  return v1[0] < v2[0];
}

// Vector de vectores donde cada vector define un punto.
vector <vector <double>> pendientes_puntos;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cout << fixed;
  for (int i = 0; i < n; i++) {
    cin >> xi >> yi;
    // Obtengo el angulo de la recta desde el origen al punto.
    double angulo = atan(yi / xi);
    // Agrego el valor donde la primera columna es el valor del angulo, el segundo el valor x
    // y el tercero el valor y.
    pendientes_puntos.push_back({ angulo,xi,yi });
  }

  // Ordenamos el vector de vectores con respecto a la primera columna, es decir, con respecto al angulo.
  sort(pendientes_puntos.begin(), pendientes_puntos.end(), sortcol);

  int ubi = (n - 1) / 2;

  // La respuesta es el punto ubicado en la mitad.
  for (int i = 1; i < 3; i++) {
    cout << setprecision(4) << pendientes_puntos[ubi][i] << " ";
  }


}