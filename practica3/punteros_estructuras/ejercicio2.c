#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 90

/*Equipo de futbol*/
typedef struct equipo
{
    char nombre[MAX_SIZE];
    int cant_victorias;
    int cant_derrotas;
    int cant_empates;
    int cant_goles;
    struct equipo *equipoSig;
} strc_equipo;

/*Entero numerado para elegir las opciones
de ordenamiento*/
typedef enum
{
    VICTORIAS = 1,
    DERROTAS,
    CANT_GOLES,
} _OPCIONES;

strc_equipo *pHead = NULL;

/*Funcion Callback para llamar a las distintas funciones de ordenamiento*/
typedef void (*bubleSort)(strc_equipo *start);

/*Agrego un nuevo nodo*/
void push(const char *nombre, const int cant_victorias, const int cant_derrotas, const int cant_empates, const int cant_goles)
{
    /*Creo un nuevo equipo por puntero*/
    strc_equipo *nuevoEquipo = (strc_equipo *)malloc(sizeof(strc_equipo));
    /*Completo los campos del equipo nuevo*/
    strcpy(nuevoEquipo->nombre, nombre);
    nuevoEquipo->cant_victorias = cant_victorias;
    nuevoEquipo->cant_derrotas = cant_derrotas;
    nuevoEquipo->cant_empates = cant_empates;
    nuevoEquipo->cant_goles = cant_goles;
    /*El nuevo equipo apuntara al equipo que fue insertado anteriormente, es decir al head*/
    nuevoEquipo->equipoSig = pHead;
    /*Ahora el head es el nuevo equipo*/
    pHead = nuevoEquipo;
}

/*Imprimo los equipos de la lista y voy liberando memoria*/
void printLista()
{
    strc_equipo *anterior = NULL;
    if (pHead == NULL)
    {
        printf("\nLista Vacia!\n");
        exit(-1);
    }
    while (pHead != NULL)
    {
        anterior = pHead; /*Apunto al nodo que voy a mostrar con otro puntero para 
        poder liberar ese segmento de memoria y no perder la referencia de temp*/
        printf("\nNombre del equipo: %s, Nro victorias: %d, Nro derrotas: %d, Nro empates: %d, Nro de goles: %d\n", pHead->nombre, pHead->cant_victorias, pHead->cant_derrotas, pHead->cant_empates, pHead->cant_goles);
        pHead = pHead->equipoSig;
        free(anterior);
    }
}

/*Intercambio los campos de los nodos*/
void swap(strc_equipo *a, strc_equipo *b)
{
    char name[MAX_SIZE];

    strcpy(name, a->nombre);
    strcpy(a->nombre, b->nombre);
    strcpy(b->nombre, name);

    int temp = a->cant_victorias;
    a->cant_victorias = b->cant_victorias;
    b->cant_victorias = temp;

    temp = a->cant_derrotas;
    a->cant_derrotas = b->cant_derrotas;
    b->cant_derrotas = temp;

    temp = a->cant_empates;
    a->cant_empates = b->cant_empates;
    b->cant_empates = temp;

    temp = a->cant_goles;
    a->cant_goles = b->cant_goles;
    b->cant_goles = temp;
}

/*Ordeno de menor a mayor segun las victorias*/
void bubbleSortVictorias(strc_equipo *start)
{
    int swapped, i;
    strc_equipo *ptr1;
    strc_equipo *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->equipoSig != lptr)
        {
            if (ptr1->cant_victorias > ptr1->equipoSig->cant_victorias)
            {
                swap(ptr1, ptr1->equipoSig);
                swapped = 1;
            }
            ptr1 = ptr1->equipoSig;
        }
        lptr = ptr1;
    } while (swapped);
}

/*Ordeno de menor a mayor segun las derrotas*/
void bubbleSortDerrotas(strc_equipo *start)
{
    int swapped, i;
    strc_equipo *ptr1;
    strc_equipo *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->equipoSig != lptr)
        {
            if (ptr1->cant_derrotas > ptr1->equipoSig->cant_derrotas)
            {
                swap(ptr1, ptr1->equipoSig);
                swapped = 1;
            }
            ptr1 = ptr1->equipoSig;
        }
        lptr = ptr1;
    } while (swapped);
}

/*Ordeno de menor a mayor segun los goles*/
void bubbleSortGoles(strc_equipo *start)
{
    int swapped, i;
    strc_equipo *ptr1;
    strc_equipo *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->equipoSig != lptr)
        {
            if (ptr1->cant_goles > ptr1->equipoSig->cant_goles)
            {
                swap(ptr1, ptr1->equipoSig);
                swapped = 1;
            }
            ptr1 = ptr1->equipoSig;
        }
        lptr = ptr1;
    } while (swapped);
}

void createList()
{

    char nombre[MAX_SIZE];
    int cant_victorias, cant_derrotas, cant_empates, cant_goles;

    printf("\nIngrese el nombre del equipo: ");
    scanf(" %s", nombre);

    printf("\nIngrese el numero de victorias del equipo: ");
    scanf("%d", &cant_victorias);

    printf("\nIngrese el numero de derrotas del equipo: ");
    scanf("%d", &cant_derrotas);

    printf("\nIngrese el numero de empates del equipo: ");
    scanf("%d", &cant_empates);

    printf("\nIngrese el numero de goles totales del equipo: ");
    scanf("%d", &cant_goles);

    push(nombre, cant_victorias, cant_derrotas, cant_empates, cant_goles);
}

void second()
{
    char respuesta = 'S';
    int opc;
    bubleSort functionSort;

    createList();

    while (respuesta == 'S')
    {
        do
        {
            printf("\nDesea insertar otro S/n\n");
            scanf(" %c", &respuesta);
        } while (!(respuesta == 'S' || respuesta == 'n'));
        if (respuesta == 'S')
            createList();
        else
            break;
    }

    do
    {
        printf("\n\nORDENAR DE MENOR A MAYOR SEGUN: (ingrese num de opc)\n\n");
        printf("1.Victorias\n2.Derrotas\n3.Cantidad de goles\n\n");
        scanf("%d", &opc);
    } while ((opc != VICTORIAS && opc != DERROTAS && opc != CANT_GOLES));

    switch (opc)
    {
    case VICTORIAS:
        printf("\nOrde de menor a mayor por\n");
        functionSort = bubbleSortVictorias;
        break;

    case DERROTAS:
        functionSort = bubbleSortDerrotas;
        break;

    case CANT_GOLES:
        functionSort = bubbleSortGoles;

    default:
        break;
    }
    functionSort(pHead);
    printLista();
}

void main()
{
    char respuesta = 'S';
    second();
    while (respuesta == 'S')
    {
        do
        {
            printf("\nDesea continuar S/n\n");
            scanf(" %c", &respuesta);
        } while (!(respuesta == 'S' || respuesta == 'n'));
        if (respuesta == 'S')
            second();
        else
            break;
    }
}