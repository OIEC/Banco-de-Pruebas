La idea es contar cuántas personas conocen a cada una de las personas en un arreglo $C$. Es decir $C[i]$ es la cantidad de personas que conocen a la persona $i$. Para la primera subtarea se puede hacer con 5 variables en lugar de un arreglo.

Para cada persona $i$, se puede iterar sobre la lista de adyacencia, incrementando $C[i]$ cada vez que aparece $i$. Esto toma $O(N^2)$ si se lo hace para cada $i$. Se puede optimizar leyendo en $O(N)$ iterando solamente una vez por sobre la lista de adyacencia incrementando cada $C[p]$ por cada persona $p$ que aparezca. Luego podemos iterar sobre el arreglo $C$ y hallar la cantidad máxima de seguidores $S$. Para la subtarea 2 basta imprimir la persona (el índice) que tiene la máxima cantidad de seguidores.

Para la subtarea 3 podemos efectuar una iteración adicional sobre el arreglo $C$ e imprimir todos los índices con máxima cantidad de seguidores $S$. Por construcción del arreglo los estaremos imprimiendo en el orden correcto.
