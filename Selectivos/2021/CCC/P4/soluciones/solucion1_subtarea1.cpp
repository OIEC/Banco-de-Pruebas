#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int n, pos, p;
double xi, yi;

// Funcion para calcular el producto cruz.
double prod(double x_1, double y_1, double x_2, double y_2 ) {
    return x_1 * y_2 - x_2 * y_1;
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
        pendientes_puntos.push_back({ xi,yi });
    }

    for (int i = 0; i < n; i++) {
        // Valor para contar cuanto puntos dan el producto cruz positivo.
        pos = 0;
        for (int j = 0; j < n; j++) {
            double cruz = prod(pendientes_puntos[i][0], pendientes_puntos[i][1], pendientes_puntos[j][0], pendientes_puntos[j][1]);
            if (cruz > 0) pos++;
        }
        // Si este valor es el piso de n/2, entonces este es el punto a buscar.
        if (pos == n / 2) {
            cout << setprecision(4) << pendientes_puntos[i][0] << " " << pendientes_puntos[i][1]; 
            break;
        }
    }

}
