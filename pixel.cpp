#include "pixel.h"


Pixel::Pixel()
{
    componentes.resize(3);
}
void Pixel::setComponentes(vector<float> &newComponentes)
{
    componentes = newComponentes;
}

void Pixel::setR(float pR)
{
    componentes[0]=pR;
}

void Pixel::setG(float pG)
{
    componentes[1]=pG;
}

void Pixel::setB(float pB)
{
    componentes[2]=pB;
}

float Pixel::getR()
{
    return componentes[0];
}

float Pixel::getG()
{
    return componentes[1];
}

float Pixel::getB()
{
    return componentes[2];
}

bool Pixel::operator==(Pixel pPixel)
{
    if(this->componentes[0]==pPixel.componentes[0] and this->componentes[1]==pPixel.componentes[1] and this->componentes[2]==pPixel.componentes[2])
        return 1;
    else
        return 0;
}

Pixel Pixel::operator-(Pixel pPixel)
{
    Pixel resta;
    resta.componentes[0] = this->componentes[0] - pPixel.componentes[0];
    resta.componentes[1] = this->componentes[1] - pPixel.componentes[1];
    resta.componentes[2] = this->componentes[2] - pPixel.componentes[2];

    if(resta.componentes[0]<0)
        resta.componentes[0]=0;
    if(resta.componentes[1]<0)
        resta.componentes[1]=0;
    if(resta.componentes[2]<0)
        resta.componentes[2]=0;

    return resta;
    //Como debo resolver si me da negativo?
}

Pixel Pixel::operator+(Pixel pPixel)
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

Pixel Pixel::operator*(Pixel pPixel)
{
    Pixel producto;

    producto.componentes[0] = this->componentes[0] * pPixel.componentes[0];
    producto.componentes[1] = this->componentes[1] * pPixel.componentes[1];
    producto.componentes[2] = this->componentes[2] * pPixel.componentes[2];

    if(producto.componentes[0] > 1)
        producto.componentes[0] = 1;
    if(producto.componentes[1] > 1)
        producto.componentes[1] = 1;
    if(producto.componentes[2] > 1)
        producto.componentes[2] = 1;

    return producto;
}

