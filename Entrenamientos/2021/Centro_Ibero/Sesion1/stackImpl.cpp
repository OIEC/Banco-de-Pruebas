// Uso de una pila (Stack)
 
#include<iostream> 
#include<stack>
using namespace std;

int main()
{
   stack<int> pila;
   int accion;
   int val;
   
   while (true)
   {
      cout << "1) Push" << endl;
      cout << "2) Pop" << endl;
      cout << "3) Top" << endl;
      cout << "4) Salir" << endl;
      cin >> accion;
      switch(accion) {
         case 1: {
            cout << "Ingresa el valor a insertar:" << endl;
            cin >> val;
            pila.push(val);
            break;
         }
         case 2: {
            /*
            if (pila.size() == 0)
            {
                cout << "La pila está vacía" << endl;
            }
            else
            {*/
                pila.pop();
            //}
            break;
         }
         case 3: {
            /*
            if (pila.size() == 0)
            {
                cout << "La pila está vacía" << endl;
            }
            else
            { */
                cout << "El tope de la pila es: " << pila.top() << endl;
            //}
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