#pragma once

#include <iostream>
#include <string>
#include "torneo.h"
#include "ResultadosPartidos.h"

void mostrar_matriz(const Registro_equipos r[],
                    const Partido resultados[],
                    int totalPartidos)
{
    string matriz[6][6];
 for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            matriz[i][j] = (i == j) ? "---" : "";
        }
    }
    











}