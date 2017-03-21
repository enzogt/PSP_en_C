#include <stdio.h>
#include <stdlib.h> //Para system.
#include <unistd.h> //Para el execl.

void main(){
	//Con system
	//printf("Devuelve: %d\n", system("firefox http://stackoverflow.com/"));

	//Con ecex. Ruta -- nombre ejecutable -- necesario.
	printf("Devuelve: %d\n", execl("/usr/bin/xed", "xed", (char*)NULL));
}
