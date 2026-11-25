# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Franco Galindo]

**Matrícula:** [26079]  
**Título de la propuesta:** [Propuesta: mostrar la racha y los resultados destacados del equipo]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[es una mejora ya que se podria ver con mayor detalle el desempeño de los equipos]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[estaria en el mismo modulo de consultar ficha,Crear variables mayorGoleada, mayorDerrota y rachaActual antes del ciclo.]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[si no se ha simulado el torneo, mostrar mensaje y salir.
 Pedir el nombre del equipo hasta que su longitud sea válida.
 Buscar el equipo ; si no existe, mostrar "Equipo no encontrado" y salir.
 Inicializar contadores de ganados, empatados, perdidos y goles.
 [NUEVO] Inicializar mayorGoleada, mayorDerrota y el rival de cada una.
   . Acumular goles y clasificar el resultado (G/E/P).
7. [CAMBIA] Imprimir las estadísticas y los puntos.
8. [NUEVO] Imprimir la mayor goleada y la mayor derrota (o "ninguna" si no hubo).]
```
