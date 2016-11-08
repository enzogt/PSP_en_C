#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
	
	int fd[2];
	int retorno;
	unsigned long long int resultado = 1;
	int objetivo;
	int medio_objetivo;
	int i;
	pid_t pid;

	/*******************************/

	if(argc != 2){
		fprintf(stderr, "A cascarla.\n");
		exit(-1);
	}

	objetivo = atoi(argv [1]);

	if(objetivo > 20){
		fprintf(stderr, "A cascarla.\n");
		exit(-1);
	}

	retorno = pipe(fd);

	if(retorno == -1){
		fprintf(stderr, "Error en el pipe\n");
		exit(-1);
	}

	medio_objetivo = objetivo / 2;

	pid = fork();


	switch (pid) {
		case -1:
			fprintf(stderr, "Error en el fork.\n");
			exit(-1);
			break;

		//Hijo.
		case 0:
			//fprintf(stdout, "Proceso hijo ejecutandose.\n");

				for (i = objetivo; i > medio_objetivo; i--){

					resultado *= i;
				}

			fprintf(stdout, "Hijo ha calculado: %llu\n", resultado);
			write(fd[1], &resultado, sizeof(unsigned long long int));

			break;

		//Padre.
		default:
			//fprintf(stdout, "Proceso padre ejecutandose.\n");

			for (i = medio_objetivo; i > 0; i--){

				resultado *= i;
			}

			fprintf(stdout, "Padre ha calculado: %llu\n", resultado);

			wait(NULL);

			/*Se calcula una vez se tienen las 2 partes*/
			unsigned long long int resultado_hijo;
			read(fd[0], &resultado_hijo, sizeof(unsigned long long int));

			resultado *= resultado_hijo;

			fprintf(stdout, "> El factorial total de %d es: %llu\n", objetivo, resultado);


			//Comprobación.
			resultado = 1;
			for (i = objetivo; i > 0; i--) resultado *= i;
			fprintf(stdout, "Comprobacion %d! es: %llu\n", objetivo, resultado);
			break;
	}

	return 0;
}