#include<stdio.h>

int main () {
  for (int i = 1; i <= 100; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      printf("OlimpiadaInformatica\n");
    }
    else if (i % 3 == 0)
    {
      printf("Olimpiada\n");
    }
    else if (i % 5 == 0)
    {
      printf("Informatica\n");
    }
    else
    {
      printf("%d\n", i);  
    }
  }
}