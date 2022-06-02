#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int caramelos[n];
    int sabores[n];

    for(int i = 0; i < n; i++){
        sabores[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> caramelos[i];
        sabores[caramelos[i]]++;
    }

    int maxCaramelos = 0;
    for(int i = 0; i < n; i++){
        if(sabores[i] > 0){
            maxCaramelos++;
        }
    }
    maxCaramelos = min(maxCaramelos, n / 2);

    cout << maxCaramelos;
}