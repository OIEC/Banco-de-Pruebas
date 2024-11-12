#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Inicializa los números y los contadores
    int primer_numero = -1; // Almacena el primer número, inicializado a -1. Sabemos que las entradas serán números positivos, por lo que -1 indica que aún no se ha asignado valor.
    int segundo_numero = -1; // Almacena el segundo número, también inicializado a -1.
    long long cuenta_primer_numero = 0; // Contador para el primer número
    long long cuenta_segundo_numero = 0; // Contador para el segundo número

    int numero_entrante;
    // Procesa las entradas de números
    for (int i = 0; i < n; i++) {
        cin >> numero_entrante; // Lee el número entrante
        
        // Si no se ha asignado valor a 'primer_numero' o el número entrante coincide con 'primer_numero'
        if (primer_numero == -1 || numero_entrante == primer_numero) {
            primer_numero = numero_entrante; // Asigna o mantiene el valor de 'primer_numero'
            cuenta_primer_numero++; // Incrementa el contador para 'primer_numero'
        } 
        // Si no se ha asignado valor a 'segundo_numero' o el número entrante coincide con 'segundo_numero'
        else if (segundo_numero == -1 || numero_entrante == segundo_numero) {
            segundo_numero = numero_entrante; // Asigna o mantiene el valor de 'segundo_numero'
            cuenta_segundo_numero++; // Incrementa el contador para 'segundo_numero'
        }
    }

    // Procesa el número de consultas (máximo 10 consultas)
    int m;
    cin >> m;

    // Responde a cada consulta
    for (int i = 0; i < m; i++) {
        int pregunta;
        cin >> pregunta; // Lee la consulta
        
        // Si la consulta pregunta por 'primer_numero'
        if (pregunta == primer_numero) {
            cout << cuenta_primer_numero << endl; // Imprime cuántas veces apareció 'primer_numero'
        } 
        // Si la consulta pregunta por 'segundo_numero'
        else if (pregunta == segundo_numero) {
            cout << cuenta_segundo_numero << endl; // Imprime cuántas veces apareció 'segundo_numero'
        } 
        // Si la consulta no corresponde a ninguno de los dos números
        else {
            cout << 0 << endl; // Imprime 0 si el número consultado no coincide con los dos principales
        }
    }

    return 0;
}
