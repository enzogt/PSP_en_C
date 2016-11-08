#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
	
	int fd[2]; //Pipe.
	char buffer[20];
	pid_t pid;
	int retorno;


	retorno = pipe(fd);

	if(retorno == -1){
		fprintf(stderr, "Error en el pipe\n");
		exit(-1);
	}

	pid = fork();

	switch (pid) {
		case -1:
			fprintf(stderr, "Error en el fork.\n");
			exit(-1);
			break;

		//Hijo.
		case 0:
			fprintf(stdout, "Proceso hijo ejecutandose.\n");

			char mensaje1[] = "Hola que tal.";
			char mensaje2[] = "Como va eso.\0";


			write(fd[1], mensaje1, (strlen(mensaje1) + 1) * sizeof(char));
			fprintf(stdout, "Primer mensaje enviado.\n");

			write(fd[1], mensaje2, (strlen(mensaje2) + 1) * sizeof(char));
			fprintf(stdout, "Segundo mensaje enviado.\n");

			break;

		//Padre.
		default:
			fprintf(stdout, "Proceso padre ejecutandose.\n");
			sleep(2);
			read(fd[0], &buffer, sizeof(buffer));
			fprintf(stdout, "%s\n", buffer);
			wait(NULL);
			break;
	}



	return 0;
}