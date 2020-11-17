 #include <iostream>
#include <cmath>
using namespace std;
int a, b; // Defino a como los puntos dentro del triángulo y b los puntos en el perímetro.
float x_1, y_1, x_2, y_2, x_3, y_3, y_temp;
float m_13;


int main() {
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
		// Me aseguro de que y_1 > y_2, caso contrario intercambio sus valores. 
		if (y_2 > y_1) y_temp = y_1, y_1 = y_2, y_2 = y_temp; 
		// Obtengo la pendiente.
		m_13 = (y_1 - y_3) / (x_1 - x_3);
		
		// Realizo un for para todas las coordenadas en x entre x_1 y x_3.
		for (int i = x_3 - 1; i > x_1; i--) {
			// Obtengo el valor de la coordenada en y del punto 
			// que pertenece a la recta con coordenadas x_i
			float max = (i - x_3) * m_13;
			// Si es entero resto este punto del conteo de los puntos
			// internos y lo agrego al de los perímetros.
			if (floorf(max) == max) b++, a--;
			// Agrego la cantidad de puntos internos.
			a += floorf(max);
		}
		// Para calcular el resto de puntos en el perímetro, basta agregar los puntos
		// que están en el eje x y en el eje y, y el origen.
		b += 1 + y_1 + x_3;

	cout << a << " " << b;
}