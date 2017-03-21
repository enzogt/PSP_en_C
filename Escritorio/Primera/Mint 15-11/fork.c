#include <stdio.h>
#include <sys/types.h> //Para tipo pid_t.
#include <unistd.h> //Para el fork.

void main(){

	pid_t id_pactual, id_padre;

	id_pactual = getpid();
	id_padre = getppid();


	//printf("PID de este proceso: %d\n\n", id_pactual);
	//printf("PID del proceso padre: %d\n\n", id_padre);


	int retorno = fork();
	if (retorno == 0){

		printf(" - Proceso ejecutado por el hijo, con PID %d\n", id_pactual);

	}else{

		printf(" - Proceso ejecutado por el padre, con PID %d\n", id_padre);
		wait();
	}


}
