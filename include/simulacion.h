#pragma once

#include <iostream>
#include <string>
using namespace std;
#include "torneo.h"
#include "ResultadosPartidos.h"

inline void simulacion(Partido resultados[], int &totalPartidos) {

    if (totalPartidos > 0) {
        cout << "El torneo ya fue simulado." << endl;
        return;
    }






for(int i = 0; i < 6; i++)
{
     for(int j = i + 1; j < 6; j++)
     {
        int golesj = numeroAleatorio();
        int golesi = numeroAleatorio();
        
        guardarResultado(
            resultados,
            totalPartidos,
            r[i].nombre,
            r[j].nombre,
            golesi,
            golesj
        );
      
     

cout << r[i].nombre << "      " << golesi << "---" << golesj <<"      " << r[j].nombre  << endl;
cout << "simulacion exitosa" << endl;
     }
  }

}

































