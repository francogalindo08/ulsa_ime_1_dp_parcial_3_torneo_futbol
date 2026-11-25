# Documentación del módulo

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** [Diego Alejandro González Cisneros]  
**Matrícula:** [26080]  
**Módulo:** [2 - Simulación de partidos]  
**Archivo de código:** [ include/simulacion.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[Mi módulo se encarga de simular los partidos de un torneo de fútbol conformado por seis equipos. Mediante la generación de números aleatorios, se asigna una cantidad de goles a cada equipo y se almacenan los resultados de los 15 enfrentamientos.

Su propósito es facilitar la simulación del torneo y proporcionar los resultados necesarios para que los demás módulos puedan calcular la tabla de posiciones, determinar al campeón y realizar consultas.]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Entradas:

Arreglo con los nombres de los seis equipos registrados.

Información sobre el estado del registro de equipos.

Selección de la opción 3 del menú principal.

Salidas:

Generación de los 15 partidos del torneo.

Marcadores aleatorios entre 0 y 5 goles por equipo.

Almacenamiento de los resultados en un arreglo de estructuras Partido.

Mensaje de error cuando no se han registrado todos los equipos.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[La función principal de mi módulo se encarga de recorrer los equipos registrados, generar los enfrentamientos y asignar los goles aleatorios de cada partido. Posteriormente, almacena los nombres de los equipos y sus respectivos marcadores.

También se utiliza la función numeroAleatorio(), que permite generar los goles de cada equipo dentro del rango establecido.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[Utilicé registros y arreglos para organizar la información del torneo.

La estructura Partido almacena los siguientes datos:

Nombre del primer equipo.

Nombre del segundo equipo.

Goles del primer equipo.

Goles del segundo equipo.

Utilicé un arreglo de estructuras Partido porque permite almacenar los 15 enfrentamientos de manera ordenada y facilita el acceso a sus resultados.

Los datos de los equipos y los partidos se manejan mediante arreglos, permitiendo consultar y modificar sus elementos desde las funciones correspondientes.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[La función principal de mi módulo se encarga de recorrer los equipos registrados, generar los enfrentamientos y asignar los goles aleatorios de cada partido. Posteriormente, almacena los nombres de los equipos y sus respectivos marcadores.

También se utiliza la función numeroAleatorio(), que permite generar los goles de cada equipo dentro del rango establecido.]

**¿Qué ciclos usaste y por qué esos?**

[Utilicé dos ciclos for anidados.

El primer ciclo recorre los equipos registrados, mientras que el segundo comienza en la posición siguiente al primer equipo, utilizando j = i + 1.

Esto permite generar los 15 enfrentamientos sin repetir partidos y evita que un equipo juegue contra sí mismo.

Elegí los ciclos for porque la cantidad de equipos y enfrentamientos es conocida desde el inicio.]

**¿Qué constantes usaste y por qué son constantes?**

[Se utilizaron los siguientes valores fijos para establecer las reglas del torneo:

Cantidad de equipos: 6.

Cantidad de partidos: 15.

Cantidad mínima de goles aleatorios: 0.

Cantidad máxima de goles aleatorios: 5.

Estos valores permanecen constantes porque forman parte de las reglas establecidas para el funcionamiento del torneo.]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Reutilicé la función numeroAleatorio() para generar los goles de cada equipo.

También utilicé las estructuras y los datos de los equipos definidos en torneo.h, lo que permitió conectar mi módulo con el registro de equipos y compartir los resultados con los demás integrantes.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[El programa verifica que los seis equipos estén registrados antes de iniciar la simulación.

En caso de que no estén registrados todos los equipos, se muestra el siguiente mensaje:

"Primero registra todos los equipos".

Esto evita generar enfrentamientos con información incompleta.]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[INICIO

    Verificar que los 6 equipos estén registrados

    Si faltan equipos por registrar
        Mostrar "Primero registra todos los equipos"
    Si no

        Inicializar contador de partidos en 0

        Para i desde 0 hasta 4

            Para j desde i + 1 hasta 5

                Obtener nombre del primer equipo
                Obtener nombre del segundo equipo

                Generar goles del primer equipo
                entre 0 y 5

                Generar goles del segundo equipo
                entre 0 y 5

                Guardar nombres y goles en Partido

                Incrementar contador de partidos

            FinPara

        FinPara

    FinSi

FIN]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Sí, realicé pruebas para comprobar que los seis equipos generaran un total de 15 partidos.

Durante el desarrollo corregí la lógica de los ciclos para evitar enfrentamientos repetidos y revisé el almacenamiento de los resultados. También corregí el manejo de las variables globales y la validación del registro de equipos antes de iniciar la simulación.]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Simulación completa del torneo] | [6 equipos registrados] | [Generar 15 partidos] | [Se generaron los 15 partidos] |
| 2 | [Generación de marcadores] | [Opción 3 del menú] | [Goles entre 0 y 5] | [Marcadores dentro del rango] |
| 3 | [Simulación sin registrar equipos] | [Opción 3 sin registrar equipos] | [Mostrar mensaje de error] | [Pendiente de confirmar] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Cómo generar los partidos sin repetir enfrentamientos] | [Utilicé dos ciclos for anidados con j = i + 1] |
| 2 | [Problemas con las variables globales] | [Corregí su declaración y manejo dentro del programa] |
| 3 | [Evitar la simulación sin registrar equipos] | [Agregué una condición para verificar el registro antes de simular] |

## 8. Reflexión

**¿Qué aprendiste?**

[Aprendí a utilizar estructuras y arreglos para almacenar información, así como a trabajar con ciclos anidados, funciones y números aleatorios. También aprendí la importancia de las validaciones y de trabajar en equipo utilizando GitHub para integrar las diferentes partes de un programa.]

**¿Qué cambiarías de tu proceso?**

[Organizaría mejor mis ideas antes de comenzar a programar y realizaría más pruebas antes de integrar mi código con el de mis compañeros. De esta manera podría detectar errores más rápido y aprovechar mejor mi tiempo]
