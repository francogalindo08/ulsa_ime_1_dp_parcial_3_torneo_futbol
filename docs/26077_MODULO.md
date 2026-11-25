# Documentación del módulo

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** [Matias Borrego]  
**Matrícula:** [26077]  
**Módulo:** [Simulación de partidos]  
**Archivo de código:** [simulacion.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[El módulo de simulación se encarga de generar automáticamente los 15 partidos del torneo utilizando el formato todos contra todos entre los 6 equipos registrados. Además, crea marcadores aleatorios para cada encuentro mediante la función de números aleatorios proporcionada por el proyecto.]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Recibe:

Los nombres de los 6 equipos previamente registrados en el arreglo r.
Los números aleatorios generados por la función numeroAleatorio(), que se utilizan para simular los goles de cada partido.
No recibe datos directamente del teclado durante la simulación.

Produce:

Produce los 15 partidos simulados y sus marcadores, almacenándolos en la estructura Partido para ser utilizados por otros módulos.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[simulacion()

Genera los 15 partidos del torneo mediante el formato todos contra todos.
Selecciona los dos equipos que participan en cada encuentro.
Genera de forma aleatoria los goles de cada equipo utilizando la función numeroAleatorio().
Produce los resultados de los partidos para que puedan ser utilizados por otros módulos del sistema.
Muestra un mensaje indicando que la simulación fue realizada correctamente.

numeroAleatorio()

Genera un número entero aleatorio entre 0 y 5.
Se utiliza para simular la cantidad de goles anotados por un equipo en cada partido.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[Registro (struct):

Se utiliza el registro Registro_equipos para almacenar la información de cada equipo.
Actualmente contiene el atributo nombre.
Se eligió porque permite agrupar los datos relacionados con cada equipo en una sola estructura.

Arreglo:

Se utiliza el arreglo r[6] de tipo Registro_equipos.
Se eligió porque el torneo trabaja con una cantidad fija de 6 equipos.
Permite acceder fácilmente a cada equipo mediante índices (r[0], r[1], ..., r[5]).]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Registros (struct):

Se utilizan mediante la estructura Registro_equipos.
Esta estructura almacena la información de cada equipo participante, específicamente su nombre.
Durante la simulación se accede a los equipos registrados mediante expresiones como r[i] y r[j].

Arreglos de registros:

Se utiliza el arreglo r[6], que almacena los seis equipos del torneo.
Permite recorrer y seleccionar los equipos que participarán en cada partido.

Ciclos anidados:

Se demuestran en la función simulacion().
El primer ciclo recorre cada equipo del torneo.
El segundo ciclo recorre los rivales restantes utilizando la condición j = i + 1.
Gracias a estos ciclos se generan automáticamente los 15 partidos de un torneo de todos contra todos sin repetir enfrentamientos]

**¿Qué ciclos usaste y por qué esos?**

[¿Qué ciclos usaste y por qué esos?

Se utilizaron dos ciclos for anidados dentro de la función simulacion().

El primer ciclo for recorre los 6 equipos registrados en el arreglo.
El segundo ciclo for recorre los equipos restantes para generar los enfrentamientos sin repetir partidos.

Se eligieron ciclos for porque la cantidad de equipos es conocida y fija (6 equipos). Además, los ciclos anidados permiten generar automáticamente los 15 partidos de un torneo todos contra todos, evitando que un equipo juegue contra sí mismo o que un partido se repita.]

**¿Qué constantes usaste y por qué son constantes?**

[6 equipos participantes, porque el proyecto establece que el torneo se juega con exactamente seis equipos.

15 partidos, porque en una competencia de todos contra todos a una vuelta, seis equipos generan quince enfrentamientos.

Rango de goles de 0 a 5, definido en la función numeroAleatorio(), ya que los marcadores se generan dentro de ese intervalo durante la simulación.

Estos valores se consideran constantes porque representan reglas fijas del proyecto y no deben modificarse durante la ejecución del programa.]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[De utilerias.h:

numeroAleatorio()
Se utiliza para generar la cantidad de goles de cada equipo en los partidos simulados.
Permite obtener marcadores aleatorios entre 0 y 5 goles.

De torneo.h:

Se reutiliza la estructura Registro_equipos.
Se utiliza para acceder a los nombres de los equipos registrados.
También se utiliza el arreglo r[6], donde se almacenan los equipos participantes.

De otros módulos:

Se aprovechan los datos generados por el módulo de registro de equipos, ya que la simulación necesita que los equipos hayan sido capturados previamente para poder generar los enfrentamientos.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[
Intentar simular sin que los 6 equipos estén registrados.
Mensaje: "Error: Primero registra todos los equipos."

Intentar simular nuevamente un torneo ya generado.
Mensaje: "Error: El torneo ya fue simulado."]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[INICIO

Verificar que existan 6 equipos registrados

Si no hay 6 equipos registrados
    Mostrar "Error: primero registre los 6 equipos"
    Terminar simulación
FinSi

Mostrar "Simulación iniciada"

Para cada equipo i desde 0 hasta 5

    Para cada rival j desde i + 1 hasta 5

        Generar goles del equipo i
        Generar goles del equipo j

        Registrar el enfrentamiento

        Mostrar:
            Nombre equipo i
            Marcador (goles i - goles j)
            Nombre equipo j

    FinPara

FinPara

Mostrar "Simulación exitosa"

FIN]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Sí. Antes de terminar la programación probé la lógica de la simulación utilizando nombres de equipos de ejemplo y siguiendo manualmente los enfrentamientos del torneo.]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Generación de enfrentamientos del torneo] | [6 equipos registrados (m, nb, v, e, t, g)] | [Generar exactamente 15 partidos sin repetir enfrentamientos ni enfrentar un equipo consigo mismo] | [Se generaron 15 partidos correctos y sin repeticiones] |
| 2 | [Generación de marcadores aleatorios] | [6 equipos registrados y ejecución de la simulación] | [Cada partido debe recibir un marcador aleatorio entre 0 y 5 goles para cada equipo] | [Todos los partidos mostraron marcadores válidos dentro del rango esperado] |
| 3 | [Caso de rechazo: simular sin equipos registrados] | [Seleccionar la opción "Simular torneo" sin registrar los 6 equipos] | [Mostrar un mensaje de error y no generar partidos] | [Se mostró el mensaje de rechazo y la simulación no se ejecutó] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [No sabía cómo generar los 15 partidos sin repetir enfrentamientos ni hacer que un equipo jugara contra sí mismo.] | [Analicé la lógica del torneo todos contra todos y utilicé dos ciclos for anidados. Además, hice que el segundo ciclo comenzara en i + 1 para evitar partidos repetidos.] |
| 2 | [Intenté mostrar un equipo usando cout << r[0]; y el programa marcaba error.] | [Revisé la estructura Registro_equipos y entendí que debía acceder al atributo nombre, ya que r[0] es un registro completo y no una cadena de texto.] |
| 3 | [La simulación generaba advertencias (unused variable) para golesi y golesj.] | [Identifiqué que las variables se estaban creando pero aún no se utilizaban. Entendí que desaparecerán cuando los resultados se almacenen o se usen en otros módulos del proyecto.] |

## 8. Reflexión

**¿Qué aprendiste?**

[a usar ciclos anidados, usar bool para validaciones, usar structs]

**¿Qué cambiarías de tu proceso?**

[nada]
