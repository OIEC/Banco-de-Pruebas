#include<iostream>
#include<algorithm>
using namespace std;

struct Punto
{
  float x;
  float y;
  float pendiente;
};

bool OrdenarPuntos (Punto p1, Punto p2)
{
  return p1.pendiente > p2.pendiente; 
}

Punto puntos[300000];
int n;

// Punto p es el punto que se une con el origen.
int Signo(int p, int i)
{
  float cruz = (puntos[p].x)*(puntos[i].y) - (puntos[p].y)*(puntos[i].x);
  if (cruz > 0.0f) return 1;
  return -1;
}

bool DividePlano(int p)
{
  int positivo = 0;
  int negativo = 0;

  for (int i = 0; i < n; i++)
  {
    if (i==p) continue;
    int s = Signo(p,i);
    if (s > 0) positivo++;
    if (s < 0) negativo++;
  }
  return positivo == negativo && (positivo == (n-1)/2);
}

int main ()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    float x;
    float y;
    cin >> x >> y;
    puntos[i].x = x;
    puntos[i].y = y;
    puntos[i].pendiente = y/x;
  }

  sort (puntos, puntos+n, OrdenarPuntos);

  printf("%.4f %.4f", puntos[n/2].x, puntos[n/2].y);

}