# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Hacer un historial de torneos para comparar resultados de los equipos con sus torneos que jugaron en el pasado.]

**Matrícula:** [26084]  
**Título de la propuesta:** [Historial de equipos]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una ocurrencia y lo que agrega es el historial de los partidos jugados de anteriores temporadas de cada equipo, beneficia a todos y concidero que es importante en una liga no solo para darle merito a los equipos con mas tiempo, sino ver que equipo tiene mejores resultados]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[Pues nada mas modificaria el menu y tomaria los nombres de los registros. Se agregaria un case nuevo en el que pregunte el nombre del equipo y le muestre su historial.    ]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[1.- Agregar un nuevo case
2.- Mostrar el título "Historial de Torneos".
3.- Verificar que los 6 equipos hayan sido registrados.
4.- Si no estan los 6 equipos, mostrar un mensaje de error y regresar al menú.
5.-Crear una estructura para almacenar la información del historial de cada equipo.
6.-Recorrer el arreglo r[6] que contiene los nombres de los equipos.
7.-Copiar el nombre de cada equipo al historial.
8.-Tomar las estadísticas del torneo actual goles a favor, goles en contra, mejor ofensiva y mejor defensiva.
9.-Mostrar la información del historial de cada equipo.]
```
