#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*EL JUEGO DE LAS 21*/

#define CARTAS 52
#define BLACKJACK 21
#define PRIMER_REPARTO 4

#define true 1
#define false 0
/*
typedef struct {
    int valor;
    char* palo;
    carta* siguiente;
}carta;


carta* top = NULL; // final de la lista

void push(int valor){
    carta* temp = (carta*)malloc(sizeof(carta)); // Creo un puntero dinamico a carta
    temp->valor = valor;
    temp->siguiente = top;
    top = temp;
}

void pop (){
    carta* temp;
    if (top == NULL) return; // lista vacia
    temp = top; // apunto con el puntero al ultimo
    top = top->siguiente;
    free(temp);
}

int isEmpty(){
    if(top == NULL) return true;
    else            return false;
}
*/

int mazoComplete(int mazo[])
{
    int i;

    for (i = 0; i < CARTAS; i++)
    {
        if (!mazo[i])
            return true;
    }
    return false;
}

int partida()
{
     int valoresBlackJack[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}; /*Cartas 2 3 4 5 6 7 8 9 10
                                                                J Q K*/
    time_t tiempo;
    int i = 0, index = 0;
    int sumJugador1 = 0, sumJugador2 = 0;
    int mazo[CARTAS] = {0};
    char respuestaJ1, respuestaJ2, respuesta;
    char cont;
    int indexMazo;

    printf("\n\n\tBIENVENIDOS AL BLACKJACK\n\n");

    srand((unsigned)time(&tiempo)); /*semilla para numero aleatorio*/
    /*Creo el mazo de cartas*/

    do
    {
        indexMazo = rand() % CARTAS;
        if (mazo[indexMazo] == 0)
        { // si es cero guardo un valor posible de carta
            mazo[indexMazo] = valoresBlackJack[i];
            i++;
        }
        if (i == 12)
            i = 0;
    } while (mazoComplete(mazo));
    // Hago esto hasta que el array mazo se llene con valores de las cartas
/*
    for (int i = 0; i < CARTAS; i++)
    {
        printf("%d\n", mazo[i]);
    }
*/
    /*Reparto de manera alternada entre los dos jugadores empezando por el primero*/

    for (index = 0; index < 2; index++)
    {
        printf("\nJugador 1 le toco la carta: %d", mazo[2 * index]);     /*Le toca la carta 0 y 2 del mazo*/
        printf("\nJugador 2 le toco la carta: %d", mazo[2 * index + 1]); /*Le toca la carta 1 y 3 del mazo*/
        sumJugador1 += mazo[2 * index];
        sumJugador2 += mazo[2 * index + 1];
    }
    /*Chequeo si alguien tuvo doble As de esa forma combina un 11 y un 1*/
    if (mazo[0] == mazo[2] && sumJugador1 == BLACKJACK)
        sumJugador1 = 12;
    if (mazo[1] == mazo[3] && sumJugador1 == BLACKJACK)
        sumJugador2 = 12;

    /*Chequeo si alguien hizo BlackJack*/
    if (sumJugador1 == BLACKJACK)
    {
        printf("\nFelicitaciones jugador 1, ¡Has ganado!\n");
        return 0;
    }

    if (sumJugador2 == BLACKJACK)
    {
        printf("\nFelicitaciones jugador 2, ¡Has ganado!\n");
        return 0;
    }

    /*Si nadie hizo BLACKJACK, continúo el juego*/
    do
    {
        do
        {
            printf("\nJugador 1, ¿Desea otra carta? S/n\n");
            scanf(" %c", &respuestaJ1);
        } while (!(respuestaJ1 == 'S' || respuestaJ1 == 'n'));

        if (respuestaJ1 == 'S')
        {
            index++; /*Este index lo use para repartirar las cartas y ya quedo con el ultimo valor del for*/
            sumJugador1 += mazo[2 * index];
            printf("\nJugador 1: su proxima carta es: %d y acumula una suma de: %d\n", mazo[2 * index], sumJugador1);

            if (sumJugador1 == BLACKJACK)
            {
                printf("\nFelicitaciones jugador 1, ¡Has ganado!\n");
                return 0;
            }

            if (sumJugador1 > BLACKJACK)
            {
                printf("\nLo siento jugador 1, ¡Has perdido!, felicitaciones jugador 2, ¡Has ganado!\n");
                return 0;
            }
        }
        else if (respuestaJ1 == 'n')
        {
            printf("\nJugador 1 se ha plantado con: %d\n", sumJugador1);
        }
        do
        {
            printf("\nJugador 2, ¿Desea otra carta? S/n\n");
            scanf(" %c", &respuestaJ2);
        } while (!(respuestaJ2 == 'S' || respuestaJ2 == 'n'));
        if (respuestaJ2 == 'S')
        {
            index++;
            sumJugador2 += mazo[2 * index + 1];
            printf("\nJugador 2: su proxima carta es: %d y acumula una suma de: %d\n", mazo[2 * index + 1], sumJugador2);

            if (sumJugador2 == BLACKJACK)
            {
                printf("\nFelicitaciones jugador 2, ¡Has ganado!\n");
                return 0;
            }
            if (sumJugador2 > BLACKJACK)
            {
                printf("\nLo siento jugador 2, ¡Has perdido! felicitaciones jugador 1, ¡Has ganado!\n");
                return 0;
            }
        }
        else if (respuestaJ2 == 'n')
        {
            printf("\nJugador 2 se ha plantado con: %d\n", sumJugador2);
        }

        if (respuestaJ1 == 'n' && respuestaJ2 == 'n') /*Situacion en la que ambos se plantaron antes de superar 
        BLACKJACK*/
        {
            if (sumJugador1 > sumJugador2)
            {
                printf("\nHa ganado el jugador 1 por mayor suma: %d\n", sumJugador1);
                printf("\nHa perdido el jugador 2 por menor suma: %d\n", sumJugador2);
                return 0;
            }

            if (sumJugador1 < sumJugador2)
            {
                printf("\nHa ganado el jugador 2 por mayor suma: %d\n", sumJugador2);
                printf("\nHa perdido el jugador 1 por menor suma: %d\n", sumJugador1);
                return 0;
            }

            if (sumJugador1 == sumJugador2)
            {
                printf("\nHubo empate, ambos jugadores sumaron: %d\n", sumJugador1);
                return 0;
            }
        }

    } while ((sumJugador1 < BLACKJACK && sumJugador2 < BLACKJACK));
    return 0;
}

void main()
{
    char  respuesta;
    partida();
    do
    {
        do
        {
            printf("\nJUGADORES, DESEAN UNA NUEVA PARTIDA? S/n\n");
            scanf(" %c", &respuesta);
        } while (!(respuesta == 'S' || respuesta == 'n'));
        if(respuesta == 'S')     partida();
        else exit(-1);       
    } while (respuesta == 'S');
}
