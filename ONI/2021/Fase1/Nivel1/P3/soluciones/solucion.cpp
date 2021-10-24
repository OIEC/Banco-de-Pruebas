#include <iostream>

using namespace std;

int main () {
    int a, b, c, d, x;

    cin >> a >> b >> c >> d >> x;

    //revisaremos todos los casos, una vez que encontremos la secuencia correcta, paramos.

    //0 negativos
    if(+a+b+c+d==x){
        cout << "+ + + +";
        return 0;
    }
    
    //1 negativo
    if(+a+b+c-d==x){
        cout << "+ + + -";
        return 0;
    }

    if(+a+b-c+d==x){
        cout << "+ + - +";
        return 0;
    }

    if(+a-b+c+d==x){
        cout << "+ - + +";
        return 0;
    }

    if(-a+b+c+d==x){
        cout << "- + + +";
        return 0;
    }


    //2 negativos
    if(+a+b-c-d==x){
        cout << "+ + - -";
        return 0;
    }
    
    if(+a-b+c-d==x){
        cout << "+ - + -";
        return 0;
    }

    if(-a+b+c-d==x){
        cout << "- + + -";
        return 0;
    }
    
    if(+a-b-c+d==x){
        cout << "+ - - +";
        return 0;
    }

    if(-a+b-c+d==x){
        cout << "- + - +";
        return 0;
    }

    if(-a-b+c+d==x){
        cout << "- - + +";
        return 0;
    }


    //tres negativos
    if(+a-b-c-d==x){
        cout << "+ - - -";
        return 0;
    }
    
    if(-a+b-c-d==x){
        cout << "- + - -";
        return 0;
    }
    
    if(-a-b+c-d==x){
        cout << "- - + -";
        return 0;
    }
    
    if(-a-b-c+d==x){
        cout << "- - - +";
        return 0;
    }

    //4 negativos
    if(-a-b-c-d==x){
        cout << "- - - -";
        return 0;
    }

    cout << "No";

    return 0;
}
