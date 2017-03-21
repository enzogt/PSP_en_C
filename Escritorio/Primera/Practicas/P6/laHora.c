/*Crear un programa laHora.c en C que imprima 4 veces la hora cada 30 segundos
* (función ​ alarm()​ ) y vuestro nombre. Por ejemplo: “​ Teo Laírla, la hora es:
* mar nov 22 13:14:42 CET 2016​ ”. Para que se imprima la hora podéis utilizar
* el comando ​ date​ , con una llamada del sistema ​ system()​ . Cread una captura de
* pantalla que muestre la ejecución completa del programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void imprimirHora(){

	fprintf(stdout, "\nLorenzo, la hora es: \n");
	system("date");
}

int main(int argc, char const *argv[])
{
	
	int repeticiones = 4;

	signal(SIGALRM, imprimirHora);

	while (repeticiones-- > 0){

		alarm(30);
		pause();
	}

	return 0;
}