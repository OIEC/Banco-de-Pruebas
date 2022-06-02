/* Notas: 
  typedef long long ll nos permite definir long long usando únicamente ll.
*/
#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;


ll gcdr(ll a, ll b){
    ll gcdab = 0;
    for (ll j=1;j<=min(a,b);j++){
        if (a%j==0 && b%j==0){
            gcdab = j;
        }
    }
    return gcdab;
}

ll lcmr(ll a, ll b){
    ll lcmab = 0;
    for (ll j=1;j<=min(a,b);j++){
        if (a%j==0 && b%j==0){
            lcmab = j;
        }
    }
    lcmab = (a/lcmab)*b;
    return lcmab;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  ll A[n], B[m];
  ll lcmA;
  ll gcdB;

  for(int i = 0; i < n; i++){
    cin >> A[i];

    if(i == 0)
      lcmA = A[i];
    else{
      lcmA = lcmr(lcmA, A[i]);
    }
  }
  for(int i = 0; i < m; i++){
    cin >> B[i];

    if(i == 0)
      gcdB = B[i];
    else{
      gcdB = gcdr(gcdB, B[i]);
    }
  }

  int res = 0;
  ll multiplos = lcmA;
  while(multiplos <= gcdB){
    if(gcdB % multiplos == 0){
      res++;
    }
    multiplos += lcmA;
  }

  cout << res;
  return 0;
}