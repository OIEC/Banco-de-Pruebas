Si consideramos cada ciudad como un vértice,
y cada vuelo o portal como aristas, cuyo peso es la energía,
tendríamos un grafo con pesos.

*Lema:* El problema sería encontrar el [Árbol recubridor mínimo](https://es.wikipedia.org/wiki/%C3%81rbol_recubridor_m%C3%ADnimo)

*Razonamiento*: El árbol recubridor es un árbol con los mismos vértices,
pero menos aristas, tal que los vértices siguen siendo conectados, y
no tenga ciclos.

El requerimiento de conectado es dado en el problema.
El requerimiento de no tener ciclo es una consecuencia de querer ahorrar más,
es decir, quedar con menos. Ya que, si tuviera un ciclo, es posible quitar
un vuelo o un portal más, y seguir con la condición de ser conectados.

Entonces el plan es:
1. Encontrar el árbol recubridor mínimo.
2. Restar la energía total del árbol de la energía anterior, ya que el
   problema pide cuánto se ahorró.

## Cómo se encuentra árbol recubridor mínimo

El método conocido es el [algoritmo de Kruskal](https://es.wikipedia.org/wiki/Algoritmo_de_Kruskal).

La idea de este método es lo siguiente:

1. Comenzamos con el conjunto vacío de aristas, es decir, todos los vértices
   están por su cuenta.
2. Tomar la arista con menor peso, añadirlo al conjunto, al mismo tiempo,
   unir a los vertices (es decir ahora esos 2 vértices ya están conectados).
3. Repite 2, pero solamente considerando aristas que **no** creen un *ciclo*.
4. Parar el proceso cuando se tengan $n - 1$ aristas, donde $n$ es el número
   de vértices. Sabemos que los árboles siempre tiene una arista menos que vértices.

Este es un algoritmo codicioso (greedy). Cada paso vamos tomando la arista que
se pueda (que no crea ciclos) y que tenga peso menor.

Antes de implementarlo, necesitamos algo que nos diga si la arista que estamos
considerando va a crear un ciclo o no. Para eso utilizaremos una estructura
que se conoce como [bosques de conjuntos disjuntos](https://es.wikipedia.org/wiki/Estructura_de_datos_para_conjuntos_disjuntos)
También conocida como union-find en inglés.

Bosques de conjuntos tiene 2 operaciones:

1. Averiguar si 2 elementos pertenecen al mismo conjunto.
2. Dados 2 elementos, unir los conjuntos a los que pertenencen.

Entonces, para implementar Kruskal, para cada arista, si sus vértices
no están en el mismo conjunto, esa arista no creará un ciclo. Y, al añadirla
al conjunto, solamente tenemos que unir los 2 conjuntos de vértices conectados.

Tendremos esta solución

```cpp
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



int N, M, P, Q;

struct Arista {
  int desde_planeta;
  int desde_ciudad;
  int hasta_planeta;
  int hasta_ciudad;
  int energia;

  bool operator<(const Arista& rhs) const {
      return energia < rhs.energia;
  }

  int desde() const {
      return M*desde_planeta + desde_ciudad;
  }

  int hasta() const {
      return M*hasta_planeta + hasta_ciudad;
  }
};

struct BosqueDeConjunto {
    std::vector<int> arreglo;
    BosqueDeConjunto(int size) : arreglo(size) {
        for (int i = 0; i < size; i++) {
            arreglo[i] = i;
        }
    }

    int find(int x) {
        vector<int> path;
        while (x != arreglo[x]) {
            path.push_back(x);
            x = arreglo[x];
        }
        for (int p : path) {
          arreglo[p] = x;
        }
        return x;
    }

    void unir(int x, int y) {
        int org_x = find(x);
        int org_y = find(y);
        arreglo[org_x] = org_y;
    }

};



int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  cin >> N >> M >> P >> Q;
  std::vector<Arista> aristas;
  int energia_anterior = 0;
  for (int i = 0; i < P; i++) {
    int desde, hasta, energia;
    cin >> desde >> hasta >> energia;
    for (int j = 0; j < N; j++) {
      Arista arista;
      // vuelos no cambia de planeta
      arista.desde_planeta = j;
      arista.hasta_planeta = j;
      arista.desde_ciudad = desde - 1;
      arista.hasta_ciudad = hasta - 1;
      arista.energia = energia;
      aristas.push_back(arista);
      energia_anterior += energia;
    }
  }
  for (int i = 0; i < Q; i++) {
    int desde, hasta, energia;
    cin >> desde >> hasta >> energia;
    for (int j = 0; j < M; j++) {
      Arista arista;
      // portales no cambia de ciudad 
      arista.desde_planeta = desde - 1;
      arista.hasta_planeta = hasta - 1;
      arista.desde_ciudad = j;
      arista.hasta_ciudad = j;
      arista.energia = energia;
      aristas.push_back(arista);
      energia_anterior += energia;
    }
  }

  // ordenar porque vamos a tomar las aristas con menores energías primero
  std::sort(aristas.begin(), aristas.end());

  int energia_total = 0;
  int num_aristas = 0;

  BosqueDeConjunto bosque(N*M);

  for (const auto& a : aristas) {
      auto desde = a.desde();
      auto hasta = a.hasta();
      if (bosque.find(desde) != bosque.find(hasta)) {
          bosque.unir(desde, hasta);
          energia_total += a.energia;
          num_aristas += 1;
      }
      if (num_aristas == N*M - 1) break;
  }

  cout << energia_anterior - energia_total << endl;
  return 0;
}
```

Esta solución es una implementación estándar de Kruskal, pero
solo logrará pasar las primeras 2 subtareas. Unos lugares
evidentes de mejorar son los siguientes:

```
    for (int j = 0; j < M; j++) {
      Arista arista;
      // portales no cambia de ciudad 
      arista.desde_planeta = desde - 1;
      arista.hasta_planeta = hasta - 1;
      arista.desde_ciudad = j;
      arista.hasta_ciudad = j;
      arista.energia = energia;
      aristas.push_back(arista);
      energia_anterior += energia;
    }
```
Ahí estamos creando $M$ aristas, ya que existe un portal desde
$a_i$ hasta $b_i$ para cada ciudad que existe. Pero estamos guardando
mucha información redundante.

```
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



int N, M, P, Q;

struct Aristas {
  int desde;
  int hasta;
  bool es_portal;
  long energia;

  bool operator<(const Aristas& rhs) const {
      return energia < rhs.energia;
  }
};

struct BosqueDeConjunto {
    std::vector<int> arreglo;
    BosqueDeConjunto(int size) : arreglo(size) {
        for (int i = 0; i < size; i++) {
            arreglo[i] = i;
        }
    }

    int find(int x) {
        while (x != arreglo[x]) {
            x = arreglo[x];
        }
        return x;
    }

    void unir(int x, int y) {
        int org_x = find(x);
        int org_y = find(y);
        arreglo[org_x] = org_y;
    }
};



int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  cin >> N >> M >> P >> Q;
  std::vector<Aristas> aristas;
  long energia_anterior = 0;
  for (int i = 0; i < P; i++) {
    int desde, hasta;
    long energia;
    cin >> desde >> hasta >> energia;
    Aristas arista;
    arista.desde = desde - 1;
    arista.hasta = hasta - 1;
    arista.energia = energia;
    arista.es_portal = false;
    aristas.push_back(arista);
    energia_anterior += energia * N;
  }
  for (int i = 0; i < Q; i++) {
    int desde, hasta;
    long energia;
    cin >> desde >> hasta >> energia;
    Aristas arista;
    arista.desde = desde - 1;
    arista.hasta = hasta - 1;
    arista.energia = energia;
    arista.es_portal = true;
    aristas.push_back(arista);
    energia_anterior += energia * M;
  }

  // ordenar porque vamos a tomar las aristas con menores energías primero
  std::sort(aristas.begin(), aristas.end());

  long energia_total = 0;
  int num_aristas = 0;

  BosqueDeConjunto bosquePlanetas(N);
  BosqueDeConjunto bosqueCiudades(M);
  int num_planetas = N;
  int num_ciudades = M;

  for (const auto& a : aristas) {
    if (a.es_portal) {
      // unir planetas
      if (bosquePlanetas.find(a.desde) != bosquePlanetas.find(a.hasta)) {
          bosquePlanetas.unir(a.desde, a.hasta);
          energia_total += a.energia * long(num_ciudades);
          num_planetas --;
      }
    } else {
      // unir ciudades 
      if (bosqueCiudades.find(a.desde) != bosqueCiudades.find(a.hasta)) {
          bosqueCiudades.unir(a.desde, a.hasta);
          energia_total += long(a.energia) * long(num_planetas);
          num_ciudades--;
      }
    }
  }

  cout << energia_anterior - energia_total << endl;
  return 0;
}
```

La solución de arriba logra pasar la subtarea 3.

La idea es que ahora, cada arista represente N portales o M vuelos.
Por lo tanto, cuando unimos una arista, tenemos que multiplicar por 
el número de ciudades o planetas que quedan por unirse, ya que necesitaría
esos números de vuelos para conectar a todas esas ciudades.

Para la subtarea 4, se puede hacerlo más rapido con el truco de
"path-compression". El problema del BosqueDeConjuntos es que los árboles
crecen en altura y se hace más lento. Una forma de aliviarlo es
reducir la altura de los árboles mientras que hacemos `find`. 

```
int find(int x) {
        vector<int> path;
        while (x != arreglo[x]) {
            path.push_back(x);
            x = arreglo[x];
        }
        for (int p : path) {
          arreglo[p] = x;
        }
        return x;
}
```

Pueden leer más en el
artículo de wikipedia en inglés: https://en.wikipedia.org/wiki/Disjoint-set_data_structure




