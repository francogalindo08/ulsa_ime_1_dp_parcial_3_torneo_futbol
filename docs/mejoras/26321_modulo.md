# Documentación del módulo

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** [Ian silva]  
**Matrícula:** [26321]  
**Módulo:** [tabla de posiciones]  
**Archivo de código:** [include/tabla.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[El módulo arma y muestra la tabla de posiciones de la liga a partir de los
resultados que ya fueron simulados y guardados por el módulo de simulación.
No inventa ni modifica resultados: solo los lee.

Para cada equipo calcula partidos jugados (PJ), ganados (PG), empatados (PE),
perdidos (PP), goles a favor (GF), goles en contra (GC) y puntos (PTS), usando la
regla: victoria = 3 puntos, empate = 1 punto, derrota = 0 puntos. Después ordena a
los equipos del primer al último lugar y los imprime en forma de tabla.

A quien usa el programa le sirve para saber de un vistazo cómo quedó el torneo y
qué equipo va en cada posición.]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[mi modulo recibe los resultados de cada partido que fueron en base a la simulacion ya establecida y los datos registrados, lo que devuelve es una tabla ordenada de primer lugar a sexto con sus respectivos puntos obtenidos durante sus partidos, tambien muestra los goles que anoto y los que recibio cada equipo]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[ Función | Tarea |
|---|---|
| "buscarOAgregarEquipo" | Busca un equipo por nombre en la tabla. Si no está, lo agrega con todas sus estadísticas en cero. Devuelve su posición, o -1 si ya no hay espacio. |
| "registrarPartidoEquipo" | Actualiza las estadísticas de un equipo con un partido: suma PJ, GF y GC, y según el marcador suma PG/PE/PP y los puntos. |
| "vaPrimero" | Compara dos equipos y dice si el primero debe ir arriba: primero por puntos, luego por diferencia de goles y luego por goles a favor. |
| "ordenarTabla" | Ordena la tabla con el método burbuja usando "vaPrimero". |
| "mostrarTablaPosiciones" | Función principal del módulo: valida que haya partidos, llena la tabla recorriendo los resultados, la ordena y la imprime. |]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[- **Registro "EquipoTabla": guarda nombre, pj, pg, pe, pp, gf, gc y pts. Lo elegí
  porque todos esos datos pertenecen al mismo equipo y así viajan juntos.
 **Arreglo `EquipoTabla tabla"MAX_EQUIPOS": guarda a los 6 equipos. Es un arreglo
  porque el número máximo de equipos es fijo y conocido.
 **Registro "Partido" y arreglo "resultados": vienen del módulo de resultados;
  mi módulo solo los lee.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Registros: definición de "EquipoTabla" y uso de sus campos en "registrarPartidoEquipo".
- Arreglos: "tabla[MAX_EQUIPOS]" en "mostrarTablaPosiciones" y el recorrido de "resultados[]`.
- Funciones: las cinco funciones descritas arriba.
- Paso por referencia: "int &totalEquipos" en "buscarOAgregarEquipo` y `EquipoTabla &equipo en "registrarPartidoEquipo".
- Ciclos y condicionales: el recorrido de partidos, el método burbuja y los `if` que deciden victoria, empate o derrota.]

**¿Qué ciclos usaste y por qué esos?**

[Usé solamente ciclos `for", porque en todos los casos se conoce de antemano cuántas
veces hay que repetir:
- En "buscarOAgregarEquipo", un "for" recorre los equipos ya registrados ("totalEquipos`).
- En "mostrarTablaPosiciones", un "for" recorre los partidos guardados ("totalPartidos`).
- En "ordenarTabla", dos "for` anidados implementan el método burbuja.
- Al imprimir, un `for" recorre la tabla para mostrar una fila por equipo.

No usé "while" ni "do-while` porque no había repeticiones que dependieran de una condición desconocida.]

**¿Qué constantes usaste y por qué son constantes?**

 "MAX_EQUIPOS = 6" (definida en "torneo.h`): es el número de equipos de la liga y no
  cambia durante la ejecución. Se usa como tamaño del arreglo "tabla` y como límite para
  no agregar más equipos de los permitidos.


**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[ De "ResultadosPartidos.h": el registro "Partido" y el arreglo de resultados que llena `guardarResultado".
- De `torneo.h": la constante "MAX_EQUIPOS".
- De `utilerias.h": ninguna función.
- De la biblioteca estándar: "setw left" y "right" de "<iomanip>` para alinear las columnas.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[. **El torneo no se ha simulado** ("totalPartidos == 0"): muestra
   "Primero debes simular el torneo." y no imprime la tabla.
2. **Aparece un equipo de más** (ya hay "MAX_EQUIPOS" equipos registrados): `buscarOAgregarEquipo"
   devuelve -1 y ese partido se ignora para no escribir fuera del arreglo. Este caso no
   muestra mensaje porque con la simulación normal (6 equipos) no ocurre.]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[INICIO mostrarTablaPosiciones(resultados, totalPartidos)
  SI totalPartidos = 0 ENTONCES
    Mostrar "Primero debes simular el torneo."
    TERMINAR
  FIN SI

  Crear arreglo tabla[MAX_EQUIPOS] de tipo EquipoTabla
  totalEquipos ← 0

  PARA i ← 0 HASTA totalPartidos - 1
    pos1 ← buscarOAgregarEquipo(tabla, totalEquipos, resultados[i].equipo1)
    pos2 ← buscarOAgregarEquipo(tabla, totalEquipos, resultados[i].equipo2)
    SI pos1 = -1 O pos2 = -1 ENTONCES
      Saltar este partido
    FIN SI
    registrarPartidoEquipo(tabla[pos1], resultados[i].goles1, resultados[i].goles2)
    registrarPartidoEquipo(tabla[pos2], resultados[i].goles2, resultados[i].goles1)
  FIN PARA

  ordenarTabla(tabla, totalEquipos)

  Mostrar "--- TABLA DE POSICIONES ---"
  Mostrar encabezado: POS EQUIPO PJ PG PE PP GF GC PTS
  PARA i ← 0 HASTA totalEquipos - 1
    Mostrar i+1, nombre, pj, pg, pe, pp, gf, gc, pts
  FIN PARA
  Mostrar leyenda de columnas
FIN

buscarOAgregarEquipo(tabla, totalEquipos, nombre)
  PARA i ← 0 HASTA totalEquipos - 1
    SI tabla[i].nombre = nombre ENTONCES DEVOLVER i
  FIN PARA
  SI totalEquipos >= MAX_EQUIPOS ENTONCES DEVOLVER -1
  tabla[totalEquipos] ← nombre con pj, pg, pe, pp, gf, gc, pts en 0
  totalEquipos ← totalEquipos + 1
  DEVOLVER totalEquipos - 1

registrarPartidoEquipo(equipo, golesPropios, golesRival)
  equipo.pj ← equipo.pj + 1
  equipo.gf ← equipo.gf + golesPropios
  equipo.gc ← equipo.gc + golesRival
  SI golesPropios > golesRival ENTONCES
    equipo.pg ← equipo.pg + 1 ; equipo.pts ← equipo.pts + 3
  SINO SI golesPropios = golesRival ENTONCES
    equipo.pe ← equipo.pe + 1 ; equipo.pts ← equipo.pts + 1
  SINO
    equipo.pp ← equipo.pp + 1
  FIN SI

vaPrimero(a, b)
  SI a.pts ≠ b.pts ENTONCES DEVOLVER a.pts > b.pts
  SI (a.gf - a.gc) ≠ (b.gf - b.gc) ENTONCES DEVOLVER (a.gf - a.gc) > (b.gf - b.gc)
  DEVOLVER a.gf > b.gf

ordenarTabla(tabla, totalEquipos)
  PARA i ← 0 HASTA totalEquipos - 2
    PARA j ← 0 HASTA totalEquipos - 2 - i
      SI vaPrimero(tabla[j+1], tabla[j]) ENTONCES intercambiar tabla[j] y tabla[j+1]
    FIN PARA
  FIN PARA
```]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[tomé un equipo y seguí sus 5 partidos
paso por paso, sumando PJ, goles y puntos, y comparé con lo que mostró el programa.]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 8. Reflexión

**¿Qué aprendiste?**

[Inserta aquí tu respuesta]

**¿Qué cambiarías de tu proceso?**

[Inserta aquí tu respuesta]
