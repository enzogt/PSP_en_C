/*  b. Cread un programa ​ enviarsenyal.c aparte que envíe una señal con la función ​ kill() de C al 
* proceso ​esperarCtrlZ del ejercicio anterior. Para ello tenéis que crear el programa y pasarle
* directamente el PID del proceso (cambia en cada ejecución, así que una vez tengáis el programa ​ 
* esperarCtrlZ podéis ejecutar el comando ​ pidoff en la terminal para obtener su pid. Enviad una
* captura de pantalla que demuestre el proceso.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char const *argv[])
{

	if(argc != 2){
		fprintf(stderr, "Se requiere el PID del proceso a matar.\n");
	}

	kill(atoi(argv[1]), SIGTSTP);

	return 0;
}