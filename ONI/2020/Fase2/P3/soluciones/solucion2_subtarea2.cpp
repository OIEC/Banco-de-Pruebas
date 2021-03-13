#include <iostream>
using namespace std;
// Función que permite calcular el área de un triángulo cuyos vértices son
// (a,b), (c,d) y (e,f).
int area(int a, int b, int c, int d, int e, int f) {
	return (d-b)*e+(a-c)*f+c*b-a*d;
}
// Función que verifica que si el triángulo con vértices (a,b), (c,d) y (e,f)
// tiene área 0 (sus tres vértices forman una línea recta) el punto (e,f) está
// entre los puntos (a,b) y (c,d)
bool lin(int a, int b, int c, int d, int e, int f) {
	if (area(a,b,c,d,e,f)==0) {
		if ((a<=e && e<=c)||(a>=e && e>=c)){
			if ((b<=f && f<=d)||(b>=f && f>=d)){
				return true;
			}
		}
	}
	return false;
}

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	int I=0, P=0;
	int xm, xM, ym, yM;
	if (x1<=x2){xm=x1; xM=x2;}
	else {xm=x2; xM=x1;}
	if (x3<=xm) {xm=x3;}
	if (x3>=xM) {xM=x3;}
	// Obtengo el mayor valor de y y el menor
	if (y1<=y2){ym=y1; yM=y2;}
	else {ym=y2; yM=y1;}
	if (y3<=ym) {ym=y3;}
	if (y3>=yM) {yM=y3;}

	int A1, A2, A3;
	// Realizo un for entre todos los puntos.
	for (int i=xm; i<=xM; i++) {
		for (int j=ym; j<=yM; j++) {
			// Verifico en si el punto está en el mismo semiplano que el otro vertice para cada lado.
			A1=area(x1,y1,x2,y2,x3,y3)*area(x1,y1,x2,y2,i,j);
			A2=area(x3,y3,x2,y2,x1,y1)*area(x3,y3,x2,y2,i,j);
			A3=area(x1,y1,x3,y3,x2,y2)*area(x1,y1,x3,y3,i,j);
			// Si se cumple para los tres lados entonces el punto está dentro del triángulo.
			if (A1>0 && A2>0 && A3>0) {I++;}
			// Si está en una de las rectas a las que pertenece los lados verifico que perteneza también
			// al segmento del lado
			if (A1==0 || A2==0 || A3==0) {
			if (lin(x1,y1,x2,y2,i,j)||lin(x3,y3,x2,y2,i,j)||lin(x1,y1,x3,y3,i,j)) {
				P++;
				}
			}
		}
	}
	cout << I << " " << P << endl;
	return 0;
}