#include<stdio.h>

int crearN(int n){
  int N = 0;

  for(int c = 0, i = 1; c < n; c++, i*=10)
    N += i;
  
  return N;
}

int main(){
  int n, d, k, N;
  int esPosible = 0;

  scanf("%d", &n);
  scanf("%d", &d);
  scanf("%d", &k);

  N = crearN(n);

  for(int c = 1, i = 1; c <= n; c++, i *= 10){
    if((N + d * i) % k == 0){
      esPosible = 1;
      printf("%d\n", c);
    }
  }

  if(!esPosible)
    printf("Derrota");
}