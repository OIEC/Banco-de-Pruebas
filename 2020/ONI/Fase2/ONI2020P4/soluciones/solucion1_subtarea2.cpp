#include<stack>
#include<iostream>
using namespace std; 
  
// Posible representación de un nodo en un árbol binario usando punteros y memoria dinámica.
struct Nodo  
{ 
    string dato; 
    Nodo *izquierda;
    Nodo *derecha; 
}; 
  
// Crea un nuevo nodo usando un string.
Nodo* NuevoNodo(string s) 
{ 
    Nodo* n = new Nodo; 
    n->dato = s; 
    n->izquierda = nullptr;
    n->derecha = nullptr; 
    return n; 
} 

// Crea un nuevo nodo en un árbol usando un caracter.
Nodo* NuevoNodo(char c) 
{ 
    Nodo* n = new Nodo;
    string s = "";
    s+=c;
    n->dato = s; 
    n->izquierda = nullptr;
    n->derecha = nullptr; 
    return n; 
} 

string LeerHastaQueElEnteroTermine(int comienzo, string expr)
{
    int indice = comienzo;
    string num;
    while (indice < expr.length())
    {
        if (isdigit(expr[indice]))
        {
            num+=expr[indice];
            indice++;
        }
        else
        {
            // Llegamos a un caracter que no es un dígito.
            break;
        }
    }
    return num;
}

// Utility function to return the integer value  
// of a given string  
int ConvertirAEntero(string s)  
{  
    int num = 0;  
    for (int i=0; i<s.length(); i++)  
        num = num*10 + (int(s[i])-'0');  
    return num;  
}  
  
// Función para construir un árbol en base a una expresión.
Nodo* ConstruirArbol(string expr) 
{ 
    // Pila de nodos.
    stack<Nodo*> stN; 
  
    // Pila de caracteres.
    stack<char> stC; 
    Nodo *t;
    Nodo *t1;
    Nodo *t2; 
  
    // Priorización de operadores.
    int p[123] = { 0 }; 
    p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p[')'] = 0; 
    
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(') 
        { 
            // Apilar '(' en la pila de caracteres.
            stC.push(expr[i]); 
        } 
  
        // Apilar los operandos en la pila de Nodos.
        else if (isdigit(expr[i]))  
        { 

            string enteroString = LeerHastaQueElEnteroTermine(i, expr);
            i += enteroString.length() - 1;
            t = NuevoNodo(enteroString); 
            stN.push(t); 
            continue;
        } 
        else if (p[expr[i]] > 0)  
        { 
            // Si un operador con prioridad mas baja aparece.
            while (!stC.empty() && stC.top() != '(')
            { 
                // Desapilar el elemento de la pila de caracteres.
                t = NuevoNodo(stC.top()); 
                stC.pop(); 

                // Desapilar el elemento de la pila de Nodos.
                t1 = stN.top(); 
                stN.pop(); 
  
                // Desapilar el elemento de la pila de Nodos.
                t2 = stN.top(); 
                stN.pop(); 
  
                // Actualizar el árbol.
                t->izquierda = t2; 
                t->derecha = t1; 
  
                // Apilar el nodo en la pila de Nodos.
                stN.push(t); 
            } 
  
            // Apilar expr[i] en la pila de caracteres.
            stC.push(expr[i]); 
        } 
        else if (expr[i] == ')') 
        { 
            // Si leemos un paréntesis de cierre,
            // creamos un nuevo nodo en el árbol.
            while (!stC.empty() && stC.top() != '(')  
            { 
                t = NuevoNodo(stC.top()); 
                stC.pop(); 

                t1 = stN.top(); 
                stN.pop(); 

                t2 = stN.top(); 
                stN.pop(); 

                t->izquierda = t2; 
                t->derecha = t1; 

                stN.push(t); 
            } 
            stC.pop(); 
        } 
    } 
    // Retornamos la raíz del árbol.
    t = stN.top(); 
    return t; 
} 
  
// Función evalúa el resultado final dado un árbol.
int EvaluarArbol(Nodo* nodo)  
{  
    // Árbol vacío.
    if (!nodo)  
        return 0;  
  
    // Si tenemos una hoja => tratar como un entero.  
    if (!nodo->izquierda && !nodo->derecha)  
        return ConvertirAEntero(nodo->dato);  
  
    // Evaluar el súbarbol de la izquierda.  
    int l_val = EvaluarArbol(nodo->izquierda);  
  
    // Evaluar el súbarbol de la derecha.
    int r_val = EvaluarArbol(nodo->derecha);  
  
    // Decidir cuál operador se aplica. 
    if (nodo->dato=="+")  
        return l_val+r_val;  
  
    if (nodo->dato=="-")  
        return l_val-r_val;  
  
    if (nodo->dato=="*")  
        return l_val*r_val;  
  
    return l_val/r_val;  
}  

// Esta función asume una suma de productos.
string AnadirParentesisFaltantes(string expr)
{
    // Leer hasta encontrar un signo +. Añadir paréntesis al principio y al final.
    int inicio = 0;
    int final = 0;
    while (inicio < expr.length())
    {
        if (final == expr.length())
        {
            expr.insert(inicio, "(");
            expr.insert(final+1, ")");
            break;
        }
        else if (expr[final] == '+')
        {
            expr.insert(inicio, "(");
            expr.insert(final+1, ")");
            inicio = final+3;
            final+=3;
        }
        else
        {
            final++;
        }
    }
    return expr;
}

// Destruye recursivamente el árbol que se construyó usando memoria dinámica.
void DestruirArbol(Nodo *nodo)
{
    if (nodo != nullptr)
    {
        DestruirArbol(nodo->izquierda);
        DestruirArbol(nodo->derecha);
        delete nodo;
    }
}

int main() 
{ 
    string expr;
    cin >> expr;

    // Determinar si la expresión es del tipo 1 o 2.
    bool tieneParentesis = false;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(')
        {
            tieneParentesis = true;
            break;
        }
    }

    if (!tieneParentesis)
    {
        expr = AnadirParentesisFaltantes(expr);
    }

    expr = "(" + expr; 
    expr += ")"; 
    Nodo* raiz = ConstruirArbol(expr); 
    cout << EvaluarArbol(raiz) << endl;
    DestruirArbol(raiz);
}