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

    // 1) Armar la tabla igual que en mostrarTablaPosiciones
    EquipoTabla tabla[MAX_EQUIPOS];
    int totalEquipos = 0;

    for (int i = 0; i < totalPartidos; i++) {
        int pos1 = buscarOAgregarEquipo(tabla, totalEquipos, resultados[i].equipo1);
        int pos2 = buscarOAgregarEquipo(tabla, totalEquipos, resultados[i].equipo2);

        if (pos1 == -1 || pos2 == -1) {
            continue;
        }
        