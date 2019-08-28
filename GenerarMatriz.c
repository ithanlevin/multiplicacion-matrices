#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CADENA 5000

int main(int argc, char** argv)
{
	FILE* fichero;
	int tMatrizA, tMatrizB, num;
	char snum[2];
	srand(time(NULL));

	fichero = fopen(argv[1], "w");

	if (fichero == NULL) {
        printf("ERROR       Verifique: ./NOMBRE_PROGRAMA NOMBRE_ARCHIVO\n");
        exit(1);
        }

	if (argc==2) {

	tMatrizA = rand()% 9 + 2; //Genera números aleatorios entre 2 y 10
	printf("Filas: %d\n", tMatrizA);
	tMatrizB = rand()% 9 + 2; //Genera números aleatorios entre 2 y 10
	printf("Columnas: %d\n", tMatrizB);

	for(int i = 0; i<tMatrizA; i++)
	{
		for(int j = 0; j<tMatrizB; j++)
		{
			if(j == (tMatrizB-1))
			{
				num = rand()%2;  //Genera números aleatorios entre 0 y 1
				sprintf(snum, "%d", num);//Convierte el entero a cadena
				fprintf(fichero, "%s",snum);
			}
			else
			{
				num = rand()%2;  //Genera números aleatorios entre 0 y 1
				sprintf(snum, "%d", num);//Convierte el entero a cadena
				fprintf(fichero, "%s",snum);
				putc(' ', fichero);
			}
		}
		putc('\n', fichero);
	}
	printf("Archivo generado.\n");
	fclose(fichero);
	}
	else
         printf("ERROR       Verifique: ./NOMBRE_PROGRAMA NOMBRE_ARCHIVO\n");

	return 0;
}
