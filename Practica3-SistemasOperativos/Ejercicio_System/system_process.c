#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int pid;
int main(){
	pid = fork();
	switch(pid){
	case -1:
		printf("No se pudo crear el proceso hijo\n");
		break;
	case 0:
		sleep(0);
		printf("\n=== PROCESO HIJO ===\n");
		printf("Mi PID es %d\n", getpid());
		printf("\nListando procesos del sistema...\n\n");
		system("ps -aux | head");
		printf("\nFin del proceso hijo\n");
		break;
	default:
		printf("\n=== PROCESO PADRE ===\n");
		printf("Mi PID es %d\n", getpid());
		printf("El PID de mi hijo es %d\n", pid);
		wait(0);
		printf("\nEl hijo ha terminado\n");
		break;
	}
	exit(0);
}
