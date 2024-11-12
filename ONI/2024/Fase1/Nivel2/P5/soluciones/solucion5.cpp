#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// Constante para el módulo
const long long MOD = 1000000000;

// Función para realizar la operación de unión (concatenación)
long long unir_numeros(long long a, long long b) {
    long long potencia = 10;
    while (b >= potencia) {
        potencia *= 10; // Encuentra cuántos dígitos tiene b
    }
    return (a * potencia + b) % MOD; // Concatenar y aplicar módulo
}

long long calcular_resultado(const vector<long long>& numeros, const vector<char>& operaciones) {
    stack<long long> pila_numeros;
    stack<char> pila_operaciones;

    int n = numeros.size();
    // Primer paso: procesar todas las operaciones de unión, ya que tienen la mayor precedencia
    pila_numeros.push(numeros[0]);
    for (int i = 0; i < operaciones.size(); i++) {
        if (operaciones[i] == 'u') {
            long long num1 = pila_numeros.top();
            pila_numeros.pop();
            long long num2 = numeros[i + 1];
            pila_numeros.push(unir_numeros(num1, num2));
        } else {
            pila_numeros.push(numeros[i + 1]);
            pila_operaciones.push(operaciones[i]);  // Solo empujar operaciones que no sean de unión
        }
    }

    // Segundo paso: manejar la multiplicación
    stack<long long> pila_temp_numeros;
    stack<char> pila_temp_operaciones;

    pila_temp_numeros.push(pila_numeros.top());
    pila_numeros.pop();

    while (!pila_operaciones.empty()) {
        char op = pila_operaciones.top();
        pila_operaciones.pop();
        long long num2 = pila_numeros.top();
        pila_numeros.pop();
        long long num1 = pila_temp_numeros.top();
        pila_temp_numeros.pop();

        if (op == 'm') {
            pila_temp_numeros.push((num1 * num2) % MOD);
        } else {
            pila_temp_numeros.push(num1);
            pila_temp_numeros.push(num2);
            pila_temp_operaciones.push(op);
        }
    }

    // Tercer paso: manejar las sumas
    long long resultado = pila_temp_numeros.top();
    pila_temp_numeros.pop();

    while (!pila_temp_operaciones.empty()) {
        char op = pila_temp_operaciones.top();
        pila_temp_operaciones.pop();
        long long num2 = pila_temp_numeros.top();
        pila_temp_numeros.pop();

        if (op == 's') {
            resultado = (resultado + num2) % MOD;
        }
    }

    return resultado;
}

int main() {
    int n;
    cin >> n;

    vector<long long> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    vector<char> operaciones(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> operaciones[i];
    }

    long long resultado = calcular_resultado(numeros, operaciones);
    cout << resultado << endl;

    return 0;
}
