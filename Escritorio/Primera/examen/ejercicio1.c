#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	pid_t resultado;

	resultado = fork();

	switch(resultado){

		//En el caso de que la creación del proceso de fallo.
		case -1:
			fprintf(stderr, "Hubo un error en la creación del primer fork / hijo.\n");
			exit(-1);
			break; //no es necesario.

		//Lo que realizara el nuevo proceso (hijo).
		case 0:
			fprintf(stdout, "El primer hijo dice que su PID es %d, y el de su padre %d\n", getpid(), getppid());
			break;

		//Lo que realiza el padre.
		default:

			resultado = fork();

			switch (resultado) {
				case -1:
					fprintf(stderr, "Hubo un error en la creación del segundo fork / hijo.\n");
					exit(-1);

				//lo que realiza el segundo hijo.
				case 0:
					fprintf(stdout, "El segundo hijo dice que su PID es %d, y el de su padre %d\n", getpid(), getppid());
					break;

				default:
					//Primero imprime, luego espera.
					fprintf(stdout, "Hola, soy el padre y mi pid es: %d. El pid de mi padre (la terminal) es: %d.\n", getpid(), getppid());
					wait(NULL);
					break;
			}

			break;
	}

	return 0;
}