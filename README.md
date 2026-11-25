# Proyecto Parcial 3: Sistema de Gestión de un Torneo de Fútbol

> **Importante:** este README es del equipo y debe tener aportaciones de todos los integrantes. La guía completa está en [`PROYECTO.md`](PROYECTO.md).

## 1. Integrantes

| Módulo | Matrícula | Nombre | Usuario de GitHub | Tema |
| --- | --- | --- | --- | --- |
| 1 | [26084] | [Enrique Talamás Ortiz] | [EnriqueTalamas] | Registro de equipos |
| 2 | [26080] | [Diego Alejando González Cisneros] | [DiegoAGC24] | Simulación de partidos |
| 3 | [26077] | [Matias Borrego Flores] | [matiasborregoflores012] | Simulación de partidos |
| 4 | [26321] | [Ian Rodrigo Silva Cazarin] | [Silvaian29] | Tabla de posiciones |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Clasificación y campeón |
| 6 | [26079] | [Franco Gael  Galindo Esparza] | [Francogalindo08] | Consultas |
| 7 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Matriz de enfrentamientos |

> **Nota:** en los equipos de 5 integrantes, todos contribuyen al módulo 6. En esa fila escriban "Todo el equipo".

## 2. Opciones del menú

Escriban las opciones del menú en el orden en que aparecen en el programa.
1. Registrar equipo
2. Mostrar equipos
3. Simular torneo
4. Mostrar resultados
5. Mostrar tabla de posiciones
6. Mostrar campeon
7. Consultar equipo
8. Mostrar matriz de enfrentamientos
9. Salir


## 3. Cómo compilar y ejecutar

Desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
```

Para ejecutar en macOS:

```
./torneo
```

Para ejecutar en Windows:

```
.\torneo.exe
```

## 4. Tipos de datos abstractos (TDA)

Describan cada TDA que diseñaron como registro (`struct`): qué datos guarda, qué operaciones tiene y por qué.
*Struct Registro_equipos: lo que hace es tomar los nombres que luego se le sumo un for para que sean 6 equipos.
[TDA: Registro_equipos

Datos que guarda:

Nombre del equipo (nombre).

Operaciones que tiene:

Registrar equipos.
Mostrar equipos registrados.
Proporcionar los nombres a los módulos de simulación, consulta y tabla de posiciones.

¿Por qué se eligió?

Porque permite agrupar la información de cada equipo en una sola estructura y facilita su acceso desde los distintos módulos del sistema.
TDA: Partido

Datos que guarda:

Nombre del primer equipo (equipo1).
Nombre del segundo equipo (equipo2).
Goles del primer equipo (goles1).
Goles del segundo equipo (goles2).

Operaciones que tiene:

Almacenar los resultados de cada partido simulado.
Ser utilizado por los módulos de resultados, tabla de posiciones, campeón y matriz de enfrentamientos.
Facilitar la consulta de los marcadores generados durante la simulación.

¿Por qué se eligió?

Porque reúne en una sola estructura toda la información necesaria de un encuentro de fútbol.
TDA: EquipoTabla

Datos que guarda:

Nombre del equipo.
Partidos jugados (PJ).
Partidos ganados (PG).
Partidos empatados (PE).
Partidos perdidos (PP).
Goles a favor (GF).
Goles en contra (GC).
Puntos obtenidos (PTS).

Operaciones que tiene:

Calcular y almacenar estadísticas del torneo.
Generar la tabla de posiciones.
Apoyar la determinación del campeón.

¿Por qué se eligió?

Porque concentra todas las estadísticas necesarias de cada equipo para construir la clasificación del torneo y mostrar el rendimiento de los participantes.]

## 5. Reglas del programa

Escriban las decisiones que el equipo tomó y que el cálculo a mano necesita. Por ejemplo: cómo se obtiene la abreviatura y qué pasa si dos se repiten.

[Inserta aquí tu respuesta]

## 6. Equipos del escenario

Los 6 equipos que registran en el escenario obligatorio, en orden de registro.

| # | Nombre | Abreviatura |
| --- | --- | --- |
| 1 | [Cruz azul] | [Cruz] |
| 2 | [Pumas] | [Pum] |
| 3 | [Santos] | [San] |
| 4 | [Rayados] | [Raya] |
| 5 | [America] | [Ame] |
| 6 | [Saltillofc] | [Salti] |

## 7. Cálculo a mano

Ejecuten una corrida en modo aleatorio y copien aquí sus 15 resultados.

```
arg  1 - 5  mex
arg  3 - 5  bra
arg  0 - 3  usa
arg  1 - 0  fra
arg  4 - 0  esp
mex  0 - 4  bra
mex  2 - 4  usa
mex  1 - 0  fra
mex  4 - 2  esp
bra  3 - 3  usa
bra  3 - 1  fra
bra  3 - 3  esp
usa  0 - 3  fra
usa  2 - 0  esp
fra  5 - 2  esp
```
**Tabla de posiciones:**

| Equipo | PJ | PG | PE | PP | GF | GC | PTS |
| --- | --- | --- | --- | --- | --- | --- | --- |
| bra | 5 | 3 | 2 | 0 | 18 | 10 | 11 |
| usa | 5 | 3 | 1 | 1 | 12 | 8 | 10 |
| mex | 5 | 3 | 0 | 2 | 12 | 11 | 9 |
| fra | 5 | 2 | 0 | 3 | 9 | 7 | 6 |
| arg | 5 | 2 | 0 | 3 | 9 | 13 | 6 |
| esp | 5 | 0 | 1 | 4 | 7 | 18 | 1 |

**Campeón o equipos empatados en el primer lugar:** bra, con 11 puntos (no hay empate en el primer lugar)  
**Mejor ataque:** bra, con 18 goles a favor  
**Mejor defensa:** fra, con 7 goles en contra

**¿La salida del programa coincidió con el cálculo a mano? Si no, ¿qué corrigieron?**

[AL principio no por unos errores de sintaxis y conexion entre codigos]

## 8. Receta del menú

Receta en pseudocódigo del programa principal: el menú y cómo se conecta con cada módulo.

```
[INICIO

Mostrar título del torneo

Mientras el usuario no elija "Salir"

    Mostrar menú

    Leer opción

    Si la opción es inválida
        Mostrar "Número no válido"
    FinSi

    Segun la opción hacer

        Caso 1: Registrar equipos
            Solicitar los nombres de los 6 equipos
            Guardar los nombres en el arreglo de equipos

        Caso 2: Mostrar equipos
            Verificar que existan equipos registrados
            Si faltan equipos
                Mostrar mensaje de error
            Si no
                Mostrar la lista de equipos
            FinSi

        Caso 3: Simular torneo
            Verificar que existan los 6 equipos registrados
            Si faltan equipos
                Mostrar mensaje de error
            Si no
                Llamar al módulo de simulación
                Generar los 15 partidos
                Guardar los resultados
            FinSi

        Caso 4: Mostrar resultados
            Verificar que exista una simulación
            Si no existe
                Mostrar mensaje de error
            Si existe
                Llamar al módulo de resultados
                Mostrar los 15 partidos simulados
            FinSi

        Caso 5: Mostrar tabla de posiciones
            Verificar que exista una simulación
            Si no existe
                Mostrar mensaje de error
            Si existe
                Llamar al módulo de tabla
                Calcular y mostrar la clasificación
            FinSi

        Caso 6: Mostrar campeón
            Llamar al módulo campeón
            Mostrar el equipo campeón

        Caso 7: Consultar equipo
            Llamar al módulo de búsqueda
            Mostrar la información del equipo solicitado

        Caso 8: Mostrar matriz de enfrentamientos
            Llamar al módulo de matriz
            Mostrar los enfrentamientos entre equipos

        Caso 9: Salir
            Terminar el programa

    FinSegun

FinMientras

FIN

Conexión con los módulos
torneo.h: registra y almacena los equipos.
simulacion.h: genera los 15 partidos y los marcadores.
resultadospartidos.h: muestra los resultados almacenados.
tabla.h: calcula y muestra la tabla de posiciones.
campeon.h: determina y muestra al campeón.
BuscarEquipo.h: permite consultar información de un equipo.
matriz.h: muestra la matriz de enfrentamientos.
utilerias.h: proporciona funciones auxiliares como lectura de datos y generación de números aleatorios.]
```

## 9. Documentación individual

Enlace a la documentación y a la propuesta de mejora de cada integrante.

| Módulo | Documentación | Propuesta de mejora |
| --- | --- | --- |
| 1 | [Enrique Talamas ] | [Poner las estadisticas de cada equipo o las variables de esa forma tenemos toda la informacion en un struct] |
| 2 | [https://github.com/francogalindo08/ulsa_ime_1_dp_parcial_3_torneo_futbol/blob/main/docs/26077_MODULO.md] | [https://github.com/francogalindo08/ulsa_ime_1_dp_parcial_3_torneo_futbol/blob/main/docs/mejoras/26077_MEJORA.md] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | Franco Galindo | [ mostrar la racha y los resultados destacados del equipo] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el módulo 6. En equipos de cinco, agreguen una fila con el enlace a docs/modulo_6/modulo.md, sin propuesta de mejora. -->

## 10. Cambios a la base común

Si cambiaron una constante de `include/torneo.h`, expliquen qué cambiaron y por qué. Si no cambiaron nada, escriban "Sin cambios".

si, se agregaron los struct en la parte de abajo
