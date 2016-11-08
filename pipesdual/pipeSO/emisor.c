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
	char mensaje [] = "Hola receptor. Que tramas.\0";


	tuberia = open("./pipe", O_RDWR);


	if(tuberia == -1){
		fprintf(stderr, "Error en la tuberia. Llama al fontanero o yo que se.\n");
		exit(-1);
	}

	fprintf(stdout, "Enviando mensaje...\n");
	write(tuberia, mensaje, (strlen(mensaje) + 1) * sizeof(char));
	fprintf(stdout, "Hecho. \n");

	close(tuberia);

	return 0;
}