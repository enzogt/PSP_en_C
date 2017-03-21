#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

	int a = 5;
	int b = 3;

	pid_t pid;
	pid_t pid_hijo_terminado;

	pid = fork();

	if (pid == -1){
		fprintf(stderr, "> Error en la creacion del hijo.\n");
		exit(-1);
	}

	if (pid == 0){
		//Hijo.
		fprintf(stdout, "> El proceso hijo tiene el PID es: %d\n", getpid());
		sleep(2);

	} else {
		//Padre.
		fprintf(stdout, ">El proceso original (padre) tiene el PID: %d\n", getpid());
		
		fprintf(stdout, ">> Esperando a que termine el hijo...\n");
		pid_hijo_terminado = wait(NULL);
		fprintf(stdout, ">> El hijo %d terminó.\n", pid_hijo_terminado);
	}

	return 0;
}