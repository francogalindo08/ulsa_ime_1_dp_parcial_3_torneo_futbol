
#pragma once

#include <iostream>
#include <string>
using namespace std;

// Estructura para guardar cada partido
struct Partido {
    string equipo1;
    string equipo2;
    int goles1;
    int goles2;
};

// Funcion para guardar resultados
inline void guardarResultado(
    Partido resultados[],
    int &totalPartidos,
    string equipo1,
    string equipo2,
    int goles1,
    int goles2)
{
    if (totalPartidos >= 15) {
        return;
    }

    resultados[totalPartidos].equipo1 = equipo1;
    resultados[totalPartidos].equipo2 = equipo2;
    resultados[totalPartidos].goles1 = goles1;
    resultados[totalPartidos].goles2 = goles2;

    totalPartidos++;
}

// Funcion para mostrar resultados
inline void mostrarResultados(
    const Partido resultados[],
    int totalPartidos)
{
    if (totalPartidos == 0) {
        cout << "Primero debes simular el torneo.\n";
        return;
    }

    cout << "\n--- RESULTADOS DEL TORNEO ---\n";

    for (int i = 0; i < totalPartidos; i++) {
        cout << resultados[i].equipo1 << "  "
             << resultados[i].goles1 << " - "
             << resultados[i].goles2 << "  "
             << resultados[i].equipo2 << endl;
    }
}