#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int distribuirHilos(int fils, int cols, int p, int **matrix); //Retorna un vector donde cada espacio corresponde a la cantidad de numeros por proceso

void* calcularElementos(void* data);

typedef struct{
	int cols; 			//Columnas de la matriz 
	int numsxHilo; 		//Cantidad minima de numeros que cuenta un hilo
	int hiloN;			//Numero de entrada que tiene el hilo
	int cantElementos;		//Cantidad de 1's que tiene la matriz
	int *vector;		//Vector que contiene la cantidad de numeros que ejecutacada hilo
	int **matrix;		//Matriz que ha sido leida del archivo
}Data;


int distribuirHilos(int fils, int cols, int p, int **matrix)
{
	int numsxHilo = (fils*cols)/p;
	int residuo = (fils*cols) - numsxHilo * p;
	int *vector = (int *)malloc(p*sizeof(int)); //Reserva espacio para un vector de tamanio p

	int cantElementos = 0;

	for(int i = 0; i < p; i++)
	{
		if(i == (p-1)) //Si el espacio corresponde al ultimo proceso...
		{
			vector[i] = numsxHilo + residuo; //Agrega el residuo al ultimo hilo
		}
		else
		{
			vector[i] = numsxHilo; // Cada espacio del vector tiene una cantidad de numeros definida
		}
	}

	for(int i = 0; i < p; i++)
	{
		Data datos; //Estructura que funcionara como parametro de la funcion del hilo
		datos.cols = cols;
		datos.numsxHilo = numsxHilo;
		datos.hiloN = i;
		datos.cantElementos = 0;
		datos.vector = vector;
		datos.matrix = matrix;

		pthread_t hilo;	//Aqui abre hilos
		pthread_create(&hilo, NULL, (void*)calcularElementos, (void*)&datos);
		pthread_join(hilo, NULL);

		cantElementos += datos.cantElementos;		//Suma los unos que guarda cada hilo
	}

	return cantElementos; //Retorna la cantidad total de unos en la matriz
}

void* calcularElementos(void* data)
{
	Data *datos = (Data*) data;
	int x = 0;
	int y = 0;

	int cols = datos->cols;
	int numsxHilo = datos->numsxHilo;
	int hiloN = datos->hiloN;
	int *vector = datos->vector;
	int **matrix = datos->matrix;

	for(int j = 0; j < vector[hiloN]; j++) //Realiza iteraciones dependiendo de la cantidad de numeros que le corresponden
	{											//a cada hilo
		x = 0;
		y = hiloN * numsxHilo + j; // 

		while(y >= cols) //Localiza las coordenadas x & y donde empieza cada hilo
		{
			y = y - cols;//Disminuye la columna
			x = x +1; //Aumenta la fila
		}

		if( matrix[x][y] != 0 ) //Si el numero donde esta ubicado la coordenada es distinto de cero
		{
			datos->cantElementos++; //Aumenta en 1 la cantidad que hay en este hilo
		}
	}
}