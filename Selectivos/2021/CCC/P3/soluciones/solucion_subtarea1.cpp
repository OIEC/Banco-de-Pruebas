#include <iostream>
using namespace std;

int triangulos[2500];

bool desigualdadTriangular(int x, int y, int z){
    return (x + y > z && z + x > y && y + z > x);
}

int contarTriangulos(int n){
    int count = 0;

    for(int lado1 = 0; lado1 < n - 2; lado1++){
        for(int lado2 = lado1 + 1; lado2 < n - 1; lado2++){
            for(int lado3 = lado2 + 1; lado3 < n; lado3++){
                if(desigualdadTriangular(triangulos[lado1], triangulos[lado2], triangulos[lado3]))
                    count++;
            }
        }
    }

    return count;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> triangulos[i];

    cout << contarTriangulos(n);
}
