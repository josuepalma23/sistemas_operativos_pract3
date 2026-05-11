#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    FILE *archivo_hijo;
    int pid;
    int i;


    /*
    Funcionalidades del Archivo (ParteB)*/
    archivo_hijo = fopen("archivo_hijo.txt", "w");
    if(archivo_hijo == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }

    pid = fork();

    switch (pid)
    {
    case -1: //Si el pid = -1, ha ocurrido un error
        printf("No se ha podido crear el proceso hijo\n");
        break;
    case 0: // Si el pid = 0, es un proceso hijo

        //Parte B: Escritura en el archivo.
        for(i=1; i<=10; i++){
            fprintf(archivo_hijo, "%d Soy el hijo con PID: %d \n", i, getpid());
            printf("Escribiendo en el archivo de texto\n", i, getpid());
        }

        break;
    default: //Cuando pid != 0 es proceso padre
        for(i=0; i<100; i+=10){ // Parte A: Incremento de la variable de 10 en 10
            printf("%d Soy el padre con PID: %d \n", i, getpid());
        }
        // La función wait detiene el proceso padre y se queda esperando hasta
        // que termine el hijo
        wait(0);
        break;
    }
}
