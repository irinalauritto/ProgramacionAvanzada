#include "pixel.h"

Pixel::Pixel()
{
    maximoValor = 255;
}

void Pixel::setMaximoValor(int pMaximoValor)
{
    maximoValor = pMaximoValor;
}

void Pixel::setComponentes(float primer, float segunda, float tercer)
{
    componentes[0] = primer;
    componentes[1] = segunda;
    componentes[2] = tercer;
}

void Pixel::setPrimerComponente(float pPrimerComponente)
{
    componentes[0]=pPrimerComponente;
}

void Pixel::setSegundaComponente(float pSegundaComponente)
{
    componentes[1]=pSegundaComponente;
}

void Pixel::setTercerComponente(float pTercerComponente)
{
    componentes[2]=pTercerComponente;
}

float Pixel::getPrimerComponente()
{
    return componentes[0];
}

float Pixel::getSegundaComponente()
{
    return componentes[1];
}

float Pixel::getTercerComponente()
{
    return componentes[2];
}

bool Pixel::operator == (Pixel pPixel)
{
   return (this->componentes[0] == pPixel.componentes[0] and this->componentes[1] == pPixel.componentes[1] and this->componentes[2] == pPixel.componentes[2]);
}

Pixel Pixel::operator - (Pixel pPixel)
{
    Pixel resta;

    resta.componentes[0] = this->componentes[0] - pPixel.componentes[0];
    resta.componentes[1] = this->componentes[1] - pPixel.componentes[1];
    resta.componentes[2] = this->componentes[2] - pPixel.componentes[2];

    if(resta.componentes[0] > (float)maximoValor)
        resta.componentes[0] = (float)maximoValor;
    if(resta.componentes[1] > (float)maximoValor)
        resta.componentes[1] = (float)maximoValor;
    if(resta.componentes[2] > (float)maximoValor)
        resta.componentes[2] = (float)maximoValor;

    if(resta.componentes[0] < 0.0f)
        resta.componentes[0] = 0.0f;
    if(resta.componentes[1] < 0.0f)
        resta.componentes[1] = 0.0f;
    if(resta.componentes[2] < 0.0f)
        resta.componentes[2] = 0.0f;

    return resta;
}

Pixel Pixel::operator + (Pixel pPixel)
{
    Pixel suma;

    suma.componentes[0] = this->componentes[0] + pPixel.componentes[0];
    suma.componentes[1] = this->componentes[1] + pPixel.componentes[1];
    suma.componentes[2] = this->componentes[2] + pPixel.componentes[2];

    if(suma.componentes[0] > (float)maximoValor)
        suma.componentes[0] = (float)maximoValor;
    if(suma.componentes[1] > (float)maximoValor)
        suma.componentes[1] = (float)maximoValor;
    if(suma.componentes[2] > (float)maximoValor)
        suma.componentes[2] = (float)maximoValor;

    if(suma.componentes[0] < 0.0f)
        suma.componentes[0] = 0.0f;
    if(suma.componentes[1] < 0.0f)
        suma.componentes[1] = 0.0f;
    if(suma.componentes[2] < 0.0f)
        suma.componentes[2] = 0.0f;

    return suma;
}

Pixel Pixel::operator * (Pixel pPixel)
{
    Pixel producto;

    producto.componentes[0] = this->componentes[0] * pPixel.componentes[0];
    producto.componentes[1] = this->componentes[1] * pPixel.componentes[1];
    producto.componentes[2] = this->componentes[2] * pPixel.componentes[2];

    if(producto.componentes[0] > (float)maximoValor)
        producto.componentes[0] = (float)maximoValor;
    if(producto.componentes[1] > (float)maximoValor)
        producto.componentes[1] = (float)maximoValor;
    if(producto.componentes[2] > (float)maximoValor)
        producto.componentes[2] = (float)maximoValor;

    return producto;
}


Pixel Pixel::operator * (float valor)
{
    Pixel producto;

    producto.componentes[0] = this->componentes[0] * valor;
    producto.componentes[1] = this->componentes[1] * valor;
    producto.componentes[2] = this->componentes[2] * valor;

    if(producto.componentes[0] > (float)maximoValor)
        producto.componentes[0] = (float)maximoValor;
    if(producto.componentes[1] > (float)maximoValor)
        producto.componentes[1] = (float)maximoValor;
    if(producto.componentes[2] > (float)maximoValor)
        producto.componentes[2] = (float)maximoValor;

    return producto;
}

Pixel Pixel::operator / (Pixel pPixel)
{
    Pixel cociente;

    try
    {
        if(pPixel.getPrimerComponente() == 0.0 or pPixel.getSegundaComponente() == 0.0 or pPixel.getTercerComponente() == 0.0)
        {
            throw "Error division por cero.";
        }
        cociente.componentes[0] = this->componentes[0] / pPixel.componentes[0];
        cociente.componentes[1] = this->componentes[1] / pPixel.componentes[1];
        cociente.componentes[2] = this->componentes[2] / pPixel.componentes[2];

    }
    catch (string &err)
    {
        return *this;
    }

    return cociente;
}

bool Pixel::Pixel::operator <(Pixel pPixel)
{
    return(componentes[0] < pPixel.getPrimerComponente() and componentes[1] < pPixel.getSegundaComponente() and componentes[2] < pPixel.getTercerComponente());
}

