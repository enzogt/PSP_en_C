# include <stdio.h>
# include <pthread.h>
# include <string.h>

typedef struct {

	char nombre [10];
	int edad;

} persona;


void* cumplir (void*);


int main(int argc, char const *argv[]) {

	pthread_t hilo1;


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


void* cumplir (void* personaEntrante){

	persona* persona1 = (persona*) personaEntrante;

	persona1->edad += 1;

	fprintf(stdout, "%s ha cumplido %d años\n", persona1->nombre, persona1->edad);
}