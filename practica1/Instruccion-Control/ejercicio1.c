#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LONG 80

void invertString()
{

    char texto[LONG];
    char textoInvertido[LONG];
    char *fin = "-1";
    int i, j;

    printf("ingrese un cadena:\n");
    fgets(texto, LONG, stdin);
    if ((strcmp(texto, fin)))
        exit(-1);

    for (i = 0, j = strlen(texto) - 1; j >= 0; i++, j--)
    {
        textoInvertido[j] = texto[i];
    }
    textoInvertido[strlen(texto)] = '\0';
    printf("La cadena invertida que usted ha ingresado es:  %s\n", textoInvertido);
}

void main(void)
{
    invertString();
}