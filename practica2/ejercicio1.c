#include <stdio.h>
#include <math.h>

void mostrarLista(float array[], int size);
void bubbleSort(int sizeA, float array[], int orderType);

void bubbleSort(int sizeA, float array[], int orderType)
{

    int j, i;
    float temp;

    switch (orderType)
    {

    case 1: /*Menor a mayor en valor absoluto*/
        printf("\n\n-------------------------------------------------\n\n");
        printf("Ordenamiento de menor a mayor en valor absoluto\n\n");

        for (i = 1; i < sizeA; i++)
        {
            for (j = 0; j < sizeA - i; j++)
            {
                if (fabs(array[j]) > fabs(array[j + 1]))
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        break;

    case 2: /*Menor a mayor algebraicamente*/
        printf("\n\n-------------------------------------------------\n\n");
        printf("Ordenamiento de menor a mayor algebraicamente\n\n");
        for (i = 1; i < sizeA; i++)
        {
            for (j = 0; j < sizeA - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        break;

    case 3: /*Mayor a menor en valor absoluto*/
        printf("\n\n-------------------------------------------------\n\n");
        printf("Ordenamiento de mayor a menor en valor absoluto\n\n");
        for (i = 1; i < sizeA; i++)
        {
            for (j = 0; j < sizeA - i; j++)
            {
                if (fabs(array[j]) < fabs(array[j + 1]))
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        break;

    case 4: /*Mayor a menor algebraicamente*/
        printf("\n\n-------------------------------------------------\n\n");
        printf("Ordenamiento de mayor a menor algebraicamente\n\n");
        for (i = 1; i < sizeA; i++)
        {
            for (j = 0; j < sizeA - i; j++)
            {
                if (array[j] < array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        break;
    }
}

void mostrarLista(float array[], int sizeA)
{
    int i;
    for (i = 0; i < sizeA; i++)
        printf("%f\t", array[i]);
    printf("\n");
}

void main(void)
{
    int opc;
    float array[] = {4.7, -8.0, -2.3, 11.4, 12.9, 5.1, 8.8, -0.2, 6.0, -14.7};
    int sizeArray = sizeof(array) / sizeof(array[0]);

    printf("Array de testo:\n");
    mostrarLista(array, sizeArray);
    do
    {
        printf("\nSeleccione una opcion:\n1.Ordenamiento de menor a mayor de acuerdo al valor absoluto\n");
        printf("2.Ordenamiento de menor a mayor algebraicamente\n3. Ordenamiento de mayor a menor de acuerdo al valor absoluto\n");
        printf("4.Ordenamiento de mayor a menor algebraicamente\n5. Presione 5 para salir..\n\n");
        scanf("%d", &opc);
        bubbleSort(sizeArray, array, opc);
        mostrarLista(array, sizeArray);

    } while (opc != 5);
}