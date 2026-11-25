# Documentación del módulo

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** [Erick Aguilar]  
**Matrícula:** [26076]  
**Módulo:** Mostrar campeón (opción 6 del menú)  
**Archivo de código:** `campeon.h`

## 2. Propósito

El módulo determina quién es el campeón del torneo a partir de los resultados ya simulados. Si un solo equipo tiene más puntos que los demás, lo muestra directamente. Si dos o más equipos empatan en puntos en el primer lugar, le pide al usuario que elija manualmente al campeón entre los empatados. Le sirve a quien usa el programa para obtener un campeón definitivo aunque la tabla no lo decida sola.

## 3. Entradas y salidas

**Entradas:**
- Parámetros: `resultados` (arreglo constante de `Partido` con los partidos guardados) y `totalPartidos` (cuántos hay guardados).
- Teclado: solo si hay empate, el número del equipo elegido como campeón (entre 1 y la cantidad de empatados).

**Salidas:**
- Si `totalPartidos == 0`: imprime "Primero debes simular el torneo."
- Si hay empate: imprime los puntos del empate y la lista numerada de equipos empatados, y pide la elección.
- Siempre que se llega al final: imprime `Campeon: <nombre>` y `Puntos: <puntos>`.
- La función no devuelve valor (`void`).

## 4. Decisiones de diseño

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

El módulo tiene una sola función propia, `mostrarCampeon`, que hace cuatro tareas en orden: (1) arma la tabla de posiciones recorriendo los partidos, (2) la ordena, (3) cuenta cuántos equipos tienen los puntos del primer lugar y, si son más de uno, pide la elección manual, y (4) imprime al campeón. Para armar y ordenar la tabla reutiliza funciones del módulo de la tabla de posiciones, en lugar de reescribirlas.

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

- **Registro `Partido`:** guarda los equipos y goles de cada partido. Ya existía en `ResultadosPartidos.h`.
- **Registro `EquipoTabla`:** acumula nombre, partidos, goles y puntos de cada equipo. Lo elegí porque agrupa en un solo dato todo lo que se necesita para ordenar y desempatar.
- **Arreglo `EquipoTabla tabla[MAX_EQUIPOS]`:** es local a la función, porque el campeón se calcula cada vez que se pide y no necesita guardarse.
- **Paso de datos:** `resultados` entra como arreglo con `const`, para que la función pueda leerlo pero no modificarlo. `totalPartidos` entra por valor, porque solo se lee. `totalEquipos` se pasa por referencia a `buscarOAgregarEquipo`, porque esa función lo incrementa al agregar equipos. `tabla` se pasa como arreglo a `ordenarTabla`, que lo reordena directamente.

**¿Dónde demuestras los temas asignados a tu módulo?**

[Ajusta esta respuesta a los temas que te asignaron. Con el código actual puedes señalar:]
- Arreglos y registros: `EquipoTabla tabla[MAX_EQUIPOS]` y el uso de `Partido resultados[]`.
- Paso por referencia: `totalEquipos` en `buscarOAgregarEquipo`.
- Arreglo constante como parámetro: `const Partido resultados[]`.
- Validación de entrada: el ciclo `while (!valida)` con `cin.clear()` y `cin.ignore(...)`.

**¿Qué ciclos usaste y por qué esos?**

- `for` para recorrer los partidos y armar la tabla: se sabe cuántos son (`totalPartidos`).
- `for` para contar los equipos con los puntos del primer lugar y para imprimir la lista de empatados: se recorre una cantidad conocida de equipos.
- `while (!valida)` para pedir la elección: no se sabe cuántos intentos fallidos habrá, así que se repite hasta recibir una opción válida.

**¿Qué constantes usaste y por qué son constantes?**

Uso `MAX_EQUIPOS` (de `torneo.h`) como tamaño del arreglo `tabla`. Es constante porque la cantidad de equipos del torneo es fija (6) y así todos los módulos comparten el mismo valor.

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

