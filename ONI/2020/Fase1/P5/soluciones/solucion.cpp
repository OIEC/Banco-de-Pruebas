#include <iostream>
#include <cmath>
using namespace std;

int main () 
{
    double p;
    double a;
    cin >> p;
    cin >> a;
    bool hay = 0;
    double sp = p / 2;

    for (int l1 = 1; l1 <= p/2; l1++)
    {
        for (int l2 = 1; l2 <= l1; l2++)
	{
	    for (int l3 = l1-l2+1; l3 <= l2; l3++)
	    {
	        if (l1 + l2 + l3 == p 
	            && abs(sqrt(sp * (sp-l1) * (sp-l2) * (sp-l3)) - a) < 0.00001)
		{
		    hay = true;
		    cout << l3 << " " << l2 << " " << l1 << endl;
		}
	    }
	}
    }

    if (!hay)
    {
        cout << "no hay";
    }
}