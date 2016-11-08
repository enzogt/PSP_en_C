#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

int main(int argc, char const *argv[]) {
	
	int tuberia;
	char mensaje[100];


	tuberia = open("./pipe", O_RDWR);


	if(tuberia == -1){
		fprintf(stderr, "Error en la tuberia. Llama al fontanero o yo que se.\n");
		exit(-1);
	}

	fprintf(stdout, "Leyendo mensaje...\n");
	write(tuberia, mensaje, sizeof(mensaje));
	fprintf(stdout, "Hecho. \n");

	fprintf(stdout, "El mensaje es %s. \n", mensaje);

	close(tuberia);

	return 0;
}