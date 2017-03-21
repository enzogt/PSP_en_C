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

		//En el caso de que la creación del proceso de falle.
		case -1:
			fprintf(stderr, "Hubo un error en la creación del primer fork / hijo.\n");
			exit(-1);

		//Lo que realizara el nuevo proceso (hijo).
		case 0:

			resultado = fork();

			switch (resultado) {
				case -1:
					fprintf(stderr, "Hubo un error en la creación del segundo fork / hijo.\n");
					exit(-1);

				//Lo que hace el proceso nieto.
				case 0:
					fprintf(stdout, "El nieto dice que su PID es %d, y el de su padre %d\n", getpid(), getppid());
					break;

				//Lo que hace el proceso hijo
				default:
					fprintf(stdout, "El proceso hijo dice que su PID es %d y el PID de su padre %d.\n", getpid(), getppid());
					wait(NULL);
					break;
			}
			break;

		//Lo que realiza el padre.
		default:
			fprintf(stdout, "Hola, soy el padre y mi pid es: %d. El pid de mi padre (la terminal) es: %d.\n", getpid(), getppid());
			wait(NULL);
			break;
	}

	return 0;
}