
#pragma once

#include <iostream>
#include <string>
#include "torneo.h"
#include "resultadospartidos.h"

using namespace std;
bool validacionsimulacion() { bool faltanequipos = false;

            for (int i = 0; i < 6; i++)
            {
                if (r[i].nombre.empty())
                {
                    faltanequipos = true;
                    break;
                }
            }
           if (faltanequipos == true)
{
    cout << "Error: Primero registra todos los equipos.\n";
    return false;
}
else
{
    return true;
}
        }

inline void simulacion(Partido resultados[], int &totalPartidos) {

    if (totalPartidos > 0) {
        cout << "El torneo ya fue simulado." << endl;
        return;
    }

    cout << "\n--- SIMULACION DEL TORNEO ---\n";

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {

            int golesi = numeroAleatorio();
            int golesj = numeroAleatorio();
                


            guardarResultado(
                resultados,
                totalPartidos,
                r[i].nombre,
                r[j].nombre,
                golesi,
                golesj
            );
      
        }

    }
        cout << "\nSimulacion exitosa." << endl;

}













