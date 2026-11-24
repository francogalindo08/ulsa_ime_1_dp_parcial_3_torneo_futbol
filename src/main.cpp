// Proyecto Parcial 3: Sistema de Gestion de un Torneo de Futbol
// Programa principal (bloque de integracion, de todo el equipo).
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
// Ejecutar en macOS:
//   ./torneo
// Ejecutar en Windows:
//   .\torneo.exe
//
// Lean PROYECTO.md antes de escribir codigo.

#include <iostream>
#include <string>
#include "utilerias.h"
#include "torneo.h"
#include "simulacion.h"
#include "torneo.h"
#include "BuscarEquipo.h"
#include "escenario_prueba.h"
#include "tabla.h"
#include "resultadospartidos.h"
#include "matriz.h"

void imprimirLinea(int largo, char simbolo)
{
    for (int i = 0; i < largo; i++)
        std::cout << simbolo;
}

void mostrarMenu()
{
    std::cout << "1.-Registrar equipos\n";
    std::cout << "2.-Mostrar equipos\n";
    std::cout << "3.-Simular torneo\n";
    std::cout << "4.-Mostrar resultados\n";
    std::cout << "5.-Mostrar tabla de posiciones\n";
    std::cout << "6.-Mostrar campeon\n";
    std::cout << "7.-Consultar equipo\n";
    std::cout << "8.-Mostrar matriz de enfrentamientos\n";
    std::cout << "9.-Salir\n";
}
// TODO: incluyan aqui el archivo .h de cada modulo.

int main()
{

    // TODO: declaren aqui los datos del torneo.
    //       No usen variables globales.
    Partido resultados[15] = {};
    int totalPartidos = 0;
    std::cout << "---TORNEO DE FUTBOL---" << std::endl;
    // TODO: menu que se repite hasta elegir "Salir".
    //       Una opcion que no existe se rechaza con un mensaje.
    while (true)
    {
        mostrarMenu();

        int opcion = leerEntero("Selecciona una opcion:");
        std::cout << "Valor leido: " << opcion << std::endl;
        if (opcion < 0 || opcion > 9)
        {
            std::cout << "Numero no valido\n";
        }
        switch (opcion)
        {
        case 1:
        {
            std::cout << "\n---Registrar equipos---\n";
            for (int k = 0; k < 6; k++)
            {
                std::cout << "Nombre del equipo " << k + 1 << ": ";
                std::getline(std::cin, r[k].nombre);
            }
        }
        break;
        case 2:
       
        {
            std::cout << "\n---Nombre de los equipos---\n";
            bool equipos = false;
            for (int k = 0; k < 6; k++){
             if (r[k].nombre.empty())
             {
                equipos = true;
                break;
             }
  
             }
             if (equipos == true)
             {
                cout << "Error: Primero registra todos los equipos.\n";
             }
            else
            {
                for (int k = 0; k < 6; k++)
            {
                std::cout << r[k].nombre << std::endl;
            }
            imprimirLinea(24, '-');
            std::cout << std::endl;
            

            }
            break;
            
          
        }

        case 3:
        {

    
            bool faltanequipos = false;

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
            }
            else
            {
                std::cout << "ENTRO AL CASO 3\n";
                simulacion(resultados, totalPartidos);
            }
            break;
        }
        case 4:
        {
                std::cout << "\n---Resultados de los partidos---\n";

            if (totalPartidos == 0)
            {
                std::cout << "Error: Primero debes simular el torneo.\n";
            }
            else
            {
                mostrarResultados(resultados, totalPartidos);
            }

            break;
        }
     

        case 5:
    {
    Partido resultados[15];
    int totalPartidos = 0;

    simulacion(resultados, totalPartidos);              // simula y guarda
mostrarTablaPosiciones(resultados, totalPartidos);  // solo lee lo guardado y arma la tabla

    break;
    }
    
            // El menu debe permitir ejecutar el escenario obligatorio, en este orden:
            //
            // Paso 1: elegir cada reporte sin equipos registrados (rechazos).
            // Paso 2: intentar simular sin los 6 equipos (rechazo).
            // Paso 3: registrar 6 equipos. Durante el registro, teclear un nombre
            //         repetido con otras mayusculas o minusculas, uno de menos de
            //         3 caracteres, uno de mas de 15 y uno con acento o enie
            //         (rechazos).
            // Paso 4: intentar registrar un equipo mas (rechazo por lista llena).
            // Paso 5: simular en modo de prueba.
            // Paso 6: intentar simular de nuevo (rechazo).
            // Paso 7: mostrar equipos, resultados, tabla y matriz.
            // Paso 8: mostrar al campeon y elegirlo entre los empatados.
            // Paso 9: consultar un equipo existente y uno inexistente (rechazo).
            // Paso 10: teclear una opcion de menu inexistente (rechazo) y salir.
            // Paso 11: ejecutar de nuevo el programa en modo aleatorio y mostrar
            //          resultados, tabla y campeon.}
       
       case 8:
    {
           mostrar_matriz(r, resultados, totalPartidos);
    break;
    }
       
       
        }
    }
       
}
      