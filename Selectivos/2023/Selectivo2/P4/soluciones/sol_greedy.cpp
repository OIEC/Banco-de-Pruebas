#include <iostream>
#include <string>
using namespace std;

int main(){
    int casos;
    cin >> casos;

    for(int i=0; i < casos; ++i)
    {
        int n;
        cin >> n;
        int pasos = 0;

        while(n>0)
        {
            string num = to_string(n);
            int mayor = 0;
            for(char c : num){
                if(c - '0' > mayor){
                    mayor = c - '0';
                }
            }
            n -= mayor;
            pasos ++;
        }
        cout << pasos << ' ';
    }
}