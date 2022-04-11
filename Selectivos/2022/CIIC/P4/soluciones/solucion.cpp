#include<iostream>
using namespace std;

int main(){
    int m, n;
    cin >> n >> m;
    int sumandos[m];

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        sumandos[i] = x;
    }

    int sumas[n + 1];
    for(int i = 0; i <= n; i++){
        sumas[i] = 0;
    }
    sumas[0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(i + sumandos[j] <= n){
                sumas[i + sumandos[j]] += sumas[i];
            }
        }
    }

    cout << sumas[n] << endl;
}
