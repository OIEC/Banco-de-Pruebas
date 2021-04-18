// Programa simple para entender una lista enlazada.
#include<iostream>
using namespace std; 
  
struct Nodo { 
    int dato; 
    Nodo* next; 
}; 

void ImprimirLista(Nodo* n) 
{ 
    while (n != nullptr) { 
        cout << n->dato << " "; 
        n = n->next; 
    } 
    cout << endl;
} 

int main() 
{ 
    Nodo* primero = nullptr; 
    Nodo* segundo = nullptr; 
    Nodo* tercero = nullptr; 
  
    // crear 3 nodos usando new.
    primero = new Nodo(); 
    segundo = new Nodo(); 
    tercero = new Nodo(); 
  
    primero->dato = 1; // asignar dato in first Nodo 
    primero->next = segundo; // enlazar primer nodo con el segundo 
  
    segundo->dato = 2; // asignar dato to segundo Nodo 
    segundo->next = tercero; 
  
    tercero->dato = 3; // asignar dato to tercero Nodo 
    tercero->next = nullptr; 
  
    ImprimirLista(primero); 
  
    return 0; 
} 