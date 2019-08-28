#include <stdio.h>
#include <stdlib.h>
#include "leerMatriz.h"
#include "distribuirHilos.h"
#include "dispersa.h"

int main(int argc, char *argv[])
{
    if(argc > 4)
    {
        int fils = atoi(argv[1]);//atoi convierte argv[1] y argv[2] en enteros
        int cols = atoi(argv[2]);
        int p = atoi(argv[4]);//cantidad de hilos a ejecutar

        double prctajeUsuario;
        sscanf(argv[5], "%lf", &prctajeUsuario); //Convierte prctajeUsuario en double

        int cantidadMinCeros; // Cantidad minima de ceros para que se considere la matriz como dispersa
        int cantElemDifCero = 0; //Elementos en la matriz que son diferentes de cero


        int **matrix; //Crea la matriz de enteros
        //int *vector; //vector que contiene la cantidad de numeros por proceso

        matrix = leerMatriz(argv[3], fils, cols); //Guarda en memoria la matriz del archivo

        cantElemDifCero = distribuirHilos(fils, cols, p, matrix);

        cantidadMinCeros = cantMinCeros(fils, cols, prctajeUsuario);
        
        if(matrizEsDispersa(fils, cols, cantidadMinCeros, cantElemDifCero))
        {
            printf("\nLa matriz en el archivo %s tiene un total de %d ceros, por tanto, se considera dispersa. Se requieren %d ceros.\n\n", argv[3], (fils*cols) - cantElemDifCero, cantidadMinCeros );
        }
        else
        {
            printf("\nLa matriz en el archivo %s tiene un total de %d ceros, por tanto, no se considera dispersa. Se requieren %d ceros o más para considerarla dispersa.\n\n", argv[3], (fils*cols) - cantElemDifCero, cantidadMinCeros);   
        }

    }
    else
    {
        perror("ERROR       Verifique: ./pdispersa M N archivo nprocesos porcentaje\n");
    }

    return 0;
}