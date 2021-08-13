#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int openFile()
{
    FILE *pArchivo = NULL;
    int cantCaracteres = 0;
    char caracterBuscado[200];

    pArchivo = fopen("lorem_ipsum.txt", "r");

    if (pArchivo == NULL)
    {
        printf("No fue posible abrir el archivo\n");
        return -1;
    }
    
    /*cuento las palabras que hay en el archivo usando
    fscanf, la cual devuelve un uno cada vez que encuentra un espacio*/
    while (fgetc(pArchivo) != EOF)
    {
        while (fscanf (pArchivo, "%s", caracterBuscado) == 1)  cantCaracteres++;
    }

    printf("\nCantidad de palabras en el archivo: %d\n", cantCaracteres);

    fclose(pArchivo);

    return 0;
}

void main()
{
    openFile();
}