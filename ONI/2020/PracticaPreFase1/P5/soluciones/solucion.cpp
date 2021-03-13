#include<stdio.h>
long long nterm (int n)
{
  long long num = 0;
  for (int i = 0; i < n; i++)
  {
    num = num * 10 + 9;
  }
  return num;
}
int main () 
{
  long long n;
  scanf("%lld", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += nterm(i);
  }
  printf("%lld", sum);
}