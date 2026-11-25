
## 1. Autor

**Nombre:** [Enrique Talamas Ortiz]  
**Matrícula:** [26084]  
**Módulo:** [Registro de equipos y matriz]  
**Archivo de código:** [matriz.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[Lo que hace mi modulo es que el usuario pueda escribir el nombre de de los 6 equipos con algunas restrincciones y despues de eso que es la opcion 1 la opcion 2 lo que hace es mostrar esos 6 nombres]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[En lo que son mis modulos esta la entrada de los normbres de los equipos y tambien la salida de estos. De la matriz toma la entrada de los nombres y de los juegos que se declara en otro modulo y los acomoda en una matriz y despues de eso le da salida al equipo can mayores goles y al equipo con menos goles en contra.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[Las funcion es que tienen mi modulo es dar de alta los nombres de los equipos y imprimirlos, ademas de acomodar en una matriz los juegos de cada equipo.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[Mi módulo utiliza un registro (struct) llamado Registro_equipos, que almacena el nombre de cada equipo mediante el atributo nombre. También utiliza arreglos como Registro_equipos r[6], golesFavor[6] y golesContra[6] para guardar información de los equipos y sus estadísticas. Tambien la matriz[6][6] para representar los enfrentamientos.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Los temas asignados se demuestran en la función mostrar_matriz(). Ahí utilizo una matriz bidimensional para almacenar los resultados de los enfrentamientos entre equipos.]

**¿Qué ciclos usaste y por qué esos?**

[Use ciclos con for porque me parecen los más comodos para usar y que entiendo de mejor manera.]

**¿Qué constantes usaste y por qué son constantes?**

[const Registro_equipos r[] y const Partido resultados[],la función solo consulta la información y no necesita modificar los datos recibidos. ]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Reutilice la estructura Registro_equipos de torneo.h y la estructura Partido de ResultadosPartidos.h para obtener la información de los equipos y los resultados de los partidos.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[Mi módulo verifica que los equipos existan antes de registrar los resultados utilizando una variable booleana, bool equipos.]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[1.-Crear un arreglo r[6] de tipo Registro_equipos para almacenar los nombres de los equipos.
2.-Cuando el usuario selecciona la opción 1 del menú, mostrar el mensaje "Registrar equipos".
3.-Recorrer el arreglo con un ciclo for desde la posición 0 hasta la 5.
4.-Solicitar el nombre de cada equipo y guardarlo en r[k].nombre.
5.-Cuando el usuario selecciona la opción 2, mostrar el mensaje "Nombre de los equipos".
6.-Crear una variable booleana equipos e inicializarla en false.
7.-Recorrer nuevamente el arreglo de equipos con un ciclo for.
8.-Verificar si algún nombre está vacío usando r[k].nombre.empty().
9.-Si se encuentra un nombre vacío, asignar true a la variable equipos y salir del ciclo con break.
10.-Si todos los equipos tienen nombre, continuar mostrando o procesando la información de los equipos.
11.-Si existe al menos un equipo sin registrar, indicar que primero deben registrarse todos los equipos antes de continuar.]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Si, corregi en la receta y en el codigo los casos de rechazo.]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Nombre con numero] | [La tusa2008] | [nombre aceptado] | [Nombre registrado] |
| 2 | [sin caracteres] | [nada ] | [Ningun nombre y que lo vuelva a pedir para seguir con las siguientes funciones] | [Error: Primero registra todos los equipos.] |
| 3 | [Equipo con mas de 15 caracteres] | [jbefbefbefbefbefbiefbiebf ] | [Nombre valido] | [Nombre registrado] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Como acomodar bien la matriz] | [Preguntandole al Profesor] |
| 2 | [Como funciona una matriz de 2 dimensiones] | [Probando con los datos de filas y columnas] |
| 3 | [Para que se utiliza = {0}; ] | [ Investigando ya que queria que los goles se inicializaran en 0] |
= {0}; 
## 8. Reflexión

**¿Qué aprendiste?**

[Aprendi a usar nuevos comandos y a hacer una matriz dimensional. Ademas de mejoarar mis habilidades de trabajo en equipo.]

**¿Qué cambiarías de tu proceso?**

[Agregaria una restriccion para que no se pudiece usar el mismo nombre 2 veces y que el sistema te avice cuando un nombre ya esta en uso.]