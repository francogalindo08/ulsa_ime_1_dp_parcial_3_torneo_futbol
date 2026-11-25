# Documentación del módulo

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** [Franco Galindo]  
**Matrícula:** [26079]  
**Módulo:** [consulta de equipos]  
**Archivo de código:** [BuscarEquipo.h]

# 2. Propósito

Consulta un equipo por nombre después de simular el torneo y muestra su ficha: jugados, ganados, empatados, perdidos, goles a favor y en contra, puntos y una tabla con el marcador contra cada rival.

## 3. Entradas y salidas

**Entradas:** el nombre del equipo 
**Salidas:** imprime la ficha del equipo o un mensaje de error. Las funciones auxiliares devuelven posición, `bool` o `string`.

## 4. Decisiones de diseño

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**
- `aMinusculas`: pasa texto a minúsculas.
- `rellenar`: alinea columnas con espacios.
- `buscarEquipo`: regresa la posición del equipo o -1.
- `obtenerMarcador`: busca el partido entre dos equipos y entrega los goles.
- `mostrarFicha`: calcula e imprime las estadísticas.
- `consultarEquipo`: valida, pide el nombre y muestra la ficha.

**¿Qué estructuras de datos usa y cómo pasas los datos?**
Usa los arreglos de `Registro_equipos` y `Partido`. Los equipos van por apuntador, los resultados como arreglo `const`, `gf` y `gc` por apuntador para devolver dos valores, y los textos por valor para no alterar el original.

**¿Dónde demuestras los temas asignados a tu módulo?** (*)
Apuntadores  (`p++`, `equipos + pos`, `p - equipos`), paso por apuntador (`int* gf`) y manejo de arreglos y cadenas.

**¿Qué ciclos usaste y por qué esos?**
`for` cuando se sabe cuántos elementos recorrer, `while` en `rellenar` hasta llegar al ancho, y `while (true)` con `break` para repetir la petición hasta que el nombre sea válido.

**¿Qué constantes usaste y por qué son constantes?**
`MAX_EQUIPOS`, `MIN_CARACTERES_NOMBRE`, `MAX_CARACTERES_NOMBRE`, `PUNTOS_VICTORIA` y `PUNTOS_EMPATE`. Son reglas fijas del torneo y evitan números mágicos.

**¿Qué funciones reutilizaste?**
`leerCadena` de `utilerias.h`, y las estructuras y constantes de `torneo.h` y `simulacion.h`.

**¿Qué casos de rechazo maneja?**
- Sin simular: "Primero debes simular el torneo."
- Equipo inexistente: "Equipo no encontrado: <nombre>".

## 5. Receta

```
consultarEquipo:
    si total == 0: mostrar mensaje y salir
    repetir: leer nombre hasta que su longitud sea válida
    pos = buscarEquipo(nombre)
    si pos == -1: "Equipo no encontrado"
    si no: mostrarFicha(pos)

mostrarFicha:
    para cada rival j distinto de pos:
        si hay marcador: sumar goles, clasificar G/E/P, agregar fila
    imprimir estadísticas, puntos = G*PUNTOS_VICTORIA + E*PUNTOS_EMPATE, y tabla
```

**¿Probaste tu receta a mano? ¿Qué corregiste?** (*)
Sí. Corregí que el marcador se invierte cuando el equipo es `equipo2` y que hay que saltarse al propio equipo.

## 6. Pruebas

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Consulta normal | Equipo existente | Ficha completa | Correcto |
| 2 | Mayúsculas mezcladas | "tIgReS" | Encuentra el equipo | Correcto |
| 3 | Equipo inexistente | "Zzzzz" | "Equipo no encontrado" | Correcto |
| 4 | Sin simular (límite) | `total == 0` | "Primero debes simular el torneo." | Correcto |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | Marcador invertido cuando era `equipo2` | Intercambié `gf` y `gc` en el segundo `if` |
| 2 | No encontraba nombres con otra capitalización | Creé `aMinusculas` |
| 3 | Tabla desalineada | Creé `rellenar` |

## 8. Reflexión

**¿Qué aprendiste?**
A usar apuntadores para recorrer arreglos y devolver varios valores, y a dividir el problema en funciones pequeñas.

**¿Qué cambiarías de tu proceso?**
Probaría la receta a mano completa y cada función por separado antes de integrarlas.
