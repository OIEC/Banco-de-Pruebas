#include <iostream>
using namespace std;

char reglasLunes[3];
char reglasMartes[3];
char reglasMiercoles[3];
char reglasJueves[3];
char reglasViernes[3];
char reglasSabado[3];
char reglasDomingo[3];

void ProcesarPlaca(char d)
{
    bool contieneLunes = false;
    for (int i = 0; i < 3; ++i)
    {
        if (reglasLunes[i] == d)
        {
            contieneLunes = true;
        }
    }
    if (contieneLunes)
    {
        cout << "lunes"
             << " ";
    }

    bool contieneMartes = false;
    for (int i = 0; i < 3; ++i)
    {
        if (reglasMartes[i] == d)
        {
            contieneMartes = true;
        }
    }
    if (contieneMartes)
    {
        cout << "martes"
             << " ";
    }

    bool contieneMiercoles = false;
    for (int i = 0; i < 3; ++i)
    {
        if (reglasMiercoles[i] == d)
        {
            contieneMiercoles = true;
        }
    }
    if (contieneMiercoles)
    {
        cout << "miércoles"
             << " ";
    }

    bool contieneJueves = false;
    for (int i = 0; i < 3; ++i)
    {
        if (reglasJueves[i] == d)
        {
            contieneJueves = true;
        }
    }
    if (contieneJueves)
    {
        cout << "jueves"
             << " ";
    }

    bool contieneViernes = false;
    for (int i = 0; i < 3; ++i)
    {
        if (reglasViernes[i] == d)
        {
            contieneViernes = true;
        }
    }
    if (contieneViernes)
    {
        cout << "viernes"
             << " ";
    }

    bool contieneSabado = false;
    for (int i = 0; i < 3; ++i)
    {
        if (reglasSabado[i] == d)
        {
            contieneSabado = true;
        }
    }
    if (contieneSabado)
    {
        cout << "sábado"
             << " ";
    }

    bool contieneDomingo = false;
    for (int i = 0; i < 3; ++i)
    {
        if (reglasDomingo[i] == d)
        {
            contieneDomingo = true;
        }
    }
    if (contieneDomingo)
    {
        cout << "domingo"
             << " ";
    }

    if (!(contieneLunes || contieneMartes || contieneMiercoles || contieneJueves || contieneViernes || contieneSabado || contieneDomingo))
    {
        cout << "No circula";
    }
}

int main()
{
    char d1;
    char d2;
    char d3;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    reglasLunes[0] = d1;
    reglasLunes[1] = d2;
    reglasLunes[2] = d3;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    reglasMartes[0] = d1;
    reglasMartes[1] = d2;
    reglasMartes[2] = d3;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    reglasMiercoles[0] = d1;
    reglasMiercoles[1] = d2;
    reglasMiercoles[2] = d3;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    reglasJueves[0] = d1;
    reglasJueves[1] = d2;
    reglasJueves[2] = d3;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    reglasViernes[0] = d1;
    reglasViernes[1] = d2;
    reglasViernes[2] = d3;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    reglasSabado[0] = d1;
    reglasSabado[1] = d2;
    reglasSabado[2] = d3;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    reglasDomingo[0] = d1;
    reglasDomingo[1] = d2;
    reglasDomingo[2] = d3;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string placa;
        cin >> placa;
        ProcesarPlaca(placa[7]);
        cout << endl;
    }
}
