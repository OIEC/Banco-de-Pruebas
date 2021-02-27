#include <string>
#include <iostream>

using namespace std;
struct Estudiante {
    string nombre;     
    string apellido;     
};


int main() {
    Estudiante e;
    e.nombre = "Juan";
    e.apellido = "Piguave";
    cout << e.nombre << " " << e.apellido << endl;

    Estudiante e2{
        .nombre = "hola",
        .apellido = "mundo",
    };
    // cout << e2.nombre << " " << e2.apellido << end;
    cout << e2.nombre << " " << e2.apellido << endl;

    Estudiante e3[100];
}