#include <iostream>
#include <cmath>
using namespace std;
int a, b; // Defino a como los puntos dentro del triángulo y b los puntos en el perímetro.
float x_1, y_1, x_2, y_2, x_3, y_3, y_temp;
float m_12, m_13, m_23;


int main() {
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
	// Separo el proceso en los tres casos definidos.
	// El primer caso x_1 = x_2 < x_3
	if (x_1 == x_2) {
		// Me aseguro de que y_1 > y_2, caso contrario intercambio sus valores. 
		if (y_2 > y_1) y_temp = y_1, y_1 = y_2, y_2 = y_temp; 
		// Como x_1 = x_2 entonces m_12 es infinito y no lo calculo, las demás pendientes
		// si las calculo.
		m_13 = (y_1 - y_3) / (x_1 - x_3);
		m_23 = (y_2 - y_3) / (x_2 - x_3);
		// Realizo un for para todas las coordenadas en x entre x_1 y x_3.
		for (int i = x_3 - 1; i > x_1; i--) {
			//Obtengo 
			float max = (i - x_3) * m_13 + y_1;
			float min = (i - x_3) * m_23 + y_1;
			// Si el lado superior del triángulo pasa por un punto de coordenadas enteras
			// lo agrego al contador de puntos en el perímetro y lo quito de los puntos
			// dentro del triángulo.
			if (floorf(max) == max) b++, a--;
			// Si el lado inferior del triángulo pasa por un punto de coordenadas enteras
			// lo agrego al contador de puntos en el perímetro.
			if (floorf(min) == min) b++;
			// Los puntos dentro del triángulo son la resta del entero máximo y mínimo.
			a += floorf(max) - floorf(min);
		}
		// Agrego los puntos en el perímetro que estan en el lado con pendiente infinita.
		b = b + 2 + y_1 - y_2;

	}
	// El segundo caso x_1 < x_2 = x_3
	else if (x_2 == x_3) {
		// Me aseguro de que y_3 > y_2, caso contrario intercambio sus valores.
		if (y_2 > y_3) y_temp = y_3, y_3 = y_2, y_2 = y_temp;
		// En este caso m_23 es infinito y no lo calculo.
		m_13 = (y_1 - y_3) / (x_1 - x_3);
		m_12 = (y_1 - y_2) / (x_1 - x_2);
		for (int i = x_1 + 1; i < x_2; i++) {
			float max = (i - x_1) * m_13 + y_1;
			float min = (i - x_1) * m_12 + y_1;
			if (floorf(max) == max) b++, a--;
			if (floorf(min) == min) b++;
			a += floorf(max) - floorf(min);
		}
		b = b + 2 + y_3 - y_2;
	}
	// El tercer caso x_1 < x_2 < x_3
	else {
		m_13 = (y_1 - y_3) / (x_1 - x_3);
		m_23 = (y_2 - y_3) / (x_2 - x_3);
		m_12 = (y_1 - y_2) / (x_1 - x_2);

		// El primer subcaso del tercer caso, cuando P_2 esta abajo del segmento P_1-P_3.
		if (m_13 > m_12) {
			// El primer for, desde x1 hasta x2 inclusive.
			for (int i = x_1 + 1; i <= x_2; i++) {
				float max = (i - x_1) * m_13 + y_1;
				float min = (i - x_1) * m_12 + y_1;
				if (floorf(max) == max) b++, a--;
				if (floorf(min) == min) b++;
				a += floorf(max) - floorf(min);
			}			
			// El segundo for, desde x2 hasta x3.
			for (int i = x_2 + 1; i < x_3; i++) {
				float max = (i - x_1) * m_13 + y_1;
				float min = (i - x_2) * m_23 + y_2;
				if(floorf(max) == max) b++, a--;
				if (floorf(min) == min) b++;
				a += floorf(max) - floorf(min);
			}
			
		}
		// El segundo subcaso del tercer caso, cuando P_2 esta arriba del segmento P_1-P_3.
		else {
			for (int i = x_1 + 1; i <= x_2; i++) {
				float min = (i - x_1) * m_13 + y_1;
				float max = (i - x_1) * m_12 + y_1;
				if (floorf(max) == max) b++, a--;
				if (floorf(min) == min) b++;
				a += floorf(max) - floorf(min);
			}

			for (int i = x_2 + 1; i < x_3; i++) {
				float min = (i - x_1) * m_13 + y_1;
				float max = (i - x_2) * m_23 + y_2;
				if (floorf(max) == max) b++, a--;
				if (floorf(min) == min) b++;
				a += floorf(max) - floorf(min);
			}

		}
		b = b + 2;
	}
	cout << a << " " << b;
}