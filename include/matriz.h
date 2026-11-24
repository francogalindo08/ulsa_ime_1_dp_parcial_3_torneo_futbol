#pragma once

#include <iostream>
#include <string>
#include "torneo.h"
#include "ResultadosPartidos.h"

void mostrar_matriz(const Registro_equipos r[],
                    const Partido resultados[],
                    int totalPartidos)
{
    std::string matriz[6][6];
 for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            matriz[i][j] = (i == j) ? "---" : "";
        }
    }
    for(int p = 0; p < totalPartidos; p++)
    {
        int fila = -1;
        int columna = -1;

        for(int i = 0; i < 6; i++)
        {
            if(r[i].nombre == resultados[p].equipo1)
                fila = i;

            if(r[i].nombre == resultados[p].equipo2)
                columna = i;
        }

        if(fila != -1 && columna != -1)
        {
            matriz[fila][columna] =
                to_string(resultados[p].goles1)
                + "-" +
                to_string(resultados[p].goles2);
        }
    }

  
   











