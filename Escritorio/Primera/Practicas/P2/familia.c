/*Crear un programa ​ familia.c en C que arranque un proceso hijo y un 
* proceso nieto. Cada proceso padre esperará a la finalización de su hijo.

*   a. Cada proceso debe imprimir su número identificador de proceso (el
* abuelo, el padre y el hijo) y el número identificador de proceso de su
* padre; luego, tendrá que esperar 15 segundos hasta acabar.

*   b. Cread una captura de pantalla de un comando ps en el que se vean
* estos 3 procesos con sus respectivos ids. (5 puntos)*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	
	pid_t pid;

	pid = fork();

	switch (pid) {

		case -1:
			fprintf(stderr, "Error en el primer fork.\n");
			exit(-1);
			break;

		case 0:

			pid = fork();

			switch (pid) {

				case -1:
					fprintf(stderr, "Error en el segundo fork.\n");
					exit(-1);
					break;

				case 0:

					fprintf(stdout, "El proceso nieto dice que tiene el PID %d, y el proceso que lo generó (proceso padre) el PID: %d\n", getpid(), getppid());
					sleep(15);
					break;

				default:
					fprintf(stdout, "El proceso padre dice que tiene el PID %d, y el proceso que lo generó (proceso abuelo) el PID: %d\n", getpid(), getppid());
					wait(NULL);
					break;
			}

			break;

		default:
			fprintf(stdout, "El proceso abuelo dice que tiene el PID %d, y la terminal que lo lanzó el PID %d\n", getpid(), getppid());
			wait(NULL);
			break;
	}

	return 0;
}

			
