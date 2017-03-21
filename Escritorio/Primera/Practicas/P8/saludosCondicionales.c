/*Cread un programa saludosCondicionales.c donde haya un padre y 2 hijos de ese padre.
* El padre tiene que crear un PIPE (función pipe()), crear los dos hijos y esperar a 
* que éstos acaben.
* El primer hijo tiene que ejecutar el comando date +%H (devuelve el número de la hora) 
* mediante una llamada a system() o bien a execl() 
* y redireccionar su contenido a un archivo truncando cualquier contenido anterior ( > ). 
* Luego debe abrir ese archivo, leerlo y enviarlo por el PIPE al otro hijo.
* El otro hijo, debe quedarse esperando leyendo en el PIPE hasta que reciba el valor numérico 
* de la hora y después imprimir un mensaje que diga, Buenos días, buenas tardes o buenas noches 
* según ese valor. (Como el valor será texto, habrá que transformarlo a entero con atoi(), 
* como ya se ha hecho en clase).*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc, char const *argv[])
{
	int pipefd[2];
	int retorno;
	pid_t pid;
	int fd;
	char buffer[3]; //2 de la hora y uno de fin.
	int valorLeido;


	retorno = pipe(pipefd);

	if(retorno == -1){
		fprintf(stderr, "Error en el pipe.\n" );
		exit(-1);
	}

	pid = fork();

	switch (pid) {

		case -1:
			fprintf(stderr, "Error en el primer fork.\n");
			exit(-1);
			break;

		case 0:
			//Hijo 1.

			system("date +%H > hijo1.txt");

			fd = open("hijo1.txt", O_RDONLY);

			if (fd == -1){

				fprintf(stderr,"El fichero no se ha podido abrir.\n");
				exit(-1);
			}

			//Se leen 2 caracteres y se finaliza la cadena,
			read (fd, buffer, 2 * sizeof(char));
			buffer[sizeof(buffer) - 1] = '\0';
			close(fd);

			write(pipefd[1], buffer, sizeof(buffer));

			break;

		default:

			pid = fork();

			switch (pid) {

				case -1:
					fprintf(stderr, "Error en el segundo fork.\n");
					exit(-1);
					break;

				case 0:
					//Hijo 2.
					wait(NULL);

					read(pipefd[0], buffer, sizeof(buffer));

					valorLeido = atoi(buffer);

					if (valorLeido >= 6 && valorLeido < 14){
						fprintf(stdout, "> Buenos días (%d).\n", valorLeido);
					} else if (valorLeido >= 14 && valorLeido < 22) {
						fprintf(stdout, "> Buenas tardes (%d).\n", valorLeido);
					} else {
						fprintf(stdout, "> Buenas noches (%d).\n", valorLeido);
					}

					break;

				default:
					//Padre.
					wait(NULL);
					break;
			}

			break;
		}
	
	return 0;
}