#include<iostream>
using namespace std;

int golesTotales[23];
int minutosTotales[23];
int minutoEntrante[23];
int minutoSaliente[23];

// Esta función lee los jugadores que van a comenzar el partido, llenando el array de minutos entrantes.
// Se llena minutoSaliente a 90 por defecto a todos los jugadores. 
// Si no entran durante el partido, se sabrá por el valor de minutoEntrante. 
void ProcesarInicio()
{   
    for (int i = 1; i <= 22; ++i)
    {
        minutoEntrante[i] = -1;
        minutoSaliente[i] = 90;
    }

    for (int i = 1; i <= 11; ++i)
    {
        int j;
        cin >> j;
        minutoEntrante[j] = 0;
    }
}

// Esta función acumula el gol al jugador indicado.
void ProcesarGol(int minuto)
{
    int j;
    cin >> j;
    golesTotales[j]++;
}

// Esta función sustituye dos jugadores x y. El minuto saliente del jugador x se convierte en minuto entrante del jugador y.
void ProcesarSustitucion(int minuto)
{
    int j1;
    int j2;
    cin >> j1;
    cin >> j2;
    minutoSaliente[j1] = minuto;
    minutoEntrante[j2] = minuto;
}

// Esta función imprime el promedio goleador del jugador hasta el minuto dado.
float ProcesarPromedio(int j, int minuto)
{
    int minutosJugadosHastaEseEntonces = minutosTotales[j];

    // Si el jugador está en el partido, sumamos los minutos acumulados. 
    // Para esto chequeamos que minutoEntrante sea mayor o igual a 0.
    if (minutoEntrante[j] >= 0 && minutoSaliente[j] == 90) 
    {
        minutosJugadosHastaEseEntonces += minuto - minutoEntrante[j];
    }
    else if (minutoEntrante[j] >= 0 && minutoSaliente[j] < 90)
    {
        // Si el jugador entró en el partido pero salió, la duración es minutoSaliente - minutoEntrante.
        minutosJugadosHastaEseEntonces += minutoSaliente[j] - minutoEntrante[j];
    }

    // Si el jugador no ha jugado nada hasta este entonces, regresar 0.
    if (minutosJugadosHastaEseEntonces == 0)
    {
        return 0;
    }
    
    return (golesTotales[j] * 90.0f) / minutosJugadosHastaEseEntonces;
}

// Esta función imprime el promedio goleador del subconjunto de jugadores que se pida hasta el minuto dado.
void ProcesarPromedio(int minuto)
{
    int numJ;
    cin >> numJ;
    float promedioTotal = 0.0f;

    for (int i = 1; i <= numJ; ++i)
    {
        int j;
        cin >> j;
        float promedio = ProcesarPromedio(j, minuto);
        promedioTotal += promedio;
    }

    cout << promedioTotal << endl; 
}

// Esta función acumula la cantidad de minutos jugados del partido (saliente - entrante) de cada jugador al total.
void AcumularEstadisticas()
{
    for (int i = 1; i <= 22; ++i)
    {
        if (minutoEntrante[i] != -1)
        {
            minutosTotales[i] += minutoSaliente[i] - minutoEntrante[i];
        }
    }
}


int main ()
{
    for (int i = 0; i <= 22; ++i)   
    {
        golesTotales[i] = 0;
        minutosTotales[i] = 0;
        minutoEntrante[i] = 0;
        minutoSaliente[i] = 0;
    }

    int numPartidos;
    cin >> numPartidos;
 
    for (int i = 1; i <= numPartidos; ++i)
    {
        char c;
        cin >> c;

        if (c != 'C')
        {
            // Error leyendo la entrada.
            return -1;
        }

        ProcesarInicio();

        // Procesamos la entrada evento a evento mientras no termine el partido.
        while (1)
        {
            char m;
            cin >> m;

            if (m == 'T') 
            {
                break;
            }

            if (m != 'M')
            {
                // Error leyendo la entrada.
                return -1;
            }

            // Asumimos que leemos un evento M.
            int minuto;
            cin >> minuto;
            
            char evento;
            cin >> evento;

            if (evento == 'G')
            {
                ProcesarGol(minuto);
            }
            else if (evento == 'S')
            {
                ProcesarSustitucion(minuto);
            }
            else
            {
                if (evento != 'P')
                {
                    // Error leyendo la entrada.
                    return -1;
                }

                ProcesarPromedio(minuto);
            }
        }

        AcumularEstadisticas();
    }
}