#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

	double op1, op2, resultado = 0;
	pid_t pid = 0;


	//Si no recibe el fichero.
	if (argc != 3){
		fprintf(stderr, "\nEl uso del programa es incorrecto.\nSu uso es %s archivo.ext op1 op2.\n", argv[0]);
		exit(-1);
	}


	op1 = atof(argv[1]);
	op2 = atof(argv[2]);

	fprintf(stderr, "\n> Parametros introducidos: %f | %f", op1, op2);


	//Intencion de creacion del primer proceso hijo.
	pid = fork();
	if (pid == -1){
		fprintf(stderr, "\n> Error en la creacion del primer un hijo.");
		exit(-1);
	}

	//Primer proceso hijo creado.
	if (pid == 0){
		
		resultado = op1 + op2;
		fprintf(stdout, "\n> El hijo que suma dice: '%f + %f = %f'", op1, op2, resultado);

	} else {

		//Intencion de creacion del segundo proceso hijo.
		pid = fork();
		if (pid == -1){
			fprintf(stderr, "\n> Error en la creacion del segundo un hijo.");
			exit(-1);
		}

		//Tercer proceso hijo creado.
		if (pid == 0){
			
			resultado = op1 - op2;
			fprintf(stdout, "\n> El hijo que resta dice: '%f - %f = %f'", op1, op2, resultado);

		} else {


			//Intencion de creacion del tercer proceso hijo.
			pid = fork();
			if (pid == -1){
				fprintf(stderr, "\n> Error en la creacion del tercer un hijo.");
				exit(-1);
			}

			//Segundo proceso hijo creado.
			if (pid == 0){
				
				resultado = op1 * op2;
				fprintf(stdout, "\n> El hijo que multiplica dice: '%f * %f = %f'", op1, op2, resultado);

			} else {

				//Intencion de creacion del cuarto proceso hijo.
				pid = fork();
				if (pid == -1){
					fprintf(stderr, "\n> Error en la creacion del cuarto un hijo.");
					exit(-1);
				}

				//Segundo proceso hijo creado.
				if (pid == 0){
					
					resultado = op1 / op2;
					fprintf(stdout, "\n> El hijo que divide dice: '%f * %f = %f'", op1, op2, resultado);

				} else {

					fprintf(stdout, "\n> El padre (%d) dice: 'toca esperar'.", getpid());

					pid = wait(NULL);
					fprintf(stdout, "\n>> Hijo %d terminó.", pid);
		
					pid = wait(NULL);
					fprintf(stdout, "\n>> Hijo %d terminó.", pid);
					
					pid = wait(NULL);
					fprintf(stdout, "\n>> Hijo %d terminó.", pid);
					
					pid = wait(NULL);
					fprintf(stdout, "\n>> Hijo %d terminó.", pid);			

				}

			}

		}

	}

	return 0;
}