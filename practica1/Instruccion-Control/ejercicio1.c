#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LONG 80

void invertString()
{

    char texto[LONG];
    char textoInvertido[LONG];
    char *fin = "-1\n";
    int i, j;
do{
    printf("ingrese un cadena:\n");
    fgets(texto, LONG, stdin);
    /*if ((strcmp(texto, fin)))
        exit(-1);
*/
    for (i = 0, j = strlen(texto) - 1; j >= 0; i++, j--)
    {
        textoInvertido[j] = texto[i];
    }
    textoInvertido[strlen(texto)] = '\0';
    /*Con la siguiente instruccion evito invertir la cadena de finalizacion del programa*/
    if(strcmp(texto, fin)) printf("La cadena invertida que usted ha ingresado es:  %s\n", textoInvertido);

}while(strcmp(texto, fin));
    
}

void main(void)
{
    invertString();
}