# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Matias Borrego]

**Matrícula:** [26077]  
**Título de la propuesta:** [Escalabilidad del Número de Equipos en el Torneo]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora.

¿Qué agrega?

Mayor flexibilidad para organizar distintos tipos de torneos.
Posibilidad de reutilizar el programa en futuros proyectos o escenarios con más o menos equipos.

¿A quién beneficia?

A los usuarios, porque podrán utilizar el sistema con diferentes cantidades de equipos.
A los desarrolladores, porque el código será más escalable y requerirá menos cambios en futuras versiones del proyecto.]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[Actualmente el arreglo almacena exactamente 6 equipos.
Se tendría que modificar para permitir una cantidad variable de equipos.
Esto permitiría adaptar el torneo a diferentes tamaños sin cambiar el código.

Constantes

El valor fijo de 6 equipos dejaría de ser una constante rígida.
Se reemplazaría por una cantidad definida por el usuario al iniciar el torneo.
Esto haría el sistema más flexible.

Funciones

La función de simulación tendría que ajustarse para trabajar con cualquier número de equipos.
Los ciclos dejarían de depender del valor fijo 6 y utilizarían la cantidad real de participantes.
Así la generación de partidos funcionaría para cualquier torneo válido.

Menú

Se agregaría una opción o solicitud para que el usuario indique cuántos equipos participarán.
Esto permitiría configurar el torneo antes del registro de equipos.

Registros

No sería necesario modificar la estructura Registro_equipos.
Los datos de cada equipo seguirían siendo los mismos; únicamente cambiaría la cantidad de equipos almacenados.]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[INICIO

[NUEVO] Solicitar al usuario la cantidad de equipos participantes.

[NUEVO] Validar que la cantidad de equipos sea válida.

[CAMBIA] Registrar la cantidad de equipos indicada por el usuario.

Verificar que todos los equipos estén registrados.

Si faltan equipos por registrar
    Mostrar mensaje de error.
    Terminar proceso.
FinSi

Mostrar "Simulación iniciada".

[CAMBIA] Para cada equipo i desde 0 hasta cantidadEquipos - 1

    [CAMBIA] Para cada rival j desde i + 1 hasta cantidadEquipos - 1

        Generar goles del equipo i.
        Generar goles del equipo j.]
```
