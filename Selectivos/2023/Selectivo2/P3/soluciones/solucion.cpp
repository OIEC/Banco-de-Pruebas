#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<char, int> conteos;
    for(int i=0; i<n; i++)
    {
        char c;
        cin >> c;
        conteos[c] = conteos[c] + 1;
    }

    int conteoImpar = 0;
    for(pair<char, int> par : conteos)
    {
        if(par.second % 2 != 0)
        {
            ++conteoImpar;
        }
    }

    if(conteoImpar <= 1)
    {
      cout << "SI";
    }
    else
    {
      cout << "NO";
    }
    return 0;
}