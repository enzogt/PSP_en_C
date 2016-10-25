#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[]) {
	
	int fd; //Descriptor de fichero // file descriptor.
	char buffer[15];


	fd = open("./fichero.txt", O_RDONLY);


	if (fd == -1){

		fprintf(stdout, "Faileo al abrir el fichero.\n");
		exit(-1);
	}

	read(fd, buffer, 15 * sizeof(char));
	close(fd);

	printf("%s", buffer);


	return 0;
}