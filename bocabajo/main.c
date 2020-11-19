#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sysexits.h>
#include <stdarg.h>
#include <unistd.h>



int main(int argc, const char * argv[]) {

    int i;
	int  j = 0;
	long k;
	int numero = argc - 1;

    FILE** ficheros = malloc(sizeof(FILE*) * (numero));
	FILE* ficheroactual;
	
    size_t linea = 2048;

    long numLineas = 0;
    char** LineasFichero = NULL;


    if(argc == 2 && ((strncmp(argv[1], "-h", sizeof(char) * 2) == 0) )) {

        printf("bocabajo: Uso: bocabajo [ fichero... ]\n");
		printf("bocabajo: Invierte el orden de las lı́neas de los ficheros (o de la entrada).\n");
        exit(EX_OK);

    }

    for (i = 1; i < argc; i++){

  			int f, r;

			const char *filename = argv[i];
			f = access (filename, F_OK);
			r = access (filename, R_OK);

			if ((r != 0) || (f != 0)){

					fprintf(stderr,"bocabajo: Error(EX_NOINPUT), uso incorrecto del mandato. \"Success\"\n");
					fprintf(stderr,"bocabajo+ El fichero \"%s\" no puede ser leido. \n", argv[i]);
					exit(EX_NOINPUT);

      }

  	}

    for (i = 1; i < argc; i++) {

        ficheros[i-1] = fopen(argv[i], "r");

    }

    for (i = numero - 1; i >= 0; i--) {

        ficheroactual = ficheros[i];
        fseek(ficheroactual, 0L, SEEK_END);
		
        numLineas = ftell(ficheroactual) / sizeof(char);
        fseek(ficheroactual, 0L, SEEK_SET);

        free(LineasFichero); 
		
        LineasFichero = malloc((sizeof(char) * 2048) * numLineas);

        if(LineasFichero == NULL){

          fprintf(stderr,"%s: Error(EX_OSERR), uso incorrecto del mandato. \"Success\". \n",argv[0]);
          fprintf(stderr,"%s+ No se puede ubicar la memoria dinamica necesaria. \n", argv[0]);
          exit(EX_OSERR);

        }

        while (getline(&LineasFichero[j], &linea, ficheroactual) != -1) {

            j++;

        }

        for (k = j - 1; k >= 0; --k) {

            printf("%s", LineasFichero[k]);

        }
    }

    exit(EX_OK);
}
