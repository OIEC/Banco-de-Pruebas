#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if((i + j) % 2 == 0)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}