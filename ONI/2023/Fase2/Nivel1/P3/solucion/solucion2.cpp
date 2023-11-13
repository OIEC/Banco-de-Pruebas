#include <iostream>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int f1, f2;
  int a1, a2;
  int b1, b2;
  int c1, c2;
  cin >> f1 >> f2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  cin >> c1 >> c2;
  
  // Calculamos las distancias entre cada par de posiciones.
  int distancia_f_a = std::abs(f1-a1) + std::abs(f2-a2);
  int distancia_f_b = std::abs(f1-b1) + std::abs(f2-b2);
  int distancia_f_c = std::abs(f1-c1) + std::abs(f2-c2);
  int distancia_a_b = std::abs(a1-b1) + std::abs(a2-b2);
  int distancia_a_c = std::abs(a1-c1) + std::abs(a2-c2);
  int distancia_b_c = std::abs(b1-c1) + std::abs(b2-c2);

  // Calculamos las distancia total de las 6 posibles rutas.
  int distancia_f_a_b_c = distancia_f_a + distancia_a_b + distancia_b_c;
  int distancia_f_a_c_b = distancia_f_a + distancia_a_c + distancia_b_c;
  int distancia_f_b_a_c = distancia_f_b + distancia_a_b + distancia_a_c;
  int distancia_f_b_c_a = distancia_f_b + distancia_b_c + distancia_a_c;
  int distancia_f_c_a_b = distancia_f_c + distancia_a_c + distancia_a_b;
  int distancia_f_c_b_a = distancia_f_c + distancia_b_c + distancia_a_b;

  // Hallamos la distancia mínima.
  int minima = distancia_f_a_b_c;
  if (distancia_f_a_c_b < minima)
  {
    minima = distancia_f_a_c_b;
  }
  if (distancia_f_b_a_c < minima)
  {
    minima = distancia_f_b_a_c;
  }
  if (distancia_f_b_c_a < minima)
  {
    minima = distancia_f_b_c_a;
  }
  if (distancia_f_c_a_b < minima)
  {
    minima = distancia_f_c_a_b;
  }
  if (distancia_f_c_b_a < minima)
  {
    minima = distancia_f_c_b_a;
  }

  cout << minima * 100;

  return 0;
}