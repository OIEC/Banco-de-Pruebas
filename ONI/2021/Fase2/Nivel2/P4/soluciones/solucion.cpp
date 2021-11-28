#include <iostream>
#include <math.h>

int d(long long x){
    //devuelve cantidad de dígitos
    long long a;
    a = log10(x)+1;
    return a;
}

int get(long long N, long long cant_digit){
    //devuelve dígito en cierta posición
    int dig;
    dig = N / (pow(10, cant_digit- 1));
    return dig;
}

int main(){
    long long N;
    int m;
    int cant_dig;
    int resp = 0;
    std::cin>>N;
    std::cin>>m;
    cant_dig = d(N);
    int borrados = 0;
    int menor_ahora;
    long long temp_N;
    int temp_cant;
    int sig_num;
    int a_borrar_a_izquierda;
    int potencia = cant_dig-m-1;
    int por_borrar;
    long long mod;
    int dejados_a_la_izquierda = 0;


    for(int j=0; j<cant_dig-m; j++){
        temp_cant = cant_dig - dejados_a_la_izquierda;
        por_borrar = m - borrados;
        a_borrar_a_izquierda = 0;
        // scanear los por_borrar+1 de la izquierda
        temp_N = N;
        menor_ahora = get(N, temp_cant);
        for (int i = 1; i<por_borrar+1; i++){
            temp_cant--;
            mod = pow(10, temp_cant);
            temp_N = N % mod;
            sig_num = get(temp_N, temp_cant);
            if (sig_num<menor_ahora){
                menor_ahora = sig_num;
                a_borrar_a_izquierda = i;
            }
        }
        dejados_a_la_izquierda ++; // por el que se va a conservar
        resp = resp + menor_ahora*pow(10,potencia);
        potencia --;
        borrados = borrados + a_borrar_a_izquierda;
        dejados_a_la_izquierda = dejados_a_la_izquierda + a_borrar_a_izquierda; // por los que se van a borrar
        mod = pow(10,cant_dig-dejados_a_la_izquierda);
        N = N % mod;


    }

    //resp = resp + N;
    std::cout<<resp;

}
