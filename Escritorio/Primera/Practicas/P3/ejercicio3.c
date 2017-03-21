/*Programar un programa en C que cree acepte 2 números enteros por parámetro. El programa 
* principal debe capturar y transformar esos parámetros a float (​ atof()​ ). (20 puntos)

*   a. Luego el programa padre debe arrancar 4 hijos que con eso parámetros ejecuten 
* las operaciones aritméticas con esos parámetro. Uno sumará, otro restará, otro 
* multiplicará y otro dividirá.

*   b. Estos programas deben guardar el resultado de las operaciones en un fichero 
* (cada uno el suyo) e imprimirlo por pantalla.

*   c. El padre debe esperar a sus 4 hijos y al finalizar imprimir un mensaje de salida.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{

	if (argc != 3){
		fprintf(stderr, "Se esperaban 2 números entre los parametros. Saliendo...\n");
		exit(-1);
	}
	

	//Variables.
	float numeroA = atof(argv[1]);
	float numeroB = atof(argv[2]);
	char resultado[50];
	char comando[100];
	pid_t pid;


	pid = fork();

	switch (pid){

		case -1:
			fprintf(stderr, "Error en el primer fork.\n");
			exit(-1);
			break;

		case 0:

			sprintf(resultado, "- La suma de %.2f y %.2f es: %.2f", numeroA, numeroB, numeroA + numeroB);
			sprintf(comando, "echo %s > suma.txt", resultado);

			fprintf(stdout, "%s\n", resultado);
			system(comando);

			break;

		default:

			pid = fork();

			switch (pid){

				case -1:
					fprintf(stderr, "Error en el segundo fork.\n");
					exit(-1);
					break;

				case 0:

					sprintf(resultado, "- La resta de %.2f y %.2f es: %.2f", numeroA, numeroB, numeroA - numeroB);
					sprintf(comando, "echo %s > resta.txt", resultado);

					fprintf(stdout, "%s\n", resultado);
					system(comando);

					break;

				default:

					pid = fork();

					switch (pid){

						case -1:
							fprintf(stderr, "Error en el tercer fork.\n");
							exit(-1);
							break;

						case 0:

							sprintf(resultado, "- La multiplicación de %.2f y %.2f es: %.2f", numeroA, numeroB, numeroA * numeroB);
							sprintf(comando, "echo %s > multiplicacion.txt", resultado);

							fprintf(stdout, "%s\n", resultado);
							system(comando);

							break;

						default:

							pid = fork();

							switch (pid){

								case -1:
									fprintf(stderr, "Error en el cuarto fork.\n");
									exit(-1);
									break;

								case 0:

									sprintf(resultado, "- La división de %.2f y %.2f es: %.2f", numeroA, numeroB, numeroA / numeroB);
									sprintf(comando, "echo %s > division.txt", resultado);

									fprintf(stdout, "%s\n", resultado);
									system(comando);

									break;

								default:

									wait(NULL);
									fprintf(stdout, "\n  >>> Todas las operaciones concluidas.\n");
									break;
							}
							
							break;
					}
	
					break;
			}
			
			break;
	}

	return 0;
}