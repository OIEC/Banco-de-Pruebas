#include<iostream>
#include<vector>
using namespace std;

// Función que evalúa si un caracter es un dígito.
bool esDigito(char c){
	if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

// Función que evalúa si un caracter es un operador.
bool esOperador(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}

// Función que convierte de char a int.
int charToInt(char c){
	return (c - '0');
}

// Función que convierte de string a int.
int stringToInt(string s){
    int number = 0;
	int potencia10 = 1;

    for (int i = s.length() - 1; i >= 0; i--) {
        number += charToInt(s[i]) * potencia10;
		potencia10 *= 10;
    }

    return number;
}

// Función que analiza el string ingresado y añade los números y operadores a cada vector.
void analizarString(string s, vector<int>& numeros, vector<int>& operadores){
	int actual = 0;			// Variable para navegar a través del string.
	int inicio = 0;			// Variable que toma el valor de "actual" al principio del loop.

	while(actual < s.length()){
		char c = s[actual];

		// Revisar si el caracter en la posición "actual" del string es un operador o un dígito para asignarlo al respectivo vector.
		if(esOperador(c)){
			operadores.push_back(actual);
			actual++;
		}
		else if(esDigito(c)){
			// Si "c" es un dígito, se navega hasta el último dígito del número formado, o sea, hasta antes del siguiente operador.
			while(esDigito(s[actual]) && actual < s.length())
				actual++;

			// Se almacena dicho número en un string vacío para luego convertirlo en int usando la función stringToInt.
			string num = "";
			for(int i = inicio; i < actual; i++)
				num += s[i];

			numeros.push_back(stringToInt(num));
		}
		else{
			// Si es un paréntesis, se avanza al siguiente caracter.
			actual++;
		}
		
		inicio = actual;		// Update a "inicio" antes de volver al loop.
	}
}

// Función que calcula la operación entre dos números x, y dado el operador entre ellos.
int calcularOperacion(char op, int x, int y){
	if(op == '/')
		return x / y;
	if(op == '*')
		return x * y;
	if(op == '-')
		return x - y;
	if(op == '+')
		return x + y;
}

// Función que realiza una operación dada dentro de un paréntesis y guarda los cambios en los vectores numeros y operadores.
void operacionEnParentesis(string s, char operacion, vector<int>& numeros, vector<int>& operadores, int inicio, int fin){
	// Se navega a través de los operadores para realizar las debidas operaciones.
	for(int i = 0; i < operadores.size(); i++){
		// Se realizan la operación indicada dentro de los límites "inicio" y "fin" dados por la función.
		if(operadores.at(i) > inicio && operadores.at(i) < fin){
			if(s[operadores.at(i)] == operacion){
				int res = calcularOperacion(operacion, numeros.at(i), numeros.at(i + 1));	// Se calcula el resultado de la operación.
				operadores.erase(operadores.begin() + i);					// Se borra el operador que acaba de ser usado. 
				numeros.erase(numeros.begin() + i);								
				numeros.erase(numeros.begin() + i);						// Se borran los dos números que se usaron para la operación.
				numeros.insert(numeros.begin() + i, res);					// Se añade el resultado de la operación en la debida posición.

				// Como se borra un operador en esta operación, se resta uno a la variable de navegación.
				i--;		
			}
		}
	}
}

// Función que calcula el resultado de la operación dentro de un paréntesis dado el índice de inicio y fin de donde se quiere realizar la operación.
void resultadoEnParentesis(string s, vector<int>& numeros, vector<int>& operadores, int inicio, int fin){
	int numOperadores = 1;			// Contador de operadores dentro de los límites dados.

	// Se realizan operaciones hasta que ya no hayan operadores dentro del paréntesis.
	while(numOperadores != 0){
		numOperadores = 0;

		for (int i = inicio; i < fin; i++) {
            for (int opC = 0; opC < operadores.size(); opC++) {
                if (operadores.at(opC) == i)
                    numOperadores++;
            }
        }
		
	// Se realizan las operaciones respetando la jerarquía.		
        operacionEnParentesis(s, '/', numeros, operadores, inicio, fin);
        operacionEnParentesis(s, '*', numeros, operadores, inicio, fin);
        operacionEnParentesis(s, '-', numeros, operadores, inicio, fin);
        operacionEnParentesis(s, '+', numeros, operadores, inicio, fin);
	}


}

// Función que analiza un string y realiza las operaciones dentro de los paréntesis.
void revisarParentesis(string s, vector<int>& numeros, vector<int>& operadores){
	for(int i = 0; i < s.length(); i++){
		int aperturaCount = 0;
		int clausuraCount = 0;

		// Buscar el primer paréntesis de clausura.
		if(s[i] == ')'){
			int j;

			// For loop para encontrar el respectivo paréntesis de apertura.
			// Se cuenta cada vez que un paréntesis se abre y se cierra.
			// Se rompe el loop una vez que la cantidad de paréntesis abiertos y cerrados son iguales.
			for(j = i; j > 0; j--){
				if(s[j] == '(')
					aperturaCount++;
				if(s[j] == ')')
					clausuraCount++;
				if(clausuraCount == aperturaCount)
					break;
			}

			// Una vez hallado un par de paréntesis, se calcula el resultado de la operación dentro del mismo.
			resultadoEnParentesis(s, numeros, operadores, j, i);
		}
	}
}

// Función que calcula el resultado final de la expresión.
void resultado(string s, vector<int>& numeros, vector<int>& operadores){
    // Realizar operaciones hasta que solo haya un número en el vector "numeros" respetando la jerarquía de operaciones.
    while (numeros.size() != 1) {
        operacionEnParentesis(s, '/', numeros, operadores, 0, s.length());
        operacionEnParentesis(s, '*', numeros, operadores, 0, s.length());
        operacionEnParentesis(s, '-', numeros, operadores, 0, s.length());
        operacionEnParentesis(s, '+', numeros, operadores, 0, s.length());
    }
}

int main(){
	string s;
	vector<int> operadores;
	vector<int> numeros;

	cin >> s;

	analizarString(s, numeros, operadores);
	revisarParentesis(s, numeros, operadores);
	resultado(s, numeros, operadores);

	cout << numeros[0];
}
