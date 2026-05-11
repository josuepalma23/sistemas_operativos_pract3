#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3

void hijoHasAlgo(int numero);

int main ()
{
	int i, pid;
	
	for (i = 1; i <= NUM_PROC; i++)
	{
		pid = fork();
		
		switch(pid)
		{
		case -1:
			fprintf(stderr, "Error al crear el proceso\n");
			break;
			
		case 0:
			hijoHasAlgo(i);
			exit(0);
			
		default:
			printf("Ejecutando el padre\n");
			wait(0);
			printf("Mi hijo %d ha terminado.\n", i);
			break;
		}
	}
	
	return 0;
}

void hijoHasAlgo(int numero)
{
	int i, MAX = 10;
	
	printf("Ejecutando el hijo %d:\n", numero);
	
	if(numero == 1)
	{
		for(i = 1; i <= MAX; i++)
		{
			printf("%d\t", i);
		}
	}
	else if(numero == 2)
	{
		for(i = 2; i <= MAX; i += 2)
		{
			printf("%d\t", i);
		}
	}
	else if(numero == 3)
	{
		for(i = 1; i <= MAX; i++)
		{
			printf("%d\t", i * i);
		}
	}
	printf("\n");
}
