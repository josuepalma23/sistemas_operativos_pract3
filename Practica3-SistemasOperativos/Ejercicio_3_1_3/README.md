# 3.1.3: Creación de un proceso hijo sin espera 

## a) ¿Cuál es el PID del proceso padre del proceso hijo creado?
En la ejecución del proceso el PID del padre es 31920

## b) Verifique a que proceso es el ID encontrado.
Al ejecutar el comando ps -p 31920 no se detecta ningun proceso activo, esto nos ayuda a confirmar que el proceso padre cumplío con su tiempo de vida y fue eliminado del sistema operativo.

## c) ¿Comó se denomina al tipo de proceso hijo?
Se lo denomina proceso huerfano ya que el padre termina el proceso antes que el hijo.

## d) Modifique el código de la Figura 3 para que el proceso hijo no quede 
huérfano. Demostrar el resultado con el PPID del proceso hijo.

Se añadió la función wait(NULL); en el bloque del padre para esta modificaión.

En esta nueva ejecucion el proceso padre 6927 espero a que su hijo 6930 termine, es por eso que al final aparece el mensaje del padre, indicando que espero al hijo y este no quedó huerfano.

## Demostración

- "Huerfano.JPG" :Comportamiento original

- "Padre.JPG"    : Comportamiento con wait(NULL) incorporado