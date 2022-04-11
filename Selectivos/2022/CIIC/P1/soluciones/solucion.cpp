/* Notas: 
  La libreria bits importa todo lo que necesitamos.
  
  #define es usado para renombrar ciertas partes y
  hacerlas más cortas.
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i = a;i<b;i++)
#define PB push_back
vector<vector<int>>v;
vector<int>v1;
int n,c,k;
void imprimir(){
        REP(i,0,n){
            REP(j,0,n){
                cout << v[i][j]<<' ';
            }
            cout <<'\n';
        }
    }
    void girar(){
        vector<vector<int>>v2;
        vector<int>pivot;
        REP(i,0,n){
            REP(j,0,n){
                pivot.PB(v[j][i]);
            }
            v2.PB(pivot);
            pivot.clear();
        }
        v = v2;
    }
    void columnas(){
        int a,b,d=0;
        cin>>a>>b;
        a-=1;
        b-=1;
        REP(i,0,n){
            d = v[i][a];
            v[i][a] = v[i][b];
            v[i][b] = d;
            
        }
    }
    void filas(){
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        vector<int>pivot;
        pivot=v[a];
        v[a] = v[b];
        v[b]=pivot;
    }
int main()
{
    
    /* Ejemplo de input 
    n=3,k=3
    matriz nxn
    1 2 3
    4 5 6
    7 8 9
    
    k queries
    C 1 2
    F 1 2
    G
    */
    
    vector<int>v1;
    char operacion;
    
    cin>>n>>k;
    REP(i,0,n){
        REP(j,0,n){
            cin>>c;
            v1.PB(c);
        }
        v.PB(v1);
        v1.clear();
    }
    
    REP(i,0,k){
        cin >> operacion;
        if(operacion=='F'){
            filas();
        }else if(operacion=='C'){
            columnas();
        }else{
            girar();
        }
    }
    
    imprimir();
    

    return 0;
}