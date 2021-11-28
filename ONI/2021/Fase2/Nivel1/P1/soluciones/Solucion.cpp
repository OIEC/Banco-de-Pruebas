#include <iostream>

using namespace std;

int main()
{
    int t,v,l,m,total,ac=3001,piv=0;
    cin >> t;
    
    for(int i =0; i<t;i++){
        cin>>m>>v>>l;
        total = m+v+l*4;
        if (total < ac){
            ac = total;
            piv =i;
        }
    }
    cout << piv+1;
    return 0;
}
