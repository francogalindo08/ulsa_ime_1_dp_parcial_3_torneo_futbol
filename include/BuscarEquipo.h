#pragma once
#include "simulacion.h"
#include "escenario_prueba.h"
#include "torneo.h"
#include "utilerias.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;




// Pasa un texto a minusculas con un apuntador a char
string aMinusculas(string texto)
{
    for (char* p = &texto[0]; *p != '\0'; p++)
        *p = tolower((unsigned char)*p);
    return texto;
}

// Agrega espacios al final para alinear columnas
string rellenar(string texto, int ancho)
{
    while ((int)texto.size() < ancho)
        texto += " ";
    return texto;
}

// Busca el equipo con un apuntador. Regresa su posicion o -1
int buscarEquipo(Registro_equipos* equipos, string nombre)
{
    nombre = aMinusculas(nombre);
    for (Registro_equipos* p = equipos; p < equipos + MAX_EQUIPOS; p++)
        if (aMinusculas(p->nombre) == nombre)
            return p - equipos;
    return -1;
}

// Busca el partido entre equipo y rival. gf = goles del equipo, gc = goles del rival
bool obtenerMarcador(const Partido resultados[], int total, string equipo, string rival, int* gf, int* gc)
{
    const Partido* p = resultados;
    for (int i = 0; i < total; i++, p++)
    {
        if (p->equipo1 == equipo && p->equipo2 == rival) { *gf = p->goles1; *gc = p->goles2; return true; }
        if (p->equipo1 == rival && p->equipo2 == equipo) { *gf = p->goles2; *gc = p->goles1; return true; }
    }
    return false;
}

// Muestra la ficha del equipo que esta en la posicion pos
void mostrarFicha(Registro_equipos* equipos, const Partido resultados[], int total, int pos)
{
    int ganados = 0, empatados = 0, perdidos = 0, golesFavor = 0, golesContra = 0;
    string tabla = "";

    for (int j = 0; j < MAX_EQUIPOS; j++)
    {
        int gf, gc;
        if (j == pos || !obtenerMarcador(resultados, total, (equipos + pos)->nombre, (equipos + j)->nombre, &gf, &gc))
            continue;

        golesFavor += gf;
        golesContra += gc;

        string resultado;
        if (gf > gc)       { ganados++;   resultado = "Ganado"; }
        else if (gf == gc) { empatados++; resultado = "Empatado"; }
        else               { perdidos++;  resultado = "Perdido"; }

        tabla += rellenar((equipos + j)->nombre, 16) + rellenar(to_string(gf) + " - " + to_string(gc), 10) + resultado + "\n";
    }

    cout << "\n--- FICHA DE EQUIPO ---\n"
         << "Equipo: " << (equipos + pos)->nombre << "\n"
         << "Jugados: " << ganados + empatados + perdidos << "\n"
         << "Ganados: " << ganados << "\n"
         << "Empatados: " << empatados << "\n"
         << "Perdidos: " << perdidos << "\n"
         << "Goles a favor: " << golesFavor << "\n"
         << "Goles en contra: " << golesContra << "\n"
         << "Puntos: " << ganados * PUNTOS_VICTORIA + empatados * PUNTOS_EMPATE << "\n\n"
         << rellenar("RIVAL", 16) << rellenar("MARCADOR", 10) << "RESULTADO\n"
         << tabla;
}

// Pide y valida el nombre, busca el equipo y muestra su ficha
void consultarEquipo(Registro_equipos* equipos, const Partido resultados[], int total)
{
    if (total == 0)
    {
        cout << "Primero debes simular el torneo.\n";
        return;
    }

    string nombre;
    while (true)
    {
        nombre = leerCadena("Ingresa el nombre del equipo que buscas: ");
        if ((int)nombre.size() >= MIN_CARACTERES_NOMBRE && (int)nombre.size() <= MAX_CARACTERES_NOMBRE)
            break;
        cout << "El nombre debe tener entre " << MIN_CARACTERES_NOMBRE << " y " << MAX_CARACTERES_NOMBRE << " caracteres.\n";
    }

    int pos = buscarEquipo(equipos, nombre);
    if (pos == -1)
        cout << "\n--- FICHA DE EQUIPO ---\nEquipo no encontrado: " << nombre << "\n";
    else
        mostrarFicha(equipos, resultados, total, pos);
}

