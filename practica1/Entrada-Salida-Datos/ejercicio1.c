/*
 ============================================================================
 Name        : Practica-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 *
 * Las consignas estan un poco confusas, probablemente por temas
 * de traduccion
 *
 * */


#include <stdio.h>


int i = 102;
int j = -56;
long ix = -158931574;
unsigned u = 35460;
float x = 12.687;
double dx = 0.000000025;
char c = 'C';

void itemA(void);
void itemB(void);
void itemC(void);
void itemD(void);
void itemE(void);
void itemF(void);
void itemG(void);
void itemH(void);
void itemI(void);
void itemJ(void);

void ejercicio2Item1(void);
void ejercicio2Item2(void);
void ejercicio2Item3(void);

int main(void) {
	printf("\nActividad A:\n\n");
	itemA();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad B:\n\n");
	itemB();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad C:\n\n");
	itemC();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad D:\n\n");
	itemD();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad E:\n\n");
	itemE();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad F:\n\n");
	itemF();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad G:\n\n");
	itemG();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad H:\n");
	itemH();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad I:\n\n");
	itemI();
	printf("\n-------------------------------------------------\n\n");
	printf("\n\nActividad J:\n\n");
	itemJ();

	return 0;
}
/*
 * Escribir los valores de i, j, x y dx suponiendo que cada
 * cantidad entera tiene una longitud de campo mínima de cuatro caracteres y
 * cada cantidad en coma flotante se presenta en notación exponencial con un total de al menos 14 caracteres y no más de 8 cifras decimales.*/

void itemA (void) {
	printf("Valor de i: %04d\n",i);
	printf ("Valor de j:%04d\n",j);
	printf ("Valor de x:%14.8e\n",x);
	printf ("Valor de dx:%14.8e\n",dx);
}

void itemB (void) {
	printf("Valor de i: %04d\n",i);
	printf ("Valor de j:%04d\n",j);
	printf ("Valor de x:%14.8e\n",x);
	printf ("Valor de dx:%14.8e\n",dx);
}

/*
 * Escribir los valores de i, ix, j, x y u suponiendo que cada
 * cantidad entera tendrá una longitud de campo mínima de cinco caracteres,
 * el entero largo tendrá una longitud de campo mínima de 12 caracteres y
 * la cantidad en coma flotante tiene al menos 10 caracteres con un máximo de cinco cifras decimales. No incluir el exponente.
 * */

void itemC (void) {
	printf("Valor de i: %05d\n",i);
	printf ("Valor de ix:%012ld\n",ix);
	printf ("Valor de x:%010.5f\n",x);
	printf ("Valor de j:%05i\n",j);
	printf ("Valor de u:%05u\n",u);
}

/*Repetir C, visualizando las tres primeras cantidades en una línea,
 * seguidas de una línea en blanco y las otras dos cantidades en la línea siguiente*/

void itemD (void) {
	printf("Valor de i: %05d",i);
	printf ("\tValor de ix:%012ld",ix);
	printf ("\tValor de x:%010.5f",x);
	printf("\n\n");
	printf ("Valor de j:%05i",j);
	printf (" Valor de u:%+05u",u);
}

/*Escribir los valores de i, u y c,
 * con una longitud de campo mínima de seis caracteres para cada cantidad entera.
 * Separar con tres espacios en blanco cada cantidad.*/

void itemE (void) {
	printf("Valor de i: %06d",i);
	printf ("\t\t\tValor de u:%06u",u);
	printf ("\t\t\tValor de c:%c",c);
}

/*
 * Escribir los valores de j, u y x.
 * Visualizar las tres cantidades enteras con una longitud de campo mínima de cinco caracteres.
 * Presentar la cantidad en coma flotante utilizando la conversión tipo f,
 * con una longitud mínima de 11 caracteres y un máximo de cuatro cifras decimales.
 * *
 */

void itemF(void) {
	printf ("Valor de x:%011.4f",x);
	printf ("\tValor de j:%05i",j);
	printf ("\tValor de u:%05u",u);
}

/*Repetir F, con cada dato ajustado a la izquierda dentro de su campo.*/

void itemG(void) {
	printf ("Valor de x:%-11.4f",x);
	printf ("\tValor de j:%-5d",j);
	printf ("\tValor de u:%-5u",u);
}

/*Repetir F, apareciendo un signo (tanto + como -) delante de cada dato con signo.*/

void itemH(void) {
	printf ("Valor de x:%+011.4f",x);
	printf ("\tValor de j:%+05d",j);
	printf ("\tValor de u:%5u",u);
}
 /*Repetir F, rellenando el campo de cada entidad entera con ceros.*/

void itemI(void) {
	printf ("Valor de x:%011.4f",x);
	printf ("\tValor de j:%05d",j);
	printf ("\tValor de u:%05u",u);
}

/*Repetir F, apareciendo el valor de x con un punto decimal.*/

void itemJ(void) {
	printf ("Valor de x:%011.1f",x);
	printf ("\tValor de j:%05i",j);
	printf ("\tValor de u:%05u",u);
}

