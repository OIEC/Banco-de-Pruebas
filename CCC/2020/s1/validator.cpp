#include <iostream>
#include <fstream>

int main() {
  double expected_output;
  {
    std::ifstream salida_original("data.out", std::ifstream::in);
    salida_original >> expected_output;
  }

  double salida_concursante;
  if (!(std::cin >> salida_concursante)) {
    std::cerr << "Error leyendo la salida del concursante\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  // determina si la respuesta es incorrecta.
  if (!((salida_concursante - expected_output < expected_output * 0.00001) && (salida_concursante - expected_output > expected_output * -0.00001))) {
    std::cerr << "Salida incorrecta\n";
    std::cout << 0.0 << '\n';
    return 0;
  }

  // Si la ejecución llega hasta aquí, la salida del concursante es correcta.
  std::cout << 1.0 << '\n';
  return 0;
}
