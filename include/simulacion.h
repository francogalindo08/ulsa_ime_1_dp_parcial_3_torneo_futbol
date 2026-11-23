
#pragma once

#include <iostream>
#include <string>
#include "torneo.h"
#include "ResultadosPartidos.h"

using namespace std;

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

            cout << r[i].nombre << "  "
                 << golesi << " - "
                 << golesj << "  "
                 << r[j].nombre << endl;
        }
    }

    cout << "\nSimulacion exitosa." << endl;
}













