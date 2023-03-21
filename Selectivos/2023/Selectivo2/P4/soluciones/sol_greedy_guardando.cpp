#include <iostream>
#include <string>
using namespace std;

int main(){
    const int limite = 100000;
    int pasos[limite + 1];
    pasos[0] = 0;

    for(int i=1; i <= limite; ++i)
    {
        string num = to_string(i);
        int mayor = 0;
        for(char c : num)
        {
            if(c - '0' > mayor)
            {
                mayor = c - '0';
            }
        }
        pasos[i] = 1 + pasos[i-mayor];
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        cout << pasos[n] << " ";
    }
}