#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int segundos = 0;

void controlar_senal (int senalCodigo) {

	switch (senalCodigo) {

		case SIGALRM:
			printf("Señal captada.\n");
			break;
	}
}

int main(int argc, char const *argv[]) {

	pid_t pid;

	pid = fork();

	signal(SIGALRM, controlar_senal);

	system("clear");

	switch(pid){
		case -1: 
			fprintf(stderr, "Error en el fork.\n");
			break;

		//Hijo
		case 0:
			fprintf(stdout, "Proceso hijo. Voy  a realizar un PING.\n");
			system("ping -c 4 8.8.8.8");
			break;

		//Padre
		default:
			//wait(NULL);

			pause();

			printf("Se continua.\n");

			break;
	}

	return 0;
}