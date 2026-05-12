#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int pid;

int main () {
    pid = fork();
    switch (pid)
    {
        case -1:
            printf ("\nNo he podido crear el proceso hijo");
            break;
        case 0:
            // Este es el hijo
            printf ("\nSoy el hijo, mi PID es %d y mi PPID es %d", getpid(), getppid());
            // El wait(0) aquí en el hijo es lo que analizaremos 
            wait(0);
            break;
        default:
            // Este es el padre
            printf ("\nSoy el padre, mi PID es %d y el PID de mi hijo es %d", getpid(), pid);
            wait(NULL);
            //"wait(NULL);" Espera al hijo para evitar que quede huérfano
    }
    printf ("\nFinal de ejecución de %d \n", getpid());
    exit (0);
}