- De `tabla.h`: la estructura `EquipoTabla` y las funciones `buscarOAgregarEquipo`, `registrarPartidoEquipo` y `ordenarTabla`.
- De `torneo.h`: la constante `MAX_EQUIPOS`.
- De `ResultadosPartidos.h`: la estructura `Partido`.
- De `utilerias.h`: ninguna. La lectura de la opción se hace con `cin` directamente. [Si tu equipo pide usar `leerEntero`, puedes cambiarla y actualizar esta respuesta.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?**

- Torneo sin simular (`totalPartidos == 0`): "Primero debes simular el torneo."
- Elección de campeón inválida (letra, o número fuera del rango de empatados): "Opcion invalida. Intenta de nuevo." y se vuelve a pedir.

## 5. Receta

```
FUNCIÓN mostrarCampeon(resultados, totalPartidos)
  SI totalPartidos == 0
    imprimir "Primero debes simular el torneo."
    terminar

  totalEquipos = 0
  PARA cada partido guardado
    buscar o agregar equipo1 en la tabla
    buscar o agregar equipo2 en la tabla
    SI alguno no cupo, saltar el partido
    registrar el partido en equipo1 (sus goles, goles del rival)
    registrar el partido en equipo2 (sus goles, goles del rival)

  ordenar la tabla (puntos, diferencia de goles, goles a favor)

  maxPuntos = puntos del primer lugar
  empatados = 0
  PARA cada equipo
    SI sus puntos == maxPuntos, empatados = empatados + 1

  imprimir "--- CAMPEON DEL TORNEO ---"
  elegido = 0

  SI empatados > 1
    imprimir "Hay un empate en el primer lugar con <maxPuntos> puntos."
    PARA i desde 1 hasta empatados
      imprimir i y nombre del equipo
    valida = falso
    MIENTRAS valida sea falso
      pedir "Elige al campeon: "
      SI la lectura fue número Y está entre 1 y empatados
        valida = verdadero
      SI NO
        imprimir "Opcion invalida. Intenta de nuevo."
        limpiar el error de entrada y descartar el resto de la línea
    elegido = opción - 1

  imprimir "Campeon: " y nombre del equipo en la posición elegido
  imprimir "Puntos: " y puntos de ese equipo
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Sí, la probé a mano con los resultados de una simulación de 6 equipos (mex, bra, usa, fra, arg, esp): bra quedó primero con 9 puntos y el segundo lugar con 8, así que no hay empate y la receta llega directo a imprimir al campeón. También la probé con el escenario de empate de dos equipos con 10 puntos, que obliga a pasar por la elección manual. [Agrega aquí qué corregiste de tu receta original, si algo.]

## 6. Pruebas

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Campeón sin simular | Opción 6 con el torneo sin simular | "Primero debes simular el torneo." | [Llena al ejecutar] |
| 2 | Campeón sin empate | Opción 6 con bra en primer lugar con 9 puntos y el segundo con 8 | `Campeon: bra` y `Puntos: 9`, sin pedir elección | [Llena al ejecutar] |
| 3 | Empate en primer lugar | Modo de prueba con 2 equipos empatados con 10 puntos; elegir la opción 2 | Lista los 2 equipos, pide elección e imprime el equipo 2 con 10 puntos | [Llena al ejecutar] |
| 4 | Elección inválida (caso límite) | En el empate, teclear "x", luego "0", luego "3" y por último un número válido | Muestra "Opcion invalida. Intenta de nuevo." en cada intento y acepta solo el válido | [Llena al ejecutar] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | La tabla de posiciones mostraba resultados distintos a los de la opción 4 | En el `case 5` del `main` se declaraban un `resultados` y un `totalPartidos` locales que ocultaban a los reales y volvían a simular. Los quité y dejé que el caso solo lea los resultados ya guardados. |
| 2 | En el `case 6` se imprimía una línea del menú ("6. Mostrar campeon") junto con el campeón | Eliminé ese `cout` del caso, porque la línea pertenece solo a `mostrarMenu`. |
| 3 | Al compilar salió "cannot open output file torneo.exe: Permission denied" | No era un error del código: Windows no podía sobrescribir el ejecutable porque el programa seguía abierto. Cerré el programa y volví a compilar. |

## 8. Reflexión

**¿Qué aprendiste?**

Aprendí que declarar una variable con el mismo nombre dentro de un bloque (`case`) crea una copia nueva que oculta a la original, y que eso puede producir resultados inconsistentes sin que el compilador marque error. También aprendí a reutilizar funciones de otro módulo en lugar de reescribirlas, y a validar la entrada del teclado con `cin.clear()` y `cin.ignore()` para que el programa no se cicle.

**¿Qué cambiarías de tu proceso?**

Probaría cada opción del menú con los datos reales desde el principio, y no solo mi módulo por separado, para detectar a tiempo problemas de integración como el del `case 5`. También escribiría la receta completa antes de programar, y movería el armado de la tabla a una función compartida para no repetirlo en el campeón y en la tabla de posiciones.
