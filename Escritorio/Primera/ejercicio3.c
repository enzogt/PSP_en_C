#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>


int main(int argc, char const *argv[])
{
	pid_t pid;
	FILE *f;
	int valorLeido;
	int pidpadre;

	//Creación del nuevo proceso.
	pid = fork();

	switch (pid) {

		case -1:
			fprintf(stderr, "Error en la creacion del fork.\n");
			exit(-1);
			break;

		case 0:

			//Lectura del fichero.
			f = fopen("pid.txt", "r");

			if (f == NULL){
				fprintf(stderr,"El fichero no se ha podido abrir.\n");
				exit(-1);
			}

  			fscanf (f, "%d", &valorLeido);  
  			pidpadre = getppid();

  			fprintf(stdout, "El hijo ha leido del fichero %d, mientra que el padre tiene el PID %d\n", valorLeido, pidpadre);

  			if(pidpadre == valorLeido){
  				fprintf(stdout, "Coinciden!!\n");
  			} else  {
  				fprintf(stdout, "No Coinciden\n");
  			}

			break;

		default:

			//Creación del fichero.
			f = fopen("pid.txt", "w");

			if (f == NULL){
				fprintf(stderr,"El fichero no se ha podido abrir / crear.\n");
				exit(-1);
			}

			fprintf(f, "%d", getpid());
			break;
			
		}

	return 0;
}