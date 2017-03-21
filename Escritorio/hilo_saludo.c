# include <stdio.h>
# include <pthread.h>
# include <string.h>


typedef struct {
	
	char mensaje[10];

} mensaje;


void* cumplir (void*);


int main(int argc, char const *argv[]) {
	
	pthread_t hilo1;
	pthread_t hilo2;

	mensaje m1;
	mensaje m2;

	strcpy(m1.mensaje, "Hola ");
	strcpy(m2.mensaje, "mundo");

	



	/*Primer hilo*/
	persona p1;
	p1.edad = 2147483647;
	strcpy(p1.nombre, "Sublime");


	fprintf(stdout, "%d años.\n", p1.edad);

	persona* p2 = &p1;
	p2->edad = 50;

	fprintf(stdout, "%d años.\n", p1.edad);

	pthread_create(&hilo1, NULL, cumplir, p2);
	pthread_join(hilo1, NULL);

	fprintf(stdout, "%d años.\n", p1.edad);


	return 0;
}



void* saludar (void* mensaje){

	saludo* decir = (saludo*) mensaje;

	fprintf(stdout, "%s\n", decir->mensaje);
}