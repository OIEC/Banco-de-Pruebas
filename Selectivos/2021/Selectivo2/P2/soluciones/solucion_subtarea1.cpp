#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef int32_t i32;

i32 n, k, num[100000], ans=0;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(i32 i=0; i<n; i++){
        cin >> num[i];
    }

    // Realizamos un doble for para poder obtener todas las restas posibles.
    for(i32 i =0; i<n;i++){
        for(i32 j =i+1; j<n;j++){
            if(abs(num[i]-num[j])%k==0) ans++;
        }
    }


    cout << ans;

}