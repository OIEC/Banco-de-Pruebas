#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    for(int i=0; i<a;i++){
        cout << 'O';
    }
    for(int i=0; i<b;i++){
        cout << 'I';
    }
    for(int i=0; i<c;i++){
        cout << 'E';
    }
    for(int i=0; i<d;i++){
        cout << 'C';
    }
    for(int i=0; i<e;i++){
        cout << '!';
    }

    return 0;
}

