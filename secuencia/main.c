#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sysexits.h>
#include <math.h>
#include <errno.h>


int main(int argc, char *argv[])
{
	double hasta = 10;
	double desde = 1;
	double paso = 1;
	
	if((argc == 2) && strcmp(argv[1], "-h") == 0){

	        printf("secuencia: Uso: secuencia [ hasta [ desde [ paso ]]]\n");
	        printf("secuencia: Genera la secuencia de numeros en el intervalo y paso indicados.\n");
	        exit(EX_OK);
			
			}

	if(argc > 4){

			fprintf(stderr, "secuencia: Error(EX_USAGE), uso incorrecto del mandato. \"Success\" \n");
	        fprintf(stderr, "secuencia+  Error el numero de argumentos no es correcto \n");
	        exit(EX_USAGE);
			
			}
			
	else
	{
		if (argc > 1){

			hasta = strtod(argv[1],NULL);
			
			if(errno != 0){

						fprintf(stderr, "secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
	        	        fprintf(stderr, "secuencia+ El parametro \"hasta\" no es un numero real valido.\n");
	        	        exit(EX_USAGE);	

			}
		}
		
		if (argc > 2){

			desde = strtod(argv[2],NULL);
			
			if(errno != 0){

						fprintf(stderr, "secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
	        	        fprintf(stderr, "secuencia+ El parametro \"desde\" no es un numero real valido.\n");
	        	        exit(EX_USAGE);	

			}
		}

		if (argc > 3){

			paso = strtod(argv[3],NULL);
			
			if(errno !=0 ){

						fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
	        	        fprintf(stderr,"secuencia+ El parametro \"paso\" no es un numero real valido.\n");
	        	        exit(EX_USAGE);	
				
			}
			
				if(paso == 0){
				
						fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
						fprintf(stderr,"secuencia+ El parametro \"paso\" no puede valer 0.\n");
						exit(EX_USAGE);

			}
			
			if(((hasta < desde) && (paso > 0)) || ((hasta > desde) && ( paso < 0))){
				
						fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
						fprintf(stderr,"secuencia+ El signo de \"paso\" no permite recorrer el intervalo en el sentido \"desde\" a \"hasta\".\n");
						exit(EX_USAGE);

			}
		}
	}
		
	char *maxoutput = getenv("MAX_OUTPUT");
	double maxout;
	
	if(maxoutput != NULL){

			double max = strtod(maxoutput,NULL);

			if(max > 0  && (max == (int)max)){

				maxout= max;

			}
			else if( max == 0)
				{

				maxout = 0;

			}
			else
			{
				maxout = 100;
			}

		}
		else
			{          

			maxout = 100;

		}
		

	if(abs(hasta) < abs(desde) && paso < 0){
		
	double i;
		
	for(i = desde; i >= hasta ; i = i+paso){
		
		if(abs(i) > maxout){
			
				fprintf(stderr,"secuencia: Error(EX_NOPERM), permiso denegado. \"Success\"\n");
				fprintf(stderr,"secuencia+ Se intento superar el lımite de salida establecido por MAX OUTPUT.\n");
				exit(EX_NOPERM);
			
		}

		printf("\t%g\n",i);
		
	}
		
	}
	else
		{

	double j;
		
	for(j = desde; abs(j) <= abs(hasta) ; j = j+paso){
		
		if(abs(j) > maxout){
			
				fprintf(stderr,"secuencia: Error(EX_NOPERM), permiso denegado. \"Success\"\n");
				fprintf(stderr,"secuencia+ Se intento superar el lımite de salida establecido por MAX OUTPUT.\n");
				exit(EX_NOPERM);
			
		}

		printf("\t%g\n",j);
		
	}
	}
	
	exit(EX_OK);
}
