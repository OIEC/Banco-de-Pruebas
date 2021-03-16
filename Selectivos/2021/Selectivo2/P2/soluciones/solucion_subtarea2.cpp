#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef int32_t i32;

i32 n, k, kar[1000], m, res, ans=0;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    // Contamos cuántos elementos hay para cada uno de los k restos.
    for(i32 i =0; i<n;i++){
        cin >> m;
        res = m%k;
        kar[res]++;
    }

    // Se calcula el binomial (k 2) para cada uno de los residuos y se suma.
    for(i32 i=0; i<k;i++){
        ans += (kar[i]*(kar[i]-1));
    }
    ans /= 2;
    cout << ans;

}