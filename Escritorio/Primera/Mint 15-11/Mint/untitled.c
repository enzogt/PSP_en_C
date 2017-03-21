
	h1 = fork();
	h2 = fork();
	h3 = fork();
	h4 = fork();

	if (h1 == -1 || h2 == -1 || h3 == -1 || h4 == -1){
		fprintf(stderr, "> Error en la creacion de un hijo.\n");
		exit(-1);
	}


	if (h1 == 0){
		//Hijo.
		//fprintf(stdout, "> El proceso hijo tiene el PID es: %d\n", getpid());
		//sleep(2);

	} else {

		fprintf(stdout, "h1 = %d | h2 = %d | h3 = %d | h4 = %d", h1, h2, h3, h4);

		//Padre.
		fprintf(stdout, ">El proceso original (padre) tiene el PID: %d\n", getpid());
		
		fprintf(stdout, ">> Esperando a que termine el hijo...\n");
		pid_hijo_terminado = wait(NULL);
		fprintf(stdout, ">> El hijo %d terminó.\n", pid_hijo_terminado);
	}



/*

	char buffer[3];
	int fichero;
	ssize_t bytes_escritos = 1;
	int h1, h2, h3, h4;


	//char cadenaNumeroA [10];
	//char cadenaNumeroB [10];

	//Se piden los numeros como cadena.
	//fprintf(stdout, "\n>> Introduce el primer número: ");
	//scanf("%s", cadenaNumeroA);


	//fprintf(stdout, "\n>> Introduce el segundo número: ");
	//scanf("%s", cadenaNumeroB);


	//float primerNumero = atof(cadenaNumeroA);
	//float segundoNumero = atof(cadenaNumeroB);




	fprintf(stdout, "\n\n %f", primerNumero + segundoNumero)



	exit(-1);


	fichero = open(argv[1], O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG);




	//No ha podido leer el fichero.
	if(fichero == -1){
		fprintf(stderr, "La apertura ha fallado.\n");
		exit(-1);	
	}

	bytes_escritos = write(fichero, argv[2], 3 * sizeof(char));





	close(fichero);



*/