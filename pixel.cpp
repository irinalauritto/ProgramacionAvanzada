#include "pixel.h"

Pixel::Pixel()
{
    componentes.resize(3);
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
    if(this->componentes[0] == pPixel.componentes[0] and this->componentes[1] == pPixel.componentes[1] and this->componentes[2] == pPixel.componentes[2])
        return 1;
    else
        return 0;
}

Pixel Pixel::operator - (Pixel pPixel)
{
    Pixel resta;
    resta.componentes[0] = this->componentes[0] - pPixel.componentes[0];
    resta.componentes[1] = this->componentes[1] - pPixel.componentes[1];
    resta.componentes[2] = this->componentes[2] - pPixel.componentes[2];

    if(resta.componentes[0] < 0)
        resta.componentes[0] = 0;
    if(resta.componentes[1] < 0)
        resta.componentes[1] = 0;
    if(resta.componentes[2] < 0)
        resta.componentes[2] = 0;

    return resta;
}

Pixel Pixel::operator + (Pixel pPixel)
{
    Pixel suma;

    suma.componentes[0] = this->componentes[0] + pPixel.componentes[0];
    suma.componentes[1] = this->componentes[1] + pPixel.componentes[1];
    suma.componentes[2] = this->componentes[2] + pPixel.componentes[2];

    if(suma.componentes[0] > 1)
        suma.componentes[0] = 1;
    if(suma.componentes[1] > 1)
        suma.componentes[1] = 1;
    if(suma.componentes[2] > 1)
        suma.componentes[2] = 1;

    return suma;
}

Pixel Pixel::operator * (Pixel pPixel)
{
    Pixel producto;

    producto.componentes[0] = this->componentes[0] * pPixel.componentes[0];
    producto.componentes[1] = this->componentes[1] * pPixel.componentes[1];
    producto.componentes[2] = this->componentes[2] * pPixel.componentes[2];


    return producto;
}

Pixel Pixel::operator * (float valor)
{
    Pixel producto;

    producto.componentes[0] = this->componentes[0] * valor;
    producto.componentes[1] = this->componentes[1] * valor;
    producto.componentes[2] = this->componentes[2] * valor;


    return producto;
}

Pixel Pixel::operator / (Pixel pPixel)
{
    Pixel cociente;

    cociente.componentes[0] = this->componentes[0] / pPixel.componentes[0];
    cociente.componentes[1] = this->componentes[1] / pPixel.componentes[1];
    cociente.componentes[2] = this->componentes[2] / pPixel.componentes[2];

    return cociente;
}

void Pixel::operator = (Pixel pPixel)
{
    componentes[0] = pPixel.getPrimerComponente();
    componentes[1] = pPixel.getSegundaComponente();
    componentes[2] = pPixel.getTercerComponente();
}

bool Pixel::operator < (Pixel pPixel)
{
    if(componentes[0] < pPixel.getPrimerComponente() and componentes[1] < pPixel.getSegundaComponente() and componentes[2] < pPixel.getTercerComponente())
    {
        return true;
    }
    else
    {
        return false;
    }
}

