# Editorial — Crucigrama

## Planteamiento del problema

Se nos dan dos palabras:
- $A$, de longitud $N$, que se escribe **horizontalmente**.
- $B$, de longitud $M$, que se escribe **verticalmente**.

Ambas palabras deben cruzarse compartiendo **exactamente una letra**, y esa letra debe ser la **primera letra de $A$ (recorrida en orden) que también aparece en $B$**. Una vez identificada esa letra, el punto de cruce se define como:

- Su **posición dentro de $A$** (primera vez que aparece esa letra en $A$) → determina la **columna** donde se cruza $B$.
- Su **primera posición dentro de $B$** → determina la **fila** donde se cruza $A$.

La salida es una grilla de $M$ filas por $N$ columnas, donde:
- La fila correspondiente al cruce contiene la palabra $A$ completa.
- La columna correspondiente al cruce contiene la palabra $B$ completa.
- El resto de las celdas son `.`.

---

## Idea de la solución

1. **Encontrar la letra de cruce:** recorrer $A$ posición por posición ($i = 0, 1, \dots, N-1$). Para cada carácter `A[i]`, verificar si aparece en $B$ (por ejemplo con `B.find(A[i])` en C++, o `in`/`index` en Python). La **primera** posición $i$ para la cual `A[i]` está en $B$ nos da:
   - `col = i` (la columna de cruce, posición en $A$)
   - `row` = índice de la primera aparición de `A[i]` en $B$ (la fila de cruce)

   Como el enunciado garantiza que existe al menos una letra común, este proceso siempre termina exitosamente antes de recorrer toda $A$.

2. **Construir la grilla:** crear una matriz de $M$ filas por $N$ columnas, inicializada completamente con `.`.
   - Sobre la fila `row`, copiar la palabra $A$ carácter por carácter (columnas $0$ a $N-1$).
   - Sobre la columna `col`, copiar la palabra $B$ carácter por carácter (filas $0$ a $M-1$).
   - Notar que la celda `(row, col)` se sobrescribe por ambos pasos, pero no hay conflicto: por construcción, `A[col] == B[row]` (es la letra compartida), así que el valor final es consistente sin importar el orden en que se escriban.

3. **Imprimir** las $M$ filas de la grilla.

### Verificación con el ejemplo
$A = \text{"ABBA"}$, $B = \text{"CCBBD"}$.

- $i=0$: `A[0]='A'`. ¿'A' está en B="CCBBD"? No.
- $i=1$: `A[1]='B'`. ¿'B' está en B? Sí, en la posición 2 (0-indexado, tras las dos 'C').
  → `col = 1`, `row = 2`.

Grilla ($M=5$ filas, $N=4$ columnas):
- Fila 2 (row) = "ABBA" (la palabra $A$ completa).
- Columna 1 (col) = "C","C","B","B","D" (la palabra $B$ completa, leída en las filas 0 a 4).

Resultado:
```
.C..
.C..
ABBA
.B..
.D..
```

Coincide exactamente con la salida esperada.

---

## Complejidad

Dado que $1 \le N, M \le 30$, el problema es de tamaño trivialmente pequeño:

- **Encontrar la letra de cruce:** en el peor caso se recorre toda $A$ (hasta 30 caracteres) y, por cada carácter, se busca en $B$ (hasta 30 caracteres), dando como máximo $O(N \cdot M) = O(30 \times 30) = 900$ operaciones.
- **Construir e imprimir la grilla:** $O(N \cdot M)$, ya que se llenan y recorren hasta $30 \times 30 = 900$ celdas.

En total, la solución corre en **$O(N \cdot M)$ tiempo y memoria**, extremadamente rápido incluso en el peor caso, dado que $N, M \le 30$. No existen sub-tareas por límites distintos: una única solución directa resuelve el problema completo.
