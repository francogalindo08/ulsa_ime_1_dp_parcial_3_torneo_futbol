#pragma once

#include <iostream>
#include <limits>
#include <string>
#include "torneo.h"
#include "ResultadosPartidos.h"
#include "tabla.h"   // <-- pon aqui el nombre de tu archivo de la tabla
using namespace std;

inline void mostrarCampeon(const Partido resultados[], int totalPartidos)
{
    if (totalPartidos == 0) {
        cout << "Primero debes simular el torneo.\n";
        return;
    }
    