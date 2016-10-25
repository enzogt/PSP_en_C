#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	int fd; //Descriptor de fichero // file descriptor.
	char mensaje[] = "Hola clase.";


	fd = open("./fichero2.txt", O_WRONLY);


	if (fd == -1){

		fprintf(stdout, "Faileo al abrir el fichero.\n");
		exit(-1);
	}

	write(fd, mensaje, strlen(mensaje) * sizeof(char));
	close(fd);


	return 0;
}