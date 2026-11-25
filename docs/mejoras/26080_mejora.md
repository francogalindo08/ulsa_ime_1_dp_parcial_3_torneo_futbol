# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Diego Alejandro González Cisneros]

**Matrícula:** [26080]  
**Título de la propuesta:** [Implementación de un modo de simulación manual de partidos]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Esta propuesta es una mejora que consiste en agregar una modalidad de simulación manual al sistema de gestión del torneo de fútbol.

Actualmente, los resultados de los partidos se generan de manera aleatoria. Con esta mejora, el usuario podrá elegir si desea generar los resultados automáticamente o ingresar manualmente los goles de cada equipo.

Esto beneficiaría a los usuarios al permitirles registrar resultados de partidos reales, tener mayor control sobre el torneo y comprobar el funcionamiento de la tabla de posiciones con resultados específicos.]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[Registros: Se conserva la estructura Partido, ya que contiene los datos necesarios para almacenar los resultados.

Arreglos: Se mantiene el arreglo de los 15 partidos, debido a que la cantidad de enfrentamientos no cambia.

Constantes: Se mantienen las constantes relacionadas con la cantidad de equipos y partidos.

Funciones: Se agrega una función llamada simularPartidosManual(), encargada de solicitar, validar y almacenar los goles ingresados por el usuario.

Menú: Se agrega un submenú dentro de la opción de simulación para elegir entre el modo automático y el modo manual.

Validaciones: Se verifica que los goles ingresados sean números enteros mayores o iguales a cero.

Los demás módulos podrán seguir utilizando los resultados almacenados sin necesidad de modificar su funcionamiento.]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[INICIO

    Verificar que los 6 equipos estén registrados

    Si faltan equipos
        Mostrar mensaje de error
    Si no

        [NUEVO] Mostrar opciones de simulación:
            1. Simulación automática
            2. Simulación manual

        [NUEVO] Leer modo de simulación
        [NUEVO] Validar modo seleccionado

        Inicializar contador de partidos en 0

        Para i desde 0 hasta 4
            Para j desde i + 1 hasta 5

                Obtener nombres de ambos equipos

                [CAMBIA] Si el modo es automático
                    Generar goles aleatorios entre 0 y 5

                [NUEVO] Si el modo es manual
                    Mostrar los equipos enfrentados
                    Solicitar goles del primer equipo
                    Solicitar goles del segundo equipo

                    Mientras los goles no sean enteros
                    válidos o sean negativos
                        Solicitar nuevamente los goles
                    FinMientras
                FinSi

                Guardar nombres y goles en Partido

                Incrementar contador de partidos

            FinPara
        FinPara

        Mostrar mensaje de simulación completada

    FinSi

FIN]
```
