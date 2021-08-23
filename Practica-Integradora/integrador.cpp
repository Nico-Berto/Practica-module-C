#include "integrador.hpp"
#include <iostream>
#include <string>

int main()
{
    float temp, hum, press;
    int cont = 0;
    char resp;
    list<sensor> weatherDataCenter;
    list<sensor>::iterator pos;
    do
    {
        cont++;

        std::cout << "Ingrese (T[C] H[%] P[KPa]): ";
        std::cin >> temp >> hum >> press;
        /*Creo los objetos*/
        temperatura Temperatura(temp);
        humedad Humedad(hum);
        presion Presion(press);
        Temperatura.setId(cont);
        /*Creo un objeto sensor con los objetos anteriores para guardar en una lista*/
        sensor NuevaVariable(Temperatura, Humedad, Presion);

        /*Lo guardo en la lista*/
        weatherDataCenter.push_front(NuevaVariable);

        /*Muestro el ultimo elemento de la lista*/
        sensor ultDato = weatherDataCenter.front();
        cout << "Numero de muestra:" << ultDato.tempValue.getId() << endl;
        cout << ultDato.tempValue.getParameter()<<" °C de temperatura y ";
        cout << ultDato.humValue.getParameter()<<"% de humedad" << endl;
        cout << "Avg/Max/Min temperature: ";
        cout << fixed << setprecision(1) << ultDato.avgTemp(weatherDataCenter) << "°C ";
        cout << fixed << setprecision(1) << ultDato.tempMax(weatherDataCenter) << "°C ";
        cout << fixed << setprecision(1) << ultDato.tempMin(weatherDataCenter) << "°C" << endl;
        ultDato.pronostico(weatherDataCenter);
        
        cout << "Nuevo dato? S/n" << endl;
        cin >> resp;

    } while (resp != 'n');
}
