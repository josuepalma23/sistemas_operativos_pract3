#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	/* Creamos el proceso hijo */
	int pid = fork();

	switch(pid)
	{
		case -1:
			/* Error al crear el proceso hijo */
			fprintf(stderr, "No se pudo crear el proceso hijo\n");
			exit(1);

		case 0:
			/* --- PROCESO HIJO ---
			 Usamos execl para ejecutar ls -l.
			 execl reemplaza completamente la imagen del proceso hijo.
			 Parametros
			 1) /bin/ls  ->  ruta completa del ejecutable
			 2) ls       ->  nombre del programa (argv[0])
			 3) -l       ->  argumento
			 4) NULL     ->  indica el fin de los argumentos */
		printf("Soy el hijo con PID=%d\n", getpid());
		execl("/bin/ls", "ls", "-l", NULL);

		/* Esta linea solo se ejecuta si execl fallo */
		fprintf(stderr, "Error al ejecutar execl\n");
		exit(1);

	default:
		/* --- PROCESO PADRE ---
		 Imprime su PID y el de su hijo,
		 luego espera a que el hijo termune con wait () */
		printf("Soy el padre con PID=%d, mi hijo tiene PID=%d\n", getpid(), pid);
		wait(0);
		printf("Mi hijo con PID=%d ha terminado\n", pid);
	}
	return 0;
}


