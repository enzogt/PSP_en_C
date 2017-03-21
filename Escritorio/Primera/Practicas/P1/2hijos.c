/*Crear un programa ​ 2hijos.c en C que arranque dos procesos hijo nuevos
* utilizando la función fork() El proceso padre esperará con un wait a 
* sus hijos. (5 puntos)

*   a. Cada proceso debe imprimir su número identificador de proceso (el
* padre y los dos hijos) y el número identificador de proceso de su padre; 
* luego, tendrá que esperar 15 (función ​ sleep()​ ) segundos hasta acabar.

*   b. Cread una captura de pantalla de un comando ​ ps o ​ top en el que 
* se vean estos 3 procesos con sus respectivos ids.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	//Variables.
	pid_t pid = 0;


	//Programa.
	pid = fork();


	//Se acaba si da fallo el fork
	if (pid == -1){
		fprintf(stderr, "Error en el primer fork.\n");
		exit(-1);
	}


	//Proceso hijo.
	if (pid == 0) {

		fprintf(stdout, "El primer proceso hijo tiene el PID: %d, y su progenitor tiene el PID: %d.\n", getpid(), getppid());
		sleep(15);
	}

	//Proceso padre.
	else {

		//Se crea el segundo proceso hijo.
		pid = fork();


		//Se acaba si da fallo el fork
		if (pid == -1){
			fprintf(stderr, "Error en el segundo fork.\n");
			exit(-1);
		}


		//Proceso hijo.
		if (pid == 0) {

			fprintf(stdout, "El segundo proceso hijo tiene el PID: %d, y su progenitor tiene el PID: %d.\n", getpid(), getppid());
			sleep(15);
		}

		//Proceso padre.
		else {

			fprintf(stdout, "El proceso padre tiene el PID: %d, y su progenitor tiene el PID: %d.\n", getpid(), getppid());
			wait(NULL);

		}
	}

	//Fin del main.
	return 0;
}
