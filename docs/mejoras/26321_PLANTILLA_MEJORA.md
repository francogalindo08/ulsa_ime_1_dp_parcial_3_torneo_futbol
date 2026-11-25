# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Ian Silva]

**Matrícula:** [26321]  
**Título de la propuesta:** [Columna de diferencia de goles (DG)]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora: el programa ya funciona, pero la tabla puede ser más clara.

la tabla muestra GF y GC, pero no la diferencia de goles. Cuando dos equipos
empatan en puntos, el programa ya usa esa diferencia para decidir quién va arriba,
pero el usuario no la ve y no entiende por qué un equipo quedó por encima del otro

La propuesta agrega:
- Una columna DG (GF − GC) en la tabla, para que el criterio de desempate sea visible.]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

| Parte | Cambio | Justificación |
|---|---|---|
| **Registro "EquipoTabla" | Se agrega el campo `int dg`. | Guardar la diferencia de goles de cada equipo junto con sus demás estadísticas. |
| **Función "buscarOAgregarEquipo"*| Inicializa `dg` en 0 al agregar un equipo. | Todos los campos deben empezar en cero para que las cuentas sean correctas. |
| **Función "registrarPartidoEquipo" | Después de sumar goles, actualiza `dg = gf - gc`. | Mantener la DG al día cada vez que se registra un partido. |
| **Función "mostrarTablaPosiciones" | Imprime la columna DG (con signo + si es positivo) | Mostrar el criterio de desempate |
## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[Inserta aquí tu respuesta]
```
