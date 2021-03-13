#include<stdio.h>

int ganador(char a, char b)
{
    if(a == b)
        return 0;
    if((a == 'P' && b == 'R') || (a == 'R' && b == 'T') || (a == 'T' && b == 'P'))
        return 1;
    else
        return 2;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    int a_cont = 0;
    int b_cont = 0;

    while(n--)
    {
        char a;
        char b;
        scanf("%c %c", &a, &b);

        if(ganador(a, b) == 1){
            printf("Ana gana\n");
            a_cont++;
        }
        else if(ganador(a, b) == 2){
            printf("Beto gana\n");
            b_cont++;
        }
        else
            printf("Empate\n");
    }

    if(a_cont > b_cont)
        printf("Ana gana el torneo\n");
    else
        printf("Beto gana el torneo\n");
}