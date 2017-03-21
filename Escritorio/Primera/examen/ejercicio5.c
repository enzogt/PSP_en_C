#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>


void senalHijo();
void alarmaPadre ();
void replicarSenal();

pid_t pid;

int main(int argc, char const *argv[])
{
	
	int iteraciones;

	//Creación del nuevo proceso.
	pid = fork();

	switch (pid) {

		case -1:
			fprintf(stderr, "Error en la creacion del hijo.\n");
			exit(-1);
			break;

		//Proceso hijo.
		case 0:
			signal(SIGUSR1, senalHijo);

			iteraciones = 5;

			while (iteraciones > 0){

				pause();
				iteraciones--;
			}

			signal(SIGUSR1, SIG_DFL);
			fprintf(stdout, "%s\n", "Ya he terminado.");
			break;

		//Proceso padre.
		default:
			signal(SIGALRM, alarmaPadre);
			

			iteraciones = 4;

			while (iteraciones > 0){
				iteraciones--;
				alarm(1);
				pause();
				
			}

			signal(SIGALRM, SIG_DFL);

			//Se podría hacer directamente llamando a la señal de alarma.
			signal(SIGTSTP, replicarSenal); 

			//Se espera a la señal manual.
			pause();

			wait(NULL); //Espera a la finalizacion del padre.

			break;
		}

	return 0;
}

void senalHijo () {

	fprintf(stdout, "%s\n", "Soy el hijo, he recibido un señal.");
}

void alarmaPadre() {

	kill(pid, SIGUSR1);
}

void replicarSenal (){
	alarmaPadre();
}