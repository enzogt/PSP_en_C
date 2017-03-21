/*Crear un programa ​ esperarCtrlZ.c en C que se quede esperando infinitamente una señal y modifique el 
* comportamiento por defecto de la señal ​ SIGTSTP (​ Ctrl-Z​ ) e imprima un mensaje con tu nombre y el 
* mensaje “Has pulsado Ctrl-Z”. Por ejemplo: “​ Teo Laírla, has pulsado Ctrl-Z​ ”.

*   a. Mandad la señal desde un terminal con el comando ​ kill (o killall​ ) desde otra terminal al 
* proceso y ver que tiene el mismo comportamiento. Enviad una captura de pantalla que lo demuestre.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void tratamiento () {

	fprintf(stdout, "Lorenzo has pulsado Ctrl-Z​\n");
}

int main(int argc, char const *argv[])
{

	signal(SIGTSTP, tratamiento);
	
	while (1) {
		pause();
	}

	return 0;
}