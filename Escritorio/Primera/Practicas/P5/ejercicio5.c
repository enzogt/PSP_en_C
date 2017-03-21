/*Cread un programa que capture la señal SIGINT (Ctrl-C) 3 veces con 
* comportamientos diferentes:
*   a. La primera debe ejecutar una función que escriba: “TuNombre, has 
* pulsado salir, ¿estás seguro?, si es así pulsa otra vez.”.
*   b. La segunda debe escribir: “Pero…¿seguro, seguro?”
*   c. La tercera deberá tener el comportamiento por defecto de la señal, 
* que es salir.*/



#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int repeticiones = 3;

void senal () {

	switch (repeticiones){

		case 3:
			fprintf(stdout, "Lorenzo, has pulsado salir, ¿estás seguro?, si es así pulsa otra vez.\n");
			break;

		case 2:
			fprintf(stdout, "Pero... ¿seguro, seguro?.\n");
			break;
	}
}

int main(int argc, char const *argv[])
{
	
	signal(SIGINT, senal);

	while (repeticiones > 0) {
		pause();

		repeticiones--;

		//Quitar el evento no creo que sea estricamente necesario.
		if (repeticiones == 1){
			signal(SIGINT, SIG_DFL);
		}
	}

	return 0;
}