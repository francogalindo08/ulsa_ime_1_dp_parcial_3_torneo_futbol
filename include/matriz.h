#pragma once

#include <iostream>
#include <string>
#include "torneo.h"
#include "ResultadosPartidos.h"
#include <iomanip>


void mostrar_matriz(const Registro_equipos r[],
                    const Partido resultados[],
                    int totalPartidos)
{
    std::string matriz[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            matriz[i][j] = (i == j) ? "---" : " ";
        }
    }
    int golesFavor[6] = {0};
int golesContra[6] = {0};

    for (int p = 0; p < totalPartidos; p++)
    {
        int fila = -1;
        int columna = -1;

        for (int i = 0; i < 6; i++)
        {
            if (r[i].nombre == resultados[p].equipo1)
                fila = i;

            if (r[i].nombre == resultados[p].equipo2)
                columna = i;
        }

        if (fila != -1 && columna != -1)
        {
            matriz[fila][columna] =
                to_string(resultados[p].goles1) + "-" +
                to_string(resultados[p].goles2);
            matriz[columna][fila] =
                to_string(resultados[p].goles2) + "-" +
                to_string(resultados[p].goles1);
   
    golesFavor[fila] += resultados[p].goles1;
    golesContra[fila] += resultados[p].goles2;

    golesFavor[columna] += resultados[p].goles2;
    golesContra[columna] += resultados[p].goles1;
        }
    }
    std::cout << "\n     --- MATRIZ DE ENFRENTAMIENTOS ---\n";

    std::cout << "     ";
for(int i = 0; i < 6; i++) {
    cout << setw(6) << i + 1;
}
cout << endl;

    for (int i = 0; i < 6; i++)
    {
        std::cout << std::setw(6) << r[i].nombre;

        for (int j = 0; j < 6; j++)
        {
         std::cout << std::setw(6) << matriz[i][j];
        }

        std::cout << endl;
    }
    int masGoles = 0;
int menosRecibidos = 0;

for (int i = 1; i < 6; i++)
{
    if (golesFavor[i] > golesFavor[masGoles])
    {
        masGoles = i;
    }

    if (golesContra[i] < golesContra[menosRecibidos])
    {
        menosRecibidos = i;
    }
}   
cout << "\nMejor Ofensiva: "
     << r[masGoles].nombre
     << " (" << golesFavor[masGoles] << " goles)\n";

cout << "Mejor defensiva: "
     << r[menosRecibidos].nombre
     << " (" << golesContra[menosRecibidos] << " goles recibidos)\n";
}
