#include <iostream>
using namespace std;

int maximaTemperatura(int x, int y, int z){
    return max(x, max(y, z));
}

int minimaTemperatura(int x, int y, int z){
    return min(x, min(y, z));
}

bool esEstable(int min, int max){
    return abs(max - min) <= 5;
}

bool esCaluroso(int min, int max){
    return esEstable(min, max) && max > 28;
}

bool esFrio(int min, int max){
    return esEstable(min, max) && min < 7;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // TODO: fixme.
  int numeroSemanas;
    cin >> numeroSemanas;
    
    for(int i = 0; i < numeroSemanas; i++){
        int diasEstables = 0;
        int diasCalurosos = 0;
        int diasFrios = 0;
        
        for(int dia = 0; dia < 7; dia++){
            int manana;
            int tarde;
            int noche;
            
            cin >> manana >> tarde >> noche;
            int maxTemp = maximaTemperatura(manana, tarde, noche);
            int minTemp = minimaTemperatura(manana, tarde, noche);
            
            if(esEstable(minTemp, maxTemp)){
                diasEstables++;
            }
            if(esCaluroso(minTemp, maxTemp)){
                diasCalurosos++;
            }
            if(esFrio(minTemp, maxTemp)){
                diasFrios++;
            }
        }
        
        cout << diasFrios << " " << diasCalurosos << " " << diasEstables << endl;
    }
    
  return 0;
}
