#include <iostream>
#include <vector>

int main()
{
    int num_partidos;
    std::string resultados_condores, resultados_iguanas;
    std::cin >> num_partidos;
    std::vector<int> goles_condores(num_partidos);
    std::vector<int> goles_iguanas(num_partidos);
    std::vector<std::vector<int>> maximo_valor_de_area(num_partidos + 1, std::vector<int>(num_partidos + 1, 0));

    std::cin >> resultados_condores;
    for (int i = 0; i < num_partidos; i++)
    {
        int goles;
        std::cin >> goles;
        goles_condores[i] = goles;
    }

    std::cin >> resultados_iguanas;
    for (int i = 0; i < num_partidos; i++)
    {
        int goles;
        std::cin >> goles;
        goles_iguanas[i] = goles;
    }
    int local_max = 0;
    int posibles_goles_actual;
    for (int i = 1; i <= num_partidos; i++)
    {
        for (int j = 1; j <= num_partidos; j++)
        {
            if ((resultados_condores[i - 1] == 'W' && resultados_iguanas[j - 1] == 'L' && (goles_condores[i - 1] > goles_iguanas[j - 1])) 
                || (resultados_condores[i - 1] == 'L' && resultados_iguanas[j - 1] == 'W' && (goles_condores[i - 1] < goles_iguanas[j - 1])))
            {
                posibles_goles_actual = goles_condores[i - 1] + goles_iguanas[j - 1];
            }
            else
            {
                posibles_goles_actual = 0;
            }
            local_max = std::max(posibles_goles_actual + maximo_valor_de_area[i - 1][j - 1], std::max(maximo_valor_de_area[i - 1][j], maximo_valor_de_area[i][j - 1]));
            maximo_valor_de_area[i][j] = local_max;
        }
    }
    std::cout << maximo_valor_de_area[num_partidos][num_partidos] << std::endl;
    return 0;
}
