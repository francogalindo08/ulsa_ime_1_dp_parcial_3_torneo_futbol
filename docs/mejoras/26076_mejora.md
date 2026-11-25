# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

# Propuesta de mejora

Propuesta de mejora elaborada por: [Erick Aguilar]

**Matrícula:** [26076]  
**Título de la propuesta:** Una sola función para armar la tabla de posiciones

## 1. Impacto

Es una **mejora** (refactorización), no una corrección: el programa ya funciona y la propuesta no cambia lo que ve el usuario.

Hoy el bloque que construye la tabla (recorrer los partidos, llamar a `buscarOAgregarEquipo`, registrar a ambos equipos con `registrarPartidoEquipo` y llamar a `ordenarTabla`) está escrito dos veces: en `mostrarTablaPosiciones` (tabla.h) y en `mostrarCampeon` (campeon.h). Esto genera dos problemas:

- Si el equipo cambia un criterio o corrige algo en un lugar y olvida el otro, la tabla y el campeón dejarían de coincidir.
- Cualquier módulo nuevo que necesite la tabla (por ejemplo, la matriz o una consulta de equipo) tendría que copiar el bloque una tercera vez.

Beneficia al equipo que mantiene el código, porque hay un solo lugar donde corregir o ampliar el cálculo, y a quien use el programa, porque la tabla y el campeón siempre salen de la misma fuente.

## 2. Qué implica en el diseño

- **Funciones (nueva):** `armarTabla(resultados, totalPartidos, tabla)` en tabla.h. Recibe los partidos y un arreglo `EquipoTabla` vacío, lo llena, lo ordena y devuelve cuántos equipos quedaron. Se pone en tabla.h porque ahí viven `EquipoTabla` y sus funciones auxiliares, y campeon.h ya incluye ese archivo.
- **Funciones (cambia):** `mostrarTablaPosiciones` deja de armar la tabla por su cuenta y llama a `armarTabla`; solo conserva la impresión.
- **Funciones (cambia):** `mostrarCampeon` también llama a `armarTabla` y conserva solo la lógica de empate y elección manual.
- **Registros, arreglos, constantes y menú:** no cambian. `EquipoTabla`, `MAX_EQUIPOS`, `Partido resultados[]` y las opciones del menú se quedan igual, porque la propuesta no altera el comportamiento.

## 3. Receta

```
INICIO
  declarar resultados[TOTAL_PARTIDOS] y totalPartidos = 0
  REPETIR mostrar menú y leer opción
    SEGÚN opción
      1 registrar equipos
      2 mostrar equipos
      3 simular torneo
      4 mostrar resultados
      5 mostrar tabla de posiciones
      6 mostrar campeón
      7 consultar equipo
      8 mostrar matriz de enfrentamientos
      9 salir
  HASTA elegir salir
FIN

[NUEVO] FUNCIÓN armarTabla(resultados, totalPartidos, tabla) -> totalEquipos
  [NUEVO] totalEquipos = 0
  [NUEVO] PARA cada partido guardado
  [NUEVO]   buscar o agregar equipo1 y equipo2 en la tabla
  [NUEVO]   SI alguno no cupo, saltar el partido
  [NUEVO]   registrar el partido en equipo1 (sus goles, goles del rival)
  [NUEVO]   registrar el partido en equipo2 (sus goles, goles del rival)
  [NUEVO] ordenar la tabla (puntos, diferencia de goles, goles a favor)
  [NUEVO] devolver totalEquipos

FUNCIÓN mostrarTablaPosiciones(resultados, totalPartidos)
  SI totalPartidos == 0, avisar que primero se simula y terminar
  [CAMBIA] totalEquipos = armarTabla(resultados, totalPartidos, tabla)
  imprimir encabezado y una fila por equipo
  imprimir leyenda de abreviaturas

FUNCIÓN mostrarCampeon(resultados, totalPartidos)
  SI totalPartidos == 0, avisar que primero se simula y terminar
  [CAMBIA] totalEquipos = armarTabla(resultados, totalPartidos, tabla)
  maxPuntos = puntos del primer lugar
  contar cuántos equipos tienen maxPuntos (empatados)
  elegido = primer lugar
  SI empatados > 1
    mostrar los empatados numerados
    REPETIR pedir al usuario quién es el campeón
    HASTA que la opción esté entre 1 y empatados
    elegido = opción elegida
  imprimir nombre y puntos del campeón
```

