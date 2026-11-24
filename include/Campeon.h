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

        registrarPartidoEquipo(tabla[pos1], resultados[i].goles1, resultados[i].goles2);
        registrarPartidoEquipo(tabla[pos2], resultados[i].goles2, resultados[i].goles1);
    }

    ordenarTabla(tabla, totalEquipos);

    // 2) Contar cuantos equipos tienen los puntos del primer lugar
    int maxPuntos = tabla[0].pts;
    int empatados = 0;
    for (int i = 0; i < totalEquipos; i++) {
        if (tabla[i].pts == maxPuntos) {
            empatados++;
        }
    }

    cout << "\n--- CAMPEON DEL TORNEO ---\n";

    int elegido = 0; // posicion del campeon en la tabla

    // 3) Si hay empate, se decide manualmente
    if (empatados > 1) {
        cout << "Hay un empate en el primer lugar con " << maxPuntos << " puntos.\n";

        for (int i = 0; i < empatados; i++) {
            cout << (i + 1) << ". " << tabla[i].nombre << "\n";
        }

        int opcion = 0;
        bool valida = false;

        while (!valida) {
            cout << "Elige al campeon: ";
            if (cin >> opcion && opcion >= 1 && opcion <= empatados) {
                valida = true;
            } else {
                cout << "Opcion invalida. Intenta de nuevo.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        