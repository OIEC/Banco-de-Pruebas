#include <iostream>

using namespace std;

int pscl[100][100];

int Pascal(int n, int k){
    if (k==0)
       return pscl[n][k]=1;
    if (n==k)
       return pscl[n][n]=1;
    
    return Pascal(n-1,k-1)+Pascal(n-1,k);
}

int main(){

    int n,k;
    cin>>n;
    n-=1;
    for(int i = 0 ; i < n ; i++){
        cout<<Pascal(n,i)<<" ";
    }
    cout<<"1"<<endl;
    return 0;
}