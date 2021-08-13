#include <stdio.h>

#define MAX_LENGTH  100

void ejercicio2Item1(void);
void ejercicio2Item2(void);
void ejercicio2Item3(void);

void main()
{
    printf("\n\nEJERCICIO 2\n\n");

    printf("\n\nActividad 1 del ejercicio 2:\n\n");
    ejercicio2Item1();
    printf("\n-------------------------------------------------\n\n");
    printf("\n\nActividad 2 del ejercicio 2:\n\n");
    ejercicio2Item2();
    printf("\n-------------------------------------------------\n\n");
    printf("\nActividad 3 del ejercicio 2:\n\n");
    ejercicio2Item3();
}
/*Escribir las instrucciones scanf o printf necesarias para cada uno de los siguientes puntos:
Generar el mensaje:

Por favor, introduce tu nombre:

y que el usuario introduzca en la misma línea su nombre.
Asignar el nombre a una cadena de caracteres llamada nombre.

*/

void ejercicio2Item1(void)
{

    char nombre[MAX_LENGTH];
    printf("Por favor, ingrese su nombre:\n");
    fgets(nombre,MAX_LENGTH,stdin);

    printf("Su nombre es: %s", nombre);
}
/*
 *
 * Supongamos que x1 y x2 son variables en coma flotante
 * cuyos valores son 8.0 y -2.5 respectivamente. Visualizar los valores de x1 y x2,
 * con los rótulos adecuados, por ejemplo:

x1 = 8.0	x2 = -2.5
 *
 */

void ejercicio2Item2(void)
{

    float x1 = 8.0, x2 = -2.5;

    printf("X1 = %.1f\tX2 = %.1f\n\n", x1, x2);
}

/*Supongamos que a y b son variables enteras.
 * Pedir al usuario que introduzca el valor de estas dos variables
 * y mostrar después su suma. Rotular la salida adecuadamente.*/

void ejercicio2Item3(void)
{

    int a, b;
    printf("Ingrese el valor de la variable a:");
    scanf("%d", &a);
    printf("Ingrese el valor de la variable b:");
    scanf("%d", &b);

    printf("\n\nLa suma de los valores ingresados es: %d\n", (a + b));
}