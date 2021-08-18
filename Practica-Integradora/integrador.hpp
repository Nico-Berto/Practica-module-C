#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <bits/stdc++.h>

#define HUMEDAD_PRECIPITACIONES 50
#define TEMP_PRECIPITACIONES    27
#define TEMP_NEVADA             5
using namespace ::std;

/*Clase padre de temperatura, humedad y presion*/
class datos
{
protected:
    /*Las funciones hijas heredan el id, que representa el numero de medicion*/
    int id;

protected:
    void mostrar()
    {
        cout << "Los datos son :" << endl;
    }
    /*Funcion virtual que va a devolver distintos parametros de acuerdo a las clases hijas*/
    virtual void setParameter(float) {}

public:
    datos(int);
    datos();
    void setId(int id);
    int getId()
    {
        return id;
    }
};

class temperatura : public datos
{
private:
    float temp;

public:
    temperatura(float);
    temperatura();
    float getParameter()
    {
        return temp;
    }
    void setParameter(float temp)
    {
        this->temp = temp;
    }
};

class humedad : public datos
{
private:
    float hum;

public:
    humedad(float);
    humedad();
    float getParameter()
    {
        return this->hum;
    }
    void setParameter(float hum)
    {
        this->hum = hum;
    }
};

class presion : public datos
{
private:
    float pres;

public:
    presion(float);
    presion();
    float getParameter()
    {
        return this->pres;
    }
    void setParameter(float pres)
    {
        this->pres = pres;
    }
};

/*Clase que va a contener como atributo las clases magnitudes sensadas
permitiendo facilidad al meter en una lista*/
class sensor
{
public:
    temperatura tempValue;
    humedad humValue;
    presion presValue;

public:
    sensor(temperatura, humedad, presion);
    /*metodo para calcular la temperatura promedio de la lista*/
    float avgTemp(list<sensor> &datos)
    {
        list<sensor>::iterator pos;
        float avgTemperatura = 0;
        int cont = 0;
        pos = datos.begin();
        while (pos != datos.end())
        {
            avgTemperatura += pos->tempValue.getParameter();
            pos++;
            cont++;
        }
        return (avgTemperatura / cont);
    }
    /*metodo para encontrar la temperatura maxima*/
    float tempMax(list<sensor> &datos)
    {
        list<sensor>::iterator pos;
        pos = datos.begin();
        float tempMaxima = pos->tempValue.getParameter();
        int cont = 0;
        while (pos != datos.end())
        {
            if(pos->tempValue.getParameter()>tempMaxima)    tempMaxima = pos->tempValue.getParameter();
            pos++;
        }
        return tempMaxima;
    }
    /*metodo para encontrar la temperatura minima*/
    float tempMin(list<sensor> &datos)
    {
        list<sensor>::iterator pos;
        pos = datos.begin();
        float tempMinima = pos->tempValue.getParameter();
        int cont = 0;
        while (pos != datos.end())
        {
            if(pos->tempValue.getParameter()<tempMinima)    tempMinima = pos->tempValue.getParameter();
            pos++;
        }
        return tempMinima;
    }

    void pronostico(list<sensor> &datos){
        list<sensor>::iterator pos;
        pos = datos.begin();
        if(datos.front().humValue.getParameter() > HUMEDAD_PRECIPITACIONES && datos.front().tempValue.getParameter() > TEMP_PRECIPITACIONES){
            cout <<"Se esperan fuertes lluvias por la tarde"<<endl;
        }
        else if(datos.front().humValue.getParameter() < HUMEDAD_PRECIPITACIONES && datos.front().tempValue.getParameter() < TEMP_NEVADA){
            cout <<"Se esperan nevadas por la tarde"<<endl;
        }

        else{
            cout <<"Se espera buen clima todo el dia"<<endl;
        }
        cout<<endl;
    }
};

void datos::setId(int id)
{
    this->id = id;
}

/*Constructores por defecto*/
datos::datos()
{
    this->id = 0;
}

temperatura::temperatura()
{
    this->temp = 0;
}

humedad::humedad()
{
    this->hum = 0;
};

presion::presion()
{
    this->pres = 0;
};

/*Constructores alternativos*/

datos::datos(int id)
{
    this->id = id;
}

sensor::sensor(temperatura tempValue, humedad humValue, presion presValue)
{
    this->tempValue = tempValue;
    this->humValue = humValue;
    this->presValue = presValue;
}

temperatura::temperatura(float temp)
{
    this->temp = temp;
}

humedad::humedad(float hum)
{
    this->hum = hum;
};

presion::presion(float pres)
{
    this->pres = pres;
};
