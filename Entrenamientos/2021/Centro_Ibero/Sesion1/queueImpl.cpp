// Uso de una cola (Queue)
 
#include<iostream> 
#include<queue>
using namespace std;

int main()
{
   queue<int> cola;
   int accion;
   int val;
   
   while (true)
   {
      cout << "1) Push" << endl;
      cout << "2) Pop" << endl;
      cout << "3) Front" << endl;
      cout << "4) Salir" << endl;
      cin >> accion;
      switch(accion) {
         case 1: {
            cout << "Ingresa el valor a insertar:" << endl;
            cin >> val;
            cola.push(val);
            break;
         }
         case 2: {
            if (cola.size() == 0)
            {
                cout << "La cola está vacía" << endl;
            }
            else
            {
                cola.pop();
            }
            break;
         }
         case 3: {
            if (cola.size() == 0)
            {
                cout << "La cola está vacía" << endl;
            }
            else
            {
                cout << "El frente de la cola es: " << cola.front() << endl;
            }
            break;
         }
         case 4: {
            cout << "Salir" << endl;
            return 0;
            break;
         }
         default: {
            cout << "Acción Inválida" << endl;
         }
      }
   }

    return 0;
}