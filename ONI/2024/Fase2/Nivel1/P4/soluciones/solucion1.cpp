#include <iostream>
#include <vector>

using namespace std;

// Ordenamiento burbuja
void burbuja(vector<int>& arr) {
    int n = arr.size();
    bool cambiado;
  
    for (int i = 0; i < n - 1; i++) {
        cambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cambiado = true;
            }
        }
      
        // Si no hemos cambiado elementos, salimos.
        if (!cambiado)
            break;
    }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  std::vector<int> arr(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> arr[i];
  }

  burbuja(arr);

  double minimo = 1000000000000.0;
  for(int i = 1; i < N - 1 ; i++)
  {
    double izquierda = (arr[i] - arr[i-1]) / 2.0;
    double derecha = (arr[i+1] - arr[i]) / 2.0;
    if(izquierda + derecha < minimo)
    {
        minimo = izquierda + derecha;
    }
  }
  printf("%.1f\n", minimo); 

  return 0;
}