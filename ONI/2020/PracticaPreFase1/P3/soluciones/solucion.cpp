#include <stdio.h>
#include <math.h>
int main()
{
  int n;
  scanf("%d", &n);
  int ans = pow(2,n) - (n + 1);
  printf("%d",ans);
}