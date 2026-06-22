# Editorial - Postes para la Lona

## Idea

Debemos seleccionar exactamente `k` postes de entre los `n` disponibles.

La calidad de una selección se mide por la diferencia entre el poste más grande y el poste más pequeño del grupo. Queremos que esta diferencia sea lo más pequeña posible.

Observemos que, si ordenamos los tamaños de los postes, cualquier conjunto óptimo de `k` postes corresponderá a un segmento contiguo del arreglo ordenado.

¿Por qué?

Porque si elegimos `k` postes y tomamos sus tamaños en orden creciente, cualquier poste situado entre el menor y el mayor podría reemplazar a uno exterior sin aumentar la diferencia. Por lo tanto, basta revisar todos los bloques consecutivos de longitud `k` en el arreglo ordenado.

## Algoritmo

1. Leer `k` y `n`.
2. Leer los `n` tamaños de postes.
3. Ordenar los tamaños en orden creciente.
4. Para cada bloque consecutivo de longitud `k`:
   - Calcular la diferencia entre el último y el primero.
   - Mantener la mínima diferencia encontrada.
5. Imprimir la respuesta.

## Ejemplo

Entrada:

```
3
10
100 20 40 33 65 200 77 178 135 47
```

Después de ordenar:

```
20 33 40 47 65 77 100 135 178 200
```

Bloques de tamaño 3:

```
20 33 40  -> 20
33 40 47  -> 14
40 47 65  -> 25
47 65 77  -> 30
65 77 100 -> 35
...
```

La mínima diferencia es `14`.

## Correctitud

Sea una selección óptima de `k` postes.

Ordenemos sus tamaños. La diferencia que nos interesa depende únicamente del menor y del mayor elemento seleccionados.

En el arreglo global ordenado, todos los elementos comprendidos entre esos dos extremos forman un intervalo. Si existen más de `k` elementos dentro del intervalo, podemos elegir cualquier subconjunto de `k` elementos de dicho intervalo y la diferencia no aumentará.

Por lo tanto, existe siempre una solución óptima formada por `k` elementos consecutivos en el arreglo ordenado.

El algoritmo revisa todos los bloques consecutivos de longitud `k`, incluyendo necesariamente el bloque correspondiente a alguna solución óptima. Como toma la mínima diferencia entre todos ellos, la respuesta obtenida es correcta.

## Complejidad

Ordenar los `n` postes cuesta:

```
O(n log n)
```

Luego recorremos todos los bloques consecutivos una sola vez:

```
O(n)
```

Por lo tanto:

- Tiempo: **O(n log n)**
- Memoria: **O(n)**
