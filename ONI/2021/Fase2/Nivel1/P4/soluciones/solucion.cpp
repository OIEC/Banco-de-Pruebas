#include <iostream>
#include <algorithm>
using namespace std;

int cuentas[15];

void LlenarCuentas(string c)
{
    if (c == "2")
    {
        cuentas[2] += 1;
    }

    if (c == "3")
    {
        cuentas[3] += 1;
    }

    if (c == "4")
    {
        cuentas[4] += 1;
    }

    if (c == "5")
    {
        cuentas[5] += 1;
    }

    if (c == "6")
    {
        cuentas[6] += 1;
    }

    if (c == "7")
    {
        cuentas[7] += 1;
    }

    if (c == "8")
    {
        cuentas[8] += 1;
    }

    if (c == "9")
    {
        cuentas[9] += 1;
    }

    if (c == "10")
    {
        cuentas[10] += 1;
    }

    if (c == "J")
    {
        cuentas[11] += 1;
    }

    if (c == "Q")
    {
        cuentas[12] += 1;
    }

    if (c == "K")
    {
        cuentas[13] += 1;
    }

    if (c == "A")
    {
        cuentas[14] += 1;
    }
}

bool TienePoker()
{
    for (int i = 2; i <= 14; ++i)
    {
        if (cuentas[i] == 4)
        {
            return true;
        }
    }
    return false;
}

bool TieneFullHouse()
{
    // Existe un trío.
    bool tieneTrio = false;
    for (int i = 2; i <= 14; ++i)
    {
        if (cuentas[i] == 3)
        {
            tieneTrio = true;
        }
    }

    if (!tieneTrio)
    {
        return false;
    }

    // Existe un par.
    for (int i = 2; i <= 14; ++i)
    {
        if (cuentas[i] == 2)
        {
            return true;
        }
    }
    return false;
}

bool TieneEscalera()
{
    if (cuentas[15] == 1 && cuentas[2] == 1 && cuentas[3] == 1 && cuentas[4] == 1 && cuentas[5] == 1)
    {
        return true;
    }

    for (int i = 2; i <= 10; ++i)
    {
        if (cuentas[i] == 1 && cuentas[i + 1] == 1 && cuentas[i + 2] == 1 && cuentas[i + 3] == 1 && cuentas[i + 4] == 1)
        {
            return true;
        }
    }
    return false;
}

bool TieneTrio()
{
    for (int i = 2; i <= 14; ++i)
    {
        if (cuentas[i] == 3)
        {
            return true;
        }
    }
    return false;
}

bool TieneDosPares()
{
    int numPares = 0;
    for (int i = 2; i <= 14; ++i)
    {
        if (cuentas[i] == 2)
        {
            numPares++;
        }
    }

    if (numPares == 2)
    {
        return true;
    }

    return false;
}

bool TienePar()
{
    for (int i = 2; i <= 14; ++i)
    {
        if (cuentas[i] == 2)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 15; ++i)
    {
        cuentas[i] = 0;
    }

    string c1;
    string c2;
    string c3;
    string c4;
    string c5;
    cin >> c1;
    cin >> c2;
    cin >> c3;
    cin >> c4;
    cin >> c5;
    LlenarCuentas(c1);
    LlenarCuentas(c2);
    LlenarCuentas(c3);
    LlenarCuentas(c4);
    LlenarCuentas(c5);

    if (TienePoker())
    {
        cout << "Póker";
    }
    else if (TieneFullHouse())
    {
        cout << "Full house";
    }
    else if (TieneEscalera())
    {
        cout << "Escalera";
    }
    else if (TieneTrio())
    {
        cout << "Trío";
    }
    else if (TieneDosPares())
    {
        cout << "Dos pares";
    }
    else if (TienePar())
    {
        cout << "Par";
    }
    else
    {
        cout << "Carta alta";
    }
}
