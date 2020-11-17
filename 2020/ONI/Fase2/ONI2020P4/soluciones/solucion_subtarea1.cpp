#include <iostream>
#include <string> 
using namespace std;

int main() 
{
  string expr;
  cin >> expr;
  int resFinal= 0;
  int prodTemp = 1; 
  string numStr;              
  int num;                  
  bool prodPresente = false;

  for (int i = 0; i < expr.length(); i++)
  {
    if (expr[i] == '+')
    {
      if (prodPresente)
      {
        // Si hay un producto presente, le acumulamos el número que se esté leyendo.
        // Además acumulamos el producto en el resultado final.
        prodTemp *= num;
        resFinal += prodTemp;
      }
      else
      {
        // Si no hay un producto, acumulamos el número en el resultado final.
        resFinal += num;
      }
      // Reseteamos el número que se esté leyendo y no hay producto presente.
      numStr="";
      num = 0;
      prodPresente = false;
      prodTemp = 1;
    }
    else if (expr[i] == '*')
    {
      // Si vemos un producto, guardamos este estado y lo acumulamos en prodTemp.
      prodPresente = true;
      prodTemp *= num;
      // Reseteamos el número actual para leer uno nuevo.
      numStr = "";
      num = 0;
    }
    else if (isdigit(expr[i]))
    {
      // Si es un dígito en forma de caracter, lo acumulamos en el string y convertimos el resultado a int.
      numStr += expr[i];
      num = stoi(numStr);
    }
    else
    {
      // Si leemos cualquier otro caracter, reseteamos el numStr para no desbordar num.
      numStr = "";
    }
  }


  // Una vez leída la expresión, acumulamos el último número leído de igual forma.
  if (prodPresente)
  {
    prodTemp *= num;
    resFinal += prodTemp;
  }
  else
  {
    // Si no hay un producto acumulamos el número leído en la suma.
    resFinal += num;
  }

  cout << resFinal;
}