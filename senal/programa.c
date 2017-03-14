#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int segundos = 0;

void controlar_senal (int senalCodigo) {

	switch (senalCodigo) {
		//CTRL ^ C
		case SIGINT:
			fprintf(stdout, "Has hecho CTRL C.\n");
			break;

		//Terminal Stop (CTRL Z)
		case SIGTSTP:
			fprintf(stdout, "Has hecho CTRL Z.\n");
			break;

		case SIGKILL:
			fprintf(stdout, "Has hecho SIGKILL.\n");
			break;

		case SIGALRM:
			//fprintf(stdout, "Han pasado 2 segundos.\n");
			system("clear");
			segundos++;
			fprintf(stdout, "Han pasado %d minutos y %d segundos.\n", (segundos / 60), (segundos % 60) );

			if (segundos == 61){
				signal(SIGALRM, SIG_DFL);
			}

			break;
	}
}

int main(int argc, char const *argv[])
{

	signal(SIGINT, controlar_senal);

	signal(SIGTSTP, controlar_senal);

	signal(SIGKILL, controlar_senal);

	signal(SIGALRM, controlar_senal);
	
	while(1){
		alarm(1);
		//printf("Esperando señal...\n");
		pause();
	}
	

	return 0;
}