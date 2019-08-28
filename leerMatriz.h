#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** leerMatriz(char *direccion, int fils, int cols);

int** leerMatriz(char *direccion, int fils, int cols)
{
    FILE *archivo;
    char linea[80]; //Guarda lineas de texto del archivo
    char* token; //Cadena que guarda los caracteres después de haber tokenizado
    int **matriz;  //Matriz auxiliar

    archivo = fopen(direccion, "r"); //Realiza la lectura del archivo.


    if(archivo == NULL)
    {
        perror("ERROR   Verifique: ./pdispersa M N archivo nprocesos porcentaje\n");
        return 0;
    }
    else
    {
        //printf("Se encontro el archivo\n");

        matriz = (int **)malloc(fils*sizeof(int*)); //Asigna el tamano de filas a la matriz

        for(int i = 0; i < fils; i++)
        {
            matriz[i] = (int *)malloc(cols*sizeof(int));//new int[cols]; //Asigna el tamano de columnas a la matriz

            fgets(linea, 79, archivo); //Lee una linea del archivo
            token = strtok(linea, " "); //Retira los espacios de la cadena "linea"

            matriz[i][0] = atoi(token); //Ingresa a la primera columna de cad fila su respectivo número

            for(int j = 1; j < cols; j++)
            {
                token = strtok (NULL, " "); //Guarda el siguiente caracter de la cadena tokenizada
                matriz[i][j] = atoi(token); //Termina de llenar la matriz con los respectivos numeros
            }
        }

        fclose(archivo);// Cierra el stream del archivo
        return matriz;
    }
}
