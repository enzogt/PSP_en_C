#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

	char buffer[3];
	int fichero;
	ssize_t bytes_leidos = 1;

	if (argc != 2){
		fprintf(stderr, "El uso del programa es incorrecto.\nSu uso es %s archivo.ext\n", argv[0]);
		exit(-1);
	}

	fichero = open(argv[1], O_RDONLY);

	//No ha podido leer el fichero.
	if(fichero == -1){
		fprintf(stderr, "La apertura ha fallado.\n");
		exit(-1);	
	}

	//Puede.

	while (bytes_leidos != 0) {

		bytes_leidos = read(fichero, &buffer, 3 * sizeof(char)); //Un caracter
		fprintf(stdout, "Leído = %s\n", buffer);

	}

	close(fichero);

	return 0;
}