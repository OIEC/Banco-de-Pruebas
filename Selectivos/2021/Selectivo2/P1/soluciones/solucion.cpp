#include <iostream>
using namespace std;

double Distancia(double x, double y, int i, int j)
{
    return (x-i)*(x-i) + (y-j)*(y-j);
}

int main()
{
    double x;
    double y;
    cin >> x;
    cin >> y;
    double r;
    cin >> r;

    int cantidad = 0;
    for (int i = x - r; i <= x + r; ++i)
    {
        for (int j = y - r; j <= y + r; ++j)
        {
            if (Distancia(x, y, i, j) < r*r)
            {
                ++cantidad;
            }
        }
    }
    cout << cantidad << endl;
}