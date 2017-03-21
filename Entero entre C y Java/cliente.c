#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>

int main(int argc, char **argv){

  if(argc<2) {
    printf("<host> <puerto>\n");
    return 1;
  }

  struct sockaddr_in cliente; //Declaración de la estructura con información para la conexión
  struct hostent *servidor; //Declaración de la estructura con información del host
  servidor = gethostbyname(argv[1]); //Asignacion
  if(servidor == NULL)
  { //Comprobación
    printf("Host erróneo\n");
    return 1;
  }
  int puerto, conexion;
  char buffer[100];
  conexion = socket(AF_INET, SOCK_STREAM, 0);
  puerto=(atoi(argv[2]));
  bzero((char *)&cliente, sizeof((char *)&cliente));
  cliente.sin_family = AF_INET;
  cliente.sin_port = htons(puerto);

  bcopy((char *)servidor->h_addr, (char *)&cliente.sin_addr.s_addr, sizeof(servidor->h_length));
  if(connect(conexion,(struct sockaddr *)&cliente, sizeof(cliente)) < 0)
  {
    printf("Error conectando con el host\n");
    close(conexion);
    return 1;
  }
  printf("Conectado con %s:%d\n",inet_ntoa(cliente.sin_addr),htons(cliente.sin_port));
  
  /********************/
  /*** ENVIO ENTERO ***/
  /********************/
  int leido, salida;

  printf("Escribe un entero: ");
  fscanf(stdin, "%d", &leido);

  salida = htonl(leido);

  send (conexion, &salida, sizeof(int), 0); //Envio
  close(conexion);

return 0;
}