#include <stdio.h>
#include <string.h>
#include <math.h>

#define DINERO_FINAL    100000
float potencia (float , int, int);
void ejercicio2(void);
/*
¿Cuánto dinero se acumulara después de 30 años si se depositan 100 dólares al comienzo de 
cada año y el tipo de interés compuesto es el 6% anual?
¿Cuánto dinero se debe depositar al comienzo de cada año 
para acumular 100.000 dólares después de 30 años, 
suponiendo también un tipo de interés compuesto del 6% anual?
*/

void ejercicio2(void){

 int dineroDepositado = 100;
 int anios = 30;
 float interes = 6;

 float base = 1 + (interes/100);

 float resultado = dineroDepositado * potencia(base, anios, dineroDepositado);
 printf("\nDespues de 30 años,al depositar 100 USD cada año se obtiene un total : %.2f\n", resultado);

float nuevoDeposito = DINERO_FINAL / (resultado/dineroDepositado);
 printf("\nSe debe depositar una cantidad inicial de %.2f USD para al cabo de\n30 años acumular 100 000 USD\n\n",nuevoDeposito);
 
}

float potencia (float base, int anios, int dineroDepositado){
    int i;
    float resultado;
    for (i=1 ; i<=anios; i++ ){
        resultado += pow (base, i);
    
        printf ("\nEn el año %d la cantidad de dinero acumulado es: %.2f USD\n", i, resultado*dineroDepositado);
    }

    return resultado;
}


int main(){
   ejercicio2();
    return 0;
}