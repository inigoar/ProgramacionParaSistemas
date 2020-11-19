#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sysexits.h>

int main(int argc, char *argv[])
{
	
	char palabra[2048];
	
	if(argc == 2 && (strcmp(argv[1], "-h") == 0)){

				printf("delreves: Uso: delreves [ fichero... ]\n");
				printf("delreves: Invierte el contenido de las l ́ıneas de los ficheros (o de la entrada).\n");

				exit(EX_OK);
	
	}
	
	if (argc > 1){

        	FILE* fichero;

                int i;

                for(i = 1; i < argc; i++){

	                if((fichero = fopen(argv[i],"r"))){

							while(fgets(palabra,2048,fichero));{

							int j,i,c;

									for (i = 0, j = strlen(palabra)-1; i < j; i++, j--) {
										c = palabra[i];
										palabra[i] = palabra[j];
										palabra[j] = c;
									}
									printf("%s", palabra);
									
									fclose(fichero);


								}

                         }
										
						else
						{
								fprintf(stderr,"delreves: Error(EX_NOINPUT), uso incorrecto del mandato. \"Success\" \n");
								fprintf(stderr,"delreves+ El fichero  \"%s\" no puede ser leido. \n" , argv[i]);

                                exit(EX_NOINPUT);
							
						}
				}
	}
	
	else 
	{

                while(fgets(palabra,2048,stdin)){

							int j,i,c;

									for (i = 0, j = strlen(palabra)-1; i < j; i++, j--) {
										c = palabra[i];
										palabra[i] = palabra[j];
										palabra[j] = c;
									}
									printf("%s", palabra);
								}

        }

		exit(EX_OK);
		
}