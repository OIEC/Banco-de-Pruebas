
El problema nos garantiza que la tabla de entrada es una rotación de la tabla original, entonces basta rotar la matriz 90, 180, 270 y 360 grados para verificar cuál de estas cuatro rotaciones cumple con la condición de orden planteada inicialmente. Por lo tanto, creamos una función para rotar la matriz.

```
#include <cstdio>
int matrix[MAXN][MAXN];

void rotar90(int n) {
    int temp[MAXN][MAXN];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[j][n - i - 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = temp[i][j];
        }
    }
}

```

Notar que no hemos construido las funciones rotar 180, 270 y 360 porque son equivalentes a llamar a la matriz "rotar90"  2, 3 y 0 veces respectivamente. Recordar que rotar 360 es lo mismo que no rotar.

Luego necesitamos verificar el orden en los elementos de nuestra tabla, así que escribimos las funciones que verifican si las columnas y filas están ordenadas o no. Como estas funciones de verificar responden a un sí o no las funciones a crear son booleanas.


```
bool OrdenColumnas(int n) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            if (matrix[i][j] > matrix[i + 1][j]) {
                return false;
            }
        }
    }

    return true;
}

bool OrdenFilas(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (matrix[i][j] > matrix[i][j + 1]) {
                return false;
            }
        }
    }

    return true;
}
```

## Solución 

```cpp
#include <cstdio>

const int MAXN = 101;

int matrix[MAXN][MAXN];

void rotar90(int n) {
    int temp[MAXN][MAXN];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[j][n - i - 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = temp[i][j];
        }
    }
}


bool OrdenColumnas(int n) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            if (matrix[i][j] > matrix[i + 1][j]) {
                return false;
            }
        }
    }

    return true;
}

bool OrdenFilas(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (matrix[i][j] > matrix[i][j + 1]) {
                return false;
            }
        }
    }

    return true;
}

void ImprimirMatrix(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        if(i < n-1)    
            printf("\n");
    }
}

int main() {
    int n;

    scanf("%d", &n);


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int originalMatrix[MAXN][MAXN];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            originalMatrix[i][j] = matrix[i][j];
        }
    }

    if (!OrdenFilas(n) || !OrdenColumnas(n)) {
        rotar90(n);
    }

    if (!OrdenFilas(n) || !OrdenColumnas(n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = originalMatrix[i][j];
            }
        }
        rotar90(n);
      	rotar0(n);
    }

    if (!OrdenFilas(n) || !OrdenColumnas(n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = originalMatrix[i][j];
            }
        }
        rotar90(n);
      	rotar90(n);
      	rotar90(n);
    }


    ImprimirMatrix(n);

    return 0;
}
```

La idea dentro del main es crear una matriz que represente a la matriz original o dicho de otro modo, la matriz que estamos buscando dar de output. Entonces, basta guardar la matriz original e ir rotando la matriz inicial hasta verificar que cumple las condiciones de orden, es decir que ya no van a entrar a los "if(!OrdenFilas(n) || !OrdenColumnas(n))"

Finalmente se imprime la matriz con la función ImprimirMatrix.
