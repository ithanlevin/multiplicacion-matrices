#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int cantMinCeros(int fils, int cols, double prctajeUsuario);
bool matrizEsDispersa(int fils, int cols, int cantMinCeros, int cantElemDifCero);

int cantMinCeros(int fils, int cols, double prctajeUsuario)
{
	int cant_i;
	double cant_d = (fils*cols)*prctajeUsuario / 100 ;

	//Regla de Tres
	//si 100% ----------> fils*cols
	//prctajeUsuario---->     x
	//x = (fils*cols)*prctajeUsuario / 100

	cant_i = (int) round(cant_d); //Redondea el decimal al entero mas cercano

	return cant_i; //Retorna el numero minimo de ceros que debe tener la matriz para considerarse dispersa
}

bool matrizEsDispersa(int fils, int cols, int cantMinCeros, int cantElemDifCero)
{
	float totalCeros = (fils*cols) - cantElemDifCero;

	if(totalCeros >= cantMinCeros)
	{
		return true;
	}
	else
	{
		return false;
	}
